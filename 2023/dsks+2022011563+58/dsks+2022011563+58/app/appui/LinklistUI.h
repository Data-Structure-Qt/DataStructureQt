#pragma once
#include "CNodeEditorScene.h" 
#include "CQuickHelpUI.h" 
#include <QWidget> 
#include "LinklistNode.h" 
class CEditorScene;
namespace Ui {
	class LinklistUI;
}

template <typename K, typename V>
class HashNode {
public:
	K key;
	V value;
	HashNode* next;

	HashNode(const K& key, const V& value) : key(key), value(value), next(nullptr) {}
};


template <typename K, typename V>
class HashTable {
public:
	std::vector<HashNode<K, V>*> table;
	std::vector<int> auxInfo;

	int capacity;
	int size;
	float loadFactor;

	void resize() {
		int oldCapacity = capacity;
		capacity *= 2;
		std::vector<HashNode<K, V>*> newTable(capacity);
		for (int i = 0; i < oldCapacity; i++) {
			HashNode<K, V>* head = table[i];
			while (head != nullptr) {
				K oldKey = head->key;
				V oldValue = head->value;
				HashNode<K, V>* oldNext = head->next;
				int hashIndex = hashFunction(oldKey);
				head->next = newTable[hashIndex];
				newTable[hashIndex] = head;
				head = oldNext;
			}
		}
		table = newTable;
	}

public:
	HashTable(int cap = 13, float loadFactor = 0.8) : capacity(cap), size(0), loadFactor(loadFactor) {
		table.resize(capacity);
		auxInfo.resize(capacity);
		for (int i = 0; i < capacity; i++)
			table[i] = nullptr;
	}

	~HashTable() {
		for (int i = 0; i < capacity; i++) {
			HashNode<K, V>* entry = table[i];
			while (entry != nullptr) {
				HashNode<K, V>* prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
	}

	int hashFunction(K key) {
		return key % capacity; // Simple mod-based hash function
	}

	void insertNode(K key, V value) {
		/*	if ((1.0 * size) / capacity >= loadFactor) {
				resize();
			}*/
		HashNode<K, V>* newNode = new HashNode<K, V>(key, value);
		int hashIndex = hashFunction(key);
		newNode->next = table[hashIndex];
		table[hashIndex] = newNode;
		size++;
		auxInfo[hashIndex]++;
	}

	V deleteNode(K key) {
		int hashIndex = hashFunction(key);
		HashNode<K, V>* entry = table[hashIndex];
		HashNode<K, V>* prev = nullptr;
		while (entry != nullptr && entry->key != key) {
			prev = entry;
			entry = entry->next;
		}
		if (entry == nullptr) return V(); // Key not found, return default-constructed value
		else {
			if (prev == nullptr) {
				table[hashIndex] = entry->next;
			}
			else {
				prev->next = entry->next;
			}
			V value = entry->value;
			delete entry;
			size--;
			return value;
		}
	}

	V get(K key) {
		int hashIndex = hashFunction(key);
		HashNode<K, V>* entry = table[hashIndex];
		while (entry != nullptr) {
			if (entry->key == key) return entry->value;
			entry = entry->next;
		}
		return V(); // Key not found, return default-constructed value
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}
};



typedef struct Animation { //动画片段
	int x; // 位置
	int data; // 数据
	int flag;
	int codeid;
};
class LinklistUI : public QWidget
{
	Q_OBJECT
public:
	LinklistUI(QWidget* parent = 0);//构造函数
	~LinklistUI();//析构函数
	void setScene(CNodeEditorScene* scene); //传递绘制窗口指针
	void setCQuickHelpUI(CQuickHelpUI* scene); //传递代码追踪窗口指针
	void goToBeginButton();
	void stepBackButton();
	void playButton();
	void suspendButton();
	void stepForwardButton();
	void goToEndButton();
signals:
	void SearchBtn_SendText();
private slots:
	void on_create_btn_clicked(); //创建按钮槽函数
	void on_clean_btn_clicked(); //清空按钮槽函数
	void on_headinsert_btn_clicked(); //头部插入按钮槽函数
	void on_tailinsert_btn_clicked(); //尾部插入按钮槽函数
	void on_locationinsert_btn_clicked(); //插入按钮槽函数
	void on_headdelete_btn_clicked(); //头部删除按钮槽函数
	void on_taildelete_btn_clicked(); //尾部删除按钮槽函数
	void on_locationdelete_btn_clicked(); //删除按钮槽函数
	void on_search_btn_clicked(); //搜索按钮槽函数
	//程序暂停时间 time 停留时间 毫秒
	void sleepTime(int time);
	void animationRecord(int totaltime, int frame, int x, int data);
	void animationSearchRecord(int totaltime, int frame, int x, int data, int flag, int codeid);
	void animationClean();
	void animationPrint(int totaltime, int frametime);
	void animationDraw(int totaltime, int frametime);
	void animationDrawSearch(int totaltime, int frametime, int x);
protected:
	void onSceneAttached(CEditorScene* scene);
	void onSceneDetached(CEditorScene* scene);
private:
	Ui::LinklistUI* ui; //控制面板窗口指针
	CNodeEditorScene* m_scene; //绘制区域窗口指针
	CNode* m_nodeFactory; //节点工厂类指针
	CEdge* m_edgeFactory;
	CQuickHelpUI* m_quickHelp;
	QList<LinklistNode> QLinkList; //链表节点容器
	Animation animation[200][200]; //动画 /第几帧/每帧具体步骤
	Animation animationSearch[200][200]; //动画 /第几帧/每帧具体步骤
	HashTable<int, int> mytable;
	int frametime[200];
	int insertIdCode[200];
	int framesearchtime; // 搜索结点个数
	int onlytotaltime = 0; // 结点个数
	int timestamp = 0; //进度控制时间戳
	int endplaybuttonflag = 0; //停止播放标志位
	int createflag = 0;
	int deleteflag = 0;
	int searchflag = 0;
};
