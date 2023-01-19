#include<stdio.h>
#include<malloc.h>

typedef struct nodeStruct {
	int data;
	struct nodeStruct *next;
}Node;

Node *createNode(int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertFirst(Node *head, int data) {
	Node *newNode = createNode(data);
	newNode->next = head->next;
	head->next = newNode;
}

void insertAnyPosition(Node *head, int pos, int data) {
	Node *cur = head;
	for (int i = 2; i <= pos; i++) {
		cur = cur->next;
		if (!cur)
			return;
	}
	Node *newNode = createNode(data);
	newNode->next = cur->next;
	cur->next = newNode;
}

void insertLast(Node *head, int data) {
	Node *cur = head;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = createNode(data);
}

void deleteFirst(Node *head) {
	if (NULL == head->next)
		return;
	Node *temp = head->next->next;
	free(head->next);
	head->next = temp;
}

void deleteAnyPosition(Node *head, int pos) {
	Node *cur = head;
	for (int i = 2; i <= pos; i++) {
		cur = cur->next;
		if (!cur)
			return;
	}
	//deleteFirst(cur);
	Node *temp = cur->next->next;
	free(cur->next);
	cur->next = temp;
}

void deleteLast(Node *head) {
	Node *cur = head;
	while (cur->next && cur->next->next)
		cur = cur->next;
	//deleteFirst(cur);
	free(cur->next);
	cur->next = NULL;
}

void printList(Node *head) {
	printf("Linked List contains: \n");
	Node *list = head->next;
	while (list) {
		printf("%d ", list->data);
		list = list->next;
	}
	printf("\n");
}

int main() {
	Node *head;
	int data;
	int pos, choice;
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
