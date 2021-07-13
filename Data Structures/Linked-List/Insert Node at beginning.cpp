/*これを翻訳している間、あなたはあなたの人生のいくつかの貴重な瞬間を無駄にしました*/
#pragma comment (linker,"/STACK:16777216")
#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *head;

void insert_begin(int x){
    struct node *temp = new node();
    temp->data = x;
    temp->next = head;
    head = temp;
}


void print(){
    struct node *temp = head;
    cout << "The list: " << endl;

    while(temp != NULL){
        cout << temp->data <<' ';
        temp = temp->next;
    }
    cout << endl;
}


void task(){
    head = NULL;
    int n; cin >> n;
    for(int i = 0; i<n; i++){
        int item; cin >> item;
        insert_begin(item);
        print();
    }
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef _Local
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int T = 1; //cin >> T;
    for(int __ = 1; __ <= T; __++){
        //cout <<"Case "<<__<<": ";
        task();
    }
      
return 0;
}
