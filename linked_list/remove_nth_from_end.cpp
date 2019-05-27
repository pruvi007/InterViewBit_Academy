/*
	remove nth node from end from a linked list.
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

node *remove_from_end(node *head,int pos)
{
	if(pos==1)
	{
		node *temp = head;
		head = temp->next;
		free(temp);
		return head;
	}
	int c = 1;
	node *temp = head,*prev=head;

	while(temp!=NULL)
	{
		temp = temp->next;
		c++;
		if(c==pos)
		{
			prev->next = temp->next;
			free(temp);
			break;
		}
		prev = temp;
	}
	return head;
}

int main()
{
	int x;
	node *head = NULL;
	int n=0;
	while(cin>>x)
	{
		if(x==-1)
			break;
		head = insert(head,x);
		n++;

	}
	int k;
	cin>>k;
	if(k>n)
		k = n;
	int pos = n-k+1;
	head = remove_from_end(head,pos);
	print(head);

}