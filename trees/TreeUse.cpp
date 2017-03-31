#include <iostream>
#include "TreeNode.h"
#include "Queue.h"
using namespace std;

int numNodes(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int count = 1;
	for (int i = 0; i < root->numChildren(); i++) {
		count = count + numNodes(root->getChild(i));
	}
	return count;
}

int height(TreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	int maxChildHeight = 0;
	for (int i = 0; i < root->numChildren(); i++) {
		int thisChildHeight = height(root->getChild(i));
		if (thisChildHeight > maxChildHeight) {
			maxChildHeight = thisChildHeight;
		}
	}
	return 1 + maxChildHeight;
}

TreeNode<int>* takeInputLevelWise() {
	Queue<TreeNode<int>*> q;
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	q.enqueue(root);
	while (!q.isEmpty()) {
		TreeNode<int>* frontNode = q.dequeue();
		cout << "enter num children of " << frontNode->data << endl;
		int numChildren;
		cin >> numChildren;
		for (int i = 0; i < numChildren; i++) {
			cout << "Enter " << i << "th child of " << frontNode->data << endl;
			int childData;
			cin >> childData;
			TreeNode<int>* childNode = new TreeNode<int>(childData);
			q.enqueue(childNode);
			frontNode->addChild(childNode);
		}
	}
	return root;
}

TreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);
	cout << "Enter num children for " << root->data << endl;
	int numChildren;
	cin >> numChildren;
	for (int i = 0; i < numChildren; i++) {
		TreeNode<int>* nextChild = takeInput();
		root->addChild(nextChild);
	}
	return root;
}

void print(TreeNode<int>* root) {
	cout << root->data << ":";
	for (int i = 0; i < root->numChildren(); i++) {
		cout << root->getChild(i)->data << ",";
	}
	cout << endl;
	for (int i = 0; i < root->numChildren(); i++) {
		print(root->getChild(i));
	}
}

int main() {
	//TreeNode<int>* root = takeInput();
	TreeNode<int>* root = takeInputLevelWise();
	cout<<numNodes(root)<<endl;
	print(root);
	delete root;
}

