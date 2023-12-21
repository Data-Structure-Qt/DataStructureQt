#ifndef __bplustree_h__
#define __bplustree_h__

/*
 * 文件名:bplustree
 * 作用:实现bplustree功能,同时提供遍历功能
 * 说明:如果存在相同的key,则新插入的key会保存到相同的key最后
 */

#include <vector>
#include <algorithm>
#include <cassert>

template <typename KeyType, typename LeafType>
struct bnode
{
	// 用来区分表示中间节点还是叶节点
	bool leaf = true;
	// 父节点
	bnode<KeyType, LeafType>* parent = nullptr;
	// 如果是叶子节点,最后一个节点指向下一个bNode(LeafNode),其他的指向LeafType对象,
	// 如果不为叶子节点,全部指向bNode对象
	std::vector<void*> children;
	// 表示Key的类型

	std::vector<KeyType> keys;

	// 用来获取叶节点值
	const LeafType& getValue(size_t idx) const {
		return *reinterpret_cast<LeafType*>(children[idx]);
	}

	void appendChild(bnode<KeyType, LeafType>* childNode)
	{
		children.push_back(childNode);
		childNode->parent = this;
	}

	void appendChild(void* childNode)
	{
		appendChild(reinterpret_cast<bnode<KeyType, LeafType>*>(childNode));
	}

	void insertChild(std::vector<void*>::const_iterator it, bnode<KeyType, LeafType>* childNode)
	{
		children.insert(it, childNode);
		childNode->parent = this;
	}

	void insertChild(std::vector<void*>::const_iterator it, void* childNode)
	{
		insertChild(it, reinterpret_cast<bnode<KeyType, LeafType>*>(childNode));
	}
};

// 用来设置拆分的策略
template <size_t N>
struct splitpolicy
{
	// get the leaf node split position
	size_t leafSplitPos() const
	{
		return N / 2;
	}

	// get the middle node split position
	size_t middleSplitPos() const
	{
		return N / 2 + 1;
	}
};

// N表示一个数节点,最多可以拥有的元素数
template <typename KeyType, typename LeafType, size_t N>
class bplustree
{
public:
	bplustree()
		: m_root(new bnode<KeyType, LeafType>)
	{
		m_root->children.push_back(nullptr);
	}

	// 查找一个节点
	std::pair<bnode<KeyType, LeafType>*, size_t> find(KeyType keyValue) const
	{
		auto node = &m_root;
		while (!node->leaf)
		{
			// 获取node->keys中大于等于keyValue的最小值序号
			auto it = std::lower_bound(node->keys.cbegin(), node->keys.cend(), keyValue);
			if (it == node->keys.cend()) {
				if (node->keys.empty()) {
					assert(false && "node->keys.empty() is true while it is an internal node");
					return std::make_pair(nullptr, 0);
				}
				else {
					node = reinterpret_cast<bnode<KeyType, LeafType>*>(node->children.back());
				}
			}
			else {
				node = node->children[it - node->keys.cbegin() + 1];
			}
		}
		// 查看叶节点中是否存在查找的值
		auto it = std::lower_bound(node->keys.cbegin(), node->keys.cend(), keyValue);
		if (it == node->keys.cend()) {
			return std::make_pair(nullptr, 0);
		}
		return std::make_pair(node, it - node->keys.cbegin());
	}

	// 插入操作
	void insert(KeyType keyValue, LeafType* newLeaf)
	{
		auto node = findPlace(keyValue);
		if (node == nullptr) {
			assert("findPlace couldn't find a leaf node");
			return;
		}

		if (node->keys.size() < N - 1) {
			insert_in_leaf(node, keyValue, newLeaf);
		}
		else { // node已经有了N-1个节点,需要节点拆分
			insert_in_leaf(node, keyValue, newLeaf);
			auto newNode = new bnode<KeyType, LeafType>;
			// 之前节点上留下的元素个数
			auto leftSize = m_splitPolicy.leafSplitPos();
			// 将node中的一半节点拷贝到新节点
			for (auto idx = leftSize; idx != node->keys.size(); ++idx)
			{
				newNode->keys.push_back(node->keys[idx]);
				newNode->children.push_back(node->children[idx]);
			}
			// 修改新节点指向下一个节点
			newNode->children.push_back(node->children.back());
			node->keys.resize(leftSize);
			// 修改当前节点指向新建节点
			node->children.resize(leftSize + 1);
			node->children[leftSize] = newNode;
			insert_in_parent(node, newNode->keys.front(), newNode);
		}

	}

	// 这个方法,用来提供遍历整个B+树
	bnode<KeyType, LeafType>* getRoot() const
	{
		return m_root;
	}

private:
	// 查找适合插入的叶节点
	bnode<KeyType, LeafType>* findPlace(KeyType keyValue)
	{
		bnode<KeyType, LeafType>* node = m_root;
		while (!node->leaf)
		{
			if (node->keys.empty()) {
				assert(false && "node->keys.empty() is true while it is an internal node");
				return nullptr;
			}
			// 获取node->keys中大于keyValue的最小值序号
			auto it = std::upper_bound(node->keys.begin(), node->keys.end(), keyValue);
			if (it == node->keys.cend()) {
				node = reinterpret_cast<bnode<KeyType, LeafType>*>(node->children.back());
			}
			else {
				node = reinterpret_cast<bnode<KeyType, LeafType>*>(node->children[it - node->keys.cbegin()]);
			}
		}
		return node;
	}

	// 在叶节点中插入
	void insert_in_leaf(bnode<KeyType, LeafType>* node, KeyType keyValue, LeafType* leafValue)
	{
		auto it = upper_bound(node->keys.cbegin(), node->keys.cend(), keyValue);
		node->children.insert(it - node->keys.cbegin() + node->children.cbegin(), leafValue);
		node->keys.insert(it, keyValue);
	}

	// 将节点插入到父节点中
	void insert_in_parent(bnode<KeyType, LeafType>* node, KeyType keyValue, bnode<KeyType, LeafType>* newNode)
	{

		auto p = node->parent;
		// 如果node原来是根节点
		if (p == nullptr) {
			m_root = new bnode<KeyType, LeafType>;
			m_root->leaf = false;
			m_root->keys.push_back(keyValue);
			m_root->appendChild(node);
			m_root->appendChild(newNode);
			return;
		}
		// 将新节点插入到相同值的最后
		auto it = upper_bound(p->keys.cbegin(), p->keys.cend(), keyValue);
		// newNode比node大,意味着,newNode不会被放在第一个节点
		p->insertChild(it - p->keys.cbegin() + p->children.cbegin() + 1, newNode);
		p->keys.insert(it, keyValue);

		// 拆分节点
		if (p->children.size() > N) {
			auto splitNode = new bnode<KeyType, LeafType>;
			splitNode->leaf = false;
			auto splitIdx = m_splitPolicy.middleSplitPos();
			for (auto idx = splitIdx; idx != p->children.size(); ++idx) {
				splitNode->appendChild(p->children[idx]);
			}
			for (auto idx = splitIdx; idx != p->keys.size(); ++idx) {
				splitNode->keys.push_back(p->keys[idx]);
			}
			auto splitValue = p->keys[splitIdx - 1];
			p->children.resize(splitIdx);
			p->keys.resize(splitIdx - 1);
			insert_in_parent(p, splitValue, splitNode);
		}
	}

private:
	bnode<KeyType, LeafType>* m_root;
	splitpolicy<N> m_splitPolicy;
};

#endif  // __bplustree_h__
