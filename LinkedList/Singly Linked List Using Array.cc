#include<stdio.h>
#include<malloc.h>

typedef struct nodeStruct {
	int data;
	//struct nodeStruct *next;
	int next;
}Node;

Node Pool[100005];
int poolIndex;

//Node *createNode(int data) {
int createNode(int data) {
	//Node *newNode = (Node *)malloc(sizeof(Node));
	int newNode = poolIndex++;
	//newNode->data = data;
	Pool[newNode].data = data;
	//newNode->next = NULL;
	Pool[newNode].next = -1;
	return newNode;
}

//void insertFirst(Node *head, int data) {
void insertFirst(int head, int data) {
	//Node *newNode = createNode(data);
	int newNode = createNode(data);
	//newNode->next = head->next;
	Pool[newNode].next = Pool[head].next;
	//head->next = newNode;
	Pool[head].next = newNode;
}

//void insertAnyPosition(Node *head, int pos, int data) {
void insertAnyPosition(int head, int pos, int data) {
	//Node *cur = head;
	int cur = head;
	for (int i = 2; i <= pos; i++) {
		//cur = cur->next;
		cur = Pool[cur].next;
		//if (cur == NULL)
		if (cur == -1)
			return;
	}
	//Node *newNode = createNode(data);
	int newNode = createNode(data);
	//newNode->next = cur->next;
	Pool[newNode].next = Pool[cur].next;
	//cur->next = newNode;
	Pool[cur].next = newNode;
}

//void insertLast(Node *head, int data) {
void insertLast(int head, int data) {
	//Node *cur = head;
	int cur = head;
	//while (cur->next) {
	while (Pool[cur].next != -1) {
		//cur = cur->next;
		cur = Pool[cur].next;
	}
	//cur->next = createNode(data);
	Pool[cur].next = createNode(data);
}

//void deleteFirst(Node *head) {
void deleteFirst(int head) {
	//if (NULL == head->next)
	if (-1 == Pool[head].next)
		return;
	//Node *temp = head->next->next;
	int temp = Pool[Pool[head].next].next;
	//free(head->next);
	//head->next = temp;
	Pool[head].next = temp;
}

//void deleteAnyPosition(Node *head, int pos) {
void deleteAnyPosition(int head, int pos) {
	//Node *cur = head;
	int cur = head;
	for (int i = 2; i <= pos; i++) {
		//cur = cur->next;
		cur = Pool[cur].next;
		//if (!cur)
		if (-1 == cur)
			return;
	}
	//Node *temp = cur->next->next;
	int temp = Pool[Pool[cur].next].next;
	//free(cur->next);
	//cur->next = temp;
	Pool[cur].next = temp;
}

//void deleteLast(Node *head) {
void deleteLast(int head) {
	//Node *cur = head;
	int cur = head;
	//while (cur->next && cur->next->next)
	while (Pool[cur].next != -1 && Pool[Pool[cur].next].next != -1)
		//cur = cur->next;
		cur = Pool[cur].next;
	//free(cur->next);
	//cur->next = NULL;
	Pool[cur].next = -1;
}

//void printList(Node *head) {
void printList(int head) {
	printf("Linked List contains: \n");
	//Node *list = head->next;
	int list = Pool[head].next;
	//while (list) {
	while (list != -1) {
		//printf("%d ", list->data);
		printf("%d ", Pool[list].data);
		//list = list->next;
		list = Pool[list].next;
	}
	printf("\n");
}

[Muhammad Ashraf - ul Asad]

int main() {
	//Node *head;
	int head;
	int data;
	int pos, choice;
	poolIndex = 0;
	head = createNode(-1);
	do {
		printList(head);
		printf("Enter your choice from 0 to 6\n");
		printf("0. Exit\n");
		printf("1. Insert first\n");
		printf("2. Insert any position\n");
		printf("3. Insert last\n");
		printf("4. Delete first\n");
		printf("5. Delete any position\n");
		printf("6. Delete last\n");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			printf("The program is now exit\n");
			break;
		case 1:
			printf("Enter data: ");
			scanf("%d", &data);
			insertFirst(head, data);
			break;
		case 2:
			printf("Enter any position: ");
			scanf("%d", &pos);
			printf("Enter any data: ");
			scanf("%d", &data);
			insertAnyPosition(head, pos, data);
			break;
		case 3:
			printf("Enter any data: ");
			scanf("%d", &data);
			insertLast(head, data);
			break;
		case 4:
			deleteFirst(head);
			break;
		case 5:
			printf("Enter any position: ");
			scanf("%d", &pos);
			deleteAnyPosition(head, pos);
			break;
		case 6:
			deleteLast(head);
			break;
		}
	} while (choice);
	return 0;
}
