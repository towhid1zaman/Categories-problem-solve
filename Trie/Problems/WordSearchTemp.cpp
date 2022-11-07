#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_CHILD 26
 
inline int getIndex(char a) {
    return a - 'a';
}
 
struct NodeWS {
    bool isLeaf;
    int count;
    NodeWS* child[MAX_CHILD];
};
 
NodeWS nodeArray[20000 * 30];
int arrayIt;
NodeWS* _root;
NodeWS *getNodeWS() {
    NodeWS *newNode = &nodeArray[arrayIt++];
    memset(newNode, 0, sizeof(NodeWS));
    return newNode;
}
int insertWord(char str[]) {
    NodeWS *cur = _root;
    int index;
    while (char ch = *str++) {
        index = getIndex(ch);
        if (cur->child[index]) {
            cur = cur->child[index];
        }
        else {
            cur->child[index] = getNodeWS();
            cur = cur->child[index];
        }
    }
    cur->count++;
    return cur->count;
}
 
int findWord(NodeWS *root, char *str, bool isRemove) {
    NodeWS *cur = root;
    int index;
    int cnt = 0;
    while (char ch = *str++){
        index = getIndex(ch);
        if (ch == '?') {
            for (int i = 0; i < 26; i++) {
                if (cur->child[i]) {
                    cnt += findWord(cur->child[i], str, isRemove);
                }
            }
            return cnt;
        }
 
        if (cur->child[index]) {
            cur = cur->child[index];
        }
        else {
            return 0;
        }
    }
 
    int wordCount = cur->count;
    if (isRemove)cur->count = 0;
     
    return wordCount;
}
void init() {
    arrayIt = 0;
    _root = new NodeWS();
}
 
int add(char str[]) {
    return insertWord(str);
}
 
int remove(char str[]) {
    NodeWS *cur = _root;
    int wordCount = findWord(cur, str, true);
    return wordCount;
}
 
int search(char str[]) {
    NodeWS *cur = _root;
    int wordCount = findWord(cur, str, false);
    return wordCount;
}
