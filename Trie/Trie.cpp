#include <iostream>
using namespace std;


class TrieNode {
public:
	TrieNode * child[256];
	bool isEndOfWord;
	TrieNode() {
		for (int i = 0; i < 256; i++) {
			child[i] = NULL;
		}
		isEndOfWord = false;
	}
};

bool searchKey(TrieNode * root, string key) {
	TrieNode * curr = root;
	for (int i = 0; i < key.length(); i++) {
		if (curr->child[key[i]]==NULL) {
			curr = curr->child[key[i]];
		}
	}
	return curr->isEndOfWord;
}

void addNode(TrieNode * root,string key) {
	TrieNode * curr = root;
	for (int i = 0; i < key.length(); i++) {
		if (curr->child[key[i]] == NULL) {
			curr = new TrieNode();
			curr = curr->child[key[i]];
		}
	}
	curr->isEndOfWord = true;
}

void deleteTrie(Node * root, string key) {

}



int main() {
	// your code goes here
	return 0;
}
