#include "BinaryTreeNode.h"

class BinarySearchTree {
	BinaryTreeNode<int>* root;
	int size;

	static BinaryTreeNode<int>* addElement(
			BinaryTreeNode<int>* root,int element) {
		if (root == NULL) {
			BinaryTreeNode<int>* output =
				new BinaryTreeNode<int>(element);
			return output;
		}

		if (element < root->data) {
			root->left = addElement(root->left, element);
		} else {
			root->right = addElement(root->right, element);
		}
		return root;
	}
	public:
		BinarySearchTree() {
			root = NULL;
			size = 0;
		}

		void addElement(int element) {
			root = addElement(root, element);
			size++;
		}

		/*
		void addElement(int element) {
			if (root == NULL) {
				root = new BinaryTreeNode<int>(element);
				size++;
				return;
			}

			BinaryTreeNode<int>* parent = root;
			bool done = false;
			while (!done) {
				if (parent->data == element) {
					return;
				} else if (parent->data < element) {
					if (parent->right == NULL) {
						BinaryTreeNode<int>* node =
							new BinaryTreeNode<int>(element);
						parent->right = node;
						size++;
						done = true;
					} else {
						parent = parent->right;
					}
				} else {
					if (parent->left == NULL) {
						BinaryTreeNode<int>* node =
							new BinaryTreeNode<int>(element);
						parent->left = node;
						size++;
						done = true;
					} else {
						parent = parent->left;
					}
				}
			}
		}*/

};
