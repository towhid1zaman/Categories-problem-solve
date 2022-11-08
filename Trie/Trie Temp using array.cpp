#include<iostream>
#include<string>
using namespace std;

inline int getIndex(char a) {
	return a - 'a';
}

struct TrieNode {
	int isLeaf; // every leaf count refers to a valid word
	TrieNode* child[26];
};
TrieNode *root;
TrieNode arrayNode[10001];
int arrayIt;

TrieNode *getNewTrieNode() {
	TrieNode *newNode = &arrayNode[arrayIt++];
	newNode->isLeaf = 0;
	for (register int i = 0; i < 26; i++) {
		newNode->child[i] = NULL;
	}
	return newNode;
}

void insertTrieWord(char str[]) {
	TrieNode *cur = root;
	while (*str != '\0') {
		int index = getIndex(*str);
		if (cur->child[index] == NULL) {
			cur->child[index] = getNewTrieNode();
		}
		cur = cur->child[index];
		str++;
	}
	cur->isLeaf++;
}

bool searchTrieWord(char *str) {
	/*
	*return word present or not, for word count return as int
	*/
	TrieNode *cur = root;
	while (*str != '\0') {
		int index = getIndex(*str);
		if (cur->child[index] == NULL)return false;
		cur = cur->child[index];
		*str++;
	}
	return cur->isLeaf > 0;
}

void removeTrieWord(char str[]) {
	if (!searchTrieWord(str)) {
		return;
	}
	TrieNode *cur = root;
	while (*str != '\0') {
		int index = getIndex(*str);
		if (cur->child[index] == NULL) return;
		//else move to next child
		cur = cur->child[index];
		*str++;
	}
	--cur->isLeaf; // decrease word count by one.
}
void initTrie() {
	arrayIt = 0;
	root = getNewTrieNode();
}

int main() {
	initTrie();
	insertTrieWord("abc");
	insertTrieWord("trew");
	insertTrieWord("bgre");
	insertTrieWord("abc");
	insertTrieWord("abc");
	removeTrieWord("abc");

	cout << "ashraf : " << searchTrieWord("abc") << endl; // true
	cout << "towhid: " << searchTrieWord("trew") << endl; // true
	cout << "tanim: " << searchTrieWord("bgre") << endl; // true
	cout << "not: " << searchTrieWord("not") << endl; //false
	return 0;
}
