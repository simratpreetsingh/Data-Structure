#include <iostream>
using namespace std;

void Preorder(Node * root) {
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
                cout << current->data << " ";
				current = current->left;
			}
			else {
				predecessor->right = NULL;
				current = current->right;
			}
		}
	}
}
