/*
	revrse a linked list 
	1. recursively
	2. iteratively
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	node *next;
};

node *newNode(int x)
{
	node *temp = new node;
	temp->val = x;
	temp->next = NULL;
	return temp;
}
node *insert(node *head,int k)
{
	if(head == NULL)
		return newNode(k);

	node *temp = head;
	node *n = newNode(k);
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next = n;
	return head;
}
void printLL(node *head)
{
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
}
node *rev_itr(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	node *cur = head,*prev=NULL,*next=NULL;
	while(cur!=NULL)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	head = prev;
	printLL(head);
}
node *rev_rec(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	node *first = head;
	node *rest = head->next;
	rest = rev_rec(rest);
	first->next->next = first;
	first->next = NULL;
	return rest;
}


int main()
{
	int x;
	node *head = NULL;
	while(cin>>x)
	{
		if(x==-1)
			break;
		head = insert(head,x);

	}
	rev_itr(head);
	node *t = rev_rec(head);
	printLL(t);
}