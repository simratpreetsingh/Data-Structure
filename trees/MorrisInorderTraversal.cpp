#include <iostream>
using namespace std;

void Inorder(Node * root) {
	Node* current = root;
	while (current != NULL) {
		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		}
		else {
			Node * predecessor = current->left;
			while (predecessor->right != current && predecessor->right != NULL) {
				predecessor = predecessor->right;
			}
			if (predecessor->right == NULL) {
				predecessor->right = current;
				current = current->left;
			}
			else {
				predecessor->right = NULL;
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

