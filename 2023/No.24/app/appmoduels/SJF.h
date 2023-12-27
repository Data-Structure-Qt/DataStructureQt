#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int a) :val(a), left(NULL), right(NULL) {}
};

void SearchK(TreeNode* root,int k,int &result,int &cnt) {
	if (root == NULL) {
		return;
	}
	SearchK(root->left, k, result, cnt);
	cnt++;
	if (cnt == k) {
		result = root->val;
	}
	SearchK(root->right, k, result, cnt);
}


void test() {
	TreeNode* r1 = new TreeNode(1);
	TreeNode* r2 = new TreeNode(2);
	TreeNode* r3 = new TreeNode(3);
	TreeNode* r4 = new TreeNode(4);
	TreeNode* r5 = new TreeNode(5);
	TreeNode* r6 = new TreeNode(6);
	TreeNode* r7 = new TreeNode(7);
	r1->left = r2;
	r1->right = r3;
	r2->left = r4;
	r2->right = r5;
	r3->left = r6;
	r3->right = r7;
	int result = 0;
	int cnt = 0;
	SearchK(r1, 3, result, cnt);
	cout << result << endl;
}

int main() {
	test();
	return 0;
}