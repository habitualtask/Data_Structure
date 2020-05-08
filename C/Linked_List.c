//Linked List add, del, reverse
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	char data;
	struct ListNode* link;
}ListNode;
ListNode* Head = NULL;

void display(ListNode* list) {
	printf("=== ���� ����Ʈ ���� ��� ===\n");
	list = Head;
	while (list != NULL) {
		printf("%c ", list->data);
		list = list->link;
	}printf("\n");
}
void Add_first(ListNode* list, char x) {
	ListNode* newnode; //��� �Ҵ��� ���� ������ ���� ����
	newnode = (ListNode*)malloc(sizeof(ListNode)); //��� ����
	newnode->data = x;			//���ο� ����� ������ �Է�

	if (Head == NULL) {			//���� ����Ʈ�� ���
		newnode->link = NULL;
		Head = newnode;
	}
	else {						//���� ����Ʈ�� �����ϴ� ���
		newnode->link = Head;
		Head = newnode;
	}
}

void Add_last(ListNode* list, char x) {
	ListNode* newnode, * temp;
	printf("\n== ���� ����Ʈ�� �������� ���(K) ���� ==\n");
	newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->link = NULL;
	temp = Head;

	while (temp->link != NULL)
		temp = temp->link;
	temp->link = newnode;
}

void Reverse(ListNode* list) {
	ListNode* p1, * p2, * p3;
	p1 = Head; p2 = NULL; p3 = NULL;
	printf("\n== ���Ḯ��Ʈ�� ������ ���� ==\n");
	while (p1 != NULL) {
		p3 = p2;
		p2 = p1;
		p1 = p1->link;
		p2->link = p3;
	}Head = p2;
}
void Del_item(ListNode* list, char x) {		//���� �߰�������
	ListNode* pre, * target;
	printf("\n== ���� ����Ʈ���� �߰� ���(B) ���� ==\n");
	pre = Head;
	target = pre->link;

	while (target->data != x) {
		pre = target;
		target = target->link;
	}
	if (target->data = x)
		pre->link = target->link;
	free(target);
}

void main() {
	ListNode* List_1 = NULL; //���� ����Ʈ(List_1) ����
	List_1 = Head;

	Add_first(List_1, 'A');//List_1�� �� �տ� A����(A)
	display(List_1);
	Add_first(List_1, 'B'); //List_1�� �� �տ� B����(B A)
	display(List_1);
	Add_first(List_1, 'C'); //List_1�� �� �տ� C����(C B A)
	display(List_1);
	Add_last(List_1, 'K'); //List_1�� �� �տ� C����(C B A)
	display(List_1);
	Reverse(List_1);
	display(List_1);
	Del_item(List_1, 'B');
	display(List_1);
}
