//Linked List add, del, reverse
#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	char data;
	struct ListNode* link;
}ListNode;
ListNode* Head = NULL;

void display(ListNode* list) {
	printf("=== 연결 리스트 원소 출력 ===\n");
	list = Head;
	while (list != NULL) {
		printf("%c ", list->data);
		list = list->link;
	}printf("\n");
}
void Add_first(ListNode* list, char x) {
	ListNode* newnode; //노드 할당을 위한 포인터 변수 선언
	newnode = (ListNode*)malloc(sizeof(ListNode)); //노드 생성
	newnode->data = x;			//새로운 노드의 데이터 입력

	if (Head == NULL) {			//공백 리스트인 경우
		newnode->link = NULL;
		Head = newnode;
	}
	else {						//기존 리스트가 존재하는 경우
		newnode->link = Head;
		Head = newnode;
	}
}

void Add_last(ListNode* list, char x) {
	ListNode* newnode, * temp;
	printf("\n== 연결 리스트의 마지막에 노드(K) 삽입 ==\n");
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
	printf("\n== 연결리스트의 역방향 연결 ==\n");
	while (p1 != NULL) {
		p3 = p2;
		p2 = p1;
		p1 = p1->link;
		p2->link = p3;
	}Head = p2;
}
void Del_item(ListNode* list, char x) {		//지정 중간노드삭제
	ListNode* pre, * target;
	printf("\n== 연결 리스트에서 중간 노드(B) 삭제 ==\n");
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
	ListNode* List_1 = NULL; //공백 리스트(List_1) 생성
	List_1 = Head;

	Add_first(List_1, 'A');//List_1의 맨 앞에 A삽입(A)
	display(List_1);
	Add_first(List_1, 'B'); //List_1의 맨 앞에 B삽입(B A)
	display(List_1);
	Add_first(List_1, 'C'); //List_1의 맨 앞에 C삽입(C B A)
	display(List_1);
	Add_last(List_1, 'K'); //List_1의 맨 앞에 C삽입(C B A)
	display(List_1);
	Reverse(List_1);
	display(List_1);
	Del_item(List_1, 'B');
	display(List_1);
}
