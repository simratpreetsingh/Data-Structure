#include <iostream>
using namespace std;


class TrieNode {
public:
	TrieNode *child[26];
	bool isEndOfWord;
	TrieNode(){
		for (int i = 0; i < 26; i++) {
			child[i] = NULL;
		}
		isEndOfWord = false;
	}
};

void addNode(TrieNode * root,string s) {
	TrieNode* curr = root;
	for (int i = 0; i < s.length(); i++) {
		int index = s[i] - 'a';
		if (!curr->child[index]) {
			curr->child[index] = new TrieNode();
		}
		curr = curr->child[index];
	}
	curr->isEndOfWord = true;
}

bool search(TrieNode * root, string s) {
	TrieNode * curr = root;
	for (int i = 0; i < s.length(); i++) {
		int index = s[i] - 'a';
		if (!curr->child[index]) {
			return false;
		}
		curr = curr->child[index];
	}
	return curr->isEndOfWord;
}

void printWord(char * str, int n) {
	for (int i = 0; i < n; i++) {
		cout << str[i];
	}
	cout << endl;
}

void print(TrieNode * root,char str[],int level) {
	if (root == NULL) {
		return;
	}
	if (root->isEndOfWord) {
		printWord(str, level);
	}
	for (int i = 0; i < 26; i++) {
		if (root->child[i]) {
			str[level] = (char)(i + 'a');
			print(root->child[i], str, level + 1);
		}
	}
}

int main() {
	TrieNode * root = new TrieNode();
	addNode(root,"b");
	addNode(root, "ab");
	addNode(root, "bca");
	int level = 0;
	char str[20];
	print(root, str, level);
}
