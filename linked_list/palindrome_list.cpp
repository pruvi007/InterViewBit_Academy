/*
	check whether a linked list is a palindrome or not. in O(1) space and linear time
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
struct node
{
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
node *insert(node *head,int x)
{
	if(head==NULL)
		return newNode(x);
	node *n = newNode(x);
	node *temp = head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next = n;
	return head;
}
void print(node *head)
{
	node *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
int checkPalindrome(node *head)
{
	if(head==NULL || head->next==NULL)
		return 1;
	
	node *slow=head,*fast=head,*prev;
	while(fast!=NULL && fast->next!=NULL)
	{
		fast = (fast->next)->next;
		prev = slow;
		slow = slow->next;
	}
	node *curr = slow,*next = slow;
	prev->next = NULL;
	while(curr!=NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	node *temp=head;
	while(temp!=NULL && prev!=NULL)
	{
		if(temp->val!=prev->val)
			return 0;
		temp = temp->next;
		prev = prev->next;
	}
	return 1;
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
	print(head);
	int ans = checkPalindrome(head);
	cout<<ans<<endl;
}