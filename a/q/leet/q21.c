/*
Merge two sorted linked lists
and return it as a new list.
The new list should be made by
splicing together the nodes of
the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

#include <stdio.h>
#include<stdlib.h>

struct ListNode {
	int val;
	struct ListNode* next;
};

void list_print(struct ListNode* l) {
	while(l!=NULL){
		printf("%d->",l->val);
		//scanf("%d",&dum);
		l=l->next;
	}
	printf("NULL\n");
}

struct ListNode* list_new(int* arr, int len) {
	int i=0;
	struct ListNode *head,*p=malloc(sizeof(struct ListNode));

	do{
		if(i==0)head=p;
		p->val = arr[i++];
		//printf("%d ",p->val);
		if(i==len){
			p->next=NULL;
		}else{
			p->next=(struct ListNode*)malloc(sizeof(struct ListNode));
			p=p->next;
		}
	}while(i<len);
	//printf("\n==%d\n",head->val);
	//list_print(head);

	return head;
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
}

int main() {
	int a[4] = {0, 1, 2, 3};
	int b[3]={4,5,6};
	struct ListNode* l1=list_new(a,4);
	struct ListNode* l2=list_new(b,3);

	//printf("%d",l1->val);
	list_print(l1);
	list_print(l2);
	list_print(mergeTwoLists(l1,l2));

	return 0;
}

