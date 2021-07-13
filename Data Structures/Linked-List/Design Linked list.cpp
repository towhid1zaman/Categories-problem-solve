// Definition for singly-linked list.
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {} // constructor
};

class MyLinkedList {
    SinglyListNode *head;
    SinglyListNode *tail;
    int length;
    
    public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        SinglyListNode *p = head;
        if (index >= length || index <0)
            return -1;
        
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        return p->val;
    }
    
    /** Add a node of value val before the first element of the linked list.
    After the insertion, the new node will be the first node of the linked list. */
    
    void addAtHead(int val) {
        SinglyListNode *p = new SinglyListNode(val);
        p->next = head;
        head = p;
        length++;
        if (length == 1) tail = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode *p = new SinglyListNode(val);
        if (tail != NULL) {
            tail->next = p;
        }
        tail = p;
        length++;
        if (length == 1) head = tail; 
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, 
    the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    
    void addAtIndex(int index, int val) {
        if (index > length)
            return;
        
        if (index <= 0) {
            addAtHead(val);
            return;
        }
        if (index == length) {
            addAtTail(val);
            return;
        }
        SinglyListNode *p = head;
        for (int i = 0; i < index-1; i++) {
            p = p->next;
        }
        SinglyListNode *q = new SinglyListNode(val);
        q->next = p->next;
        p->next = q;
        length++;
    }
    // Print whole linked list
    void printlist(){
        SinglyListNode *temp = head;
        cout << "The list: " << endl;

        while(temp != NULL){
            cout << temp->val <<' ';
            temp = temp->next;
        }
        cout << endl;
    }
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) { 
        if (index >= length || index<0)
            return;
        
        SinglyListNode *p = head;
        if (index == 0) {
            head = head->next;
            delete p;
            length--;
            return;
        }

        for (int i = 0; i < index-1; i++) {
            p = p->next;
        }
        SinglyListNode *q = p->next;
        p->next = q->next;
        if (tail == q) tail = p;
        delete q;
        length--;
    }
};
