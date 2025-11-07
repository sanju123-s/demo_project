#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode {
	int val;
	struct ListNode* next;
} ListNode;

ListNode* createNode(int val)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}
void append(ListNode** head, int val)
{
	ListNode* newNode = createNode(val);
	if(*head == NULL)
	{
		*head = newNode;
		return;
	}
		ListNode* temp = head;
		while(temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;
}
void display(ListNode* head)
{
	if(!head)
	{
		printf("Empty List\n");
		return;
	}
	ListNode* temp = head;
	while(temp)
	{
		printf("%d->",temp->val);
		temp = temp->next;
	}
	printf("Null\n");
}
ListNode* deepcopy(ListNode* head)
{
	if(!head) return NULL;

	ListNode* newHead = createNode(head->val);
	ListNode* currNew = newHead;
	ListNode* currOld = head->next;

	while(currOld)
	{
		currNew->next = createNode(currOld->val);
		currNew = currNew->next;
		currOld = currOld->next;
	}
	return newHead;
}
void freeList(ListNode* head)
{
	ListNode* temp;
	while(head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
int main()
{
	ListNode* originalList = NULL;
	ListNode* copiedList = NULL;
	int n,val;
	
	printf("Enter the number of elements: ");
	scanf("%d",&n);

	printf("Enter %d elements: ",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d ->",&val);
		append(&originalList,val);
	}

	printf("OriginalList:");
	display(originalList);

	copiedList = deepcopy(originalList);
	
	printf("CopiedList:");
	display(copiedList);

	printf("Adding 99 to the copied list:");
	append(&copiedList,99);

	printf("ModifiedList:");
	display(copiedList);

	printf("OriginalList after modification of copiedlist:");
	display(originalList);

	freeList(originalList);
	freeList(copiedList);

	return 0;
}

