/*연결리스트, 독립리스트*/

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int data;
	struct ListNode* link;
}ListNode;

void main() {

	ListNode* pt1, * pt2, * pt3;
	ListNode* list;

	pt1 = (ListNode*)malloc(sizeof(ListNode));
	pt2 = (ListNode*)malloc(sizeof(ListNode));
	pt3 = (ListNode*)malloc(sizeof(ListNode));

	pt1->data = '1';
	pt1->link = NULL;
	pt2->data = '2';
	pt2->link = NULL;
	pt3->data = '3';
	pt3->link = NULL;

	printf("== 독립적인 3개의 노드==\n");
	printf("pt1=%d, pt1->data=%c, pt1->link=%d\n", pt1, pt1->data, pt1->link);
	printf("pt2=%d, pt2->data=%c, pt2->link=%d\n", pt2, pt2->data, pt2->link);
	printf("pt3=%d, pt3->data=%c, pt3->link=%d\n", pt3, pt3->data, pt3->link);

	pt1->link = pt2;
	pt2->link = pt3;

	printf("\n== 연결된 3개의 노드==\n");
	printf("pt1=%d, pt1->data=%c, pt1->link=%d\n", pt1, pt1->data, pt1->link);
	printf("pt2=%d, pt2->data=%c, pt2->link=%d\n", pt2, pt2->data, pt2->link);
	printf("pt3=%d, pt3->data=%c, pt3->link=%d\n", pt3, pt3->data, pt3->link);

	list = pt1;
	printf("\n==  연결 리스트의 원소 ==\n");

	while (list != NULL) {
		printf(" %c ", list->data);
		list = list->link;
	}printf("\n");

	free(pt1);
	free(pt2);
	free(pt3);

}
