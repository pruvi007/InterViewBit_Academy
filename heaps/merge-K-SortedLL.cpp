/*
	Merge k sorted Linked Lists
	Using Min Heap
	idea is to push all nodes in heap then if next exists then push that
*/
// solution by @pruvi007


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct myComp { 
    bool operator()(struct ListNode* a, struct ListNode* b) 
    { 
        return a->val > b->val; 
    } 
}; 

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    priority_queue<ListNode *,vector<ListNode *>,myComp> pq;
    int n = A.size();
    for(int i=0;i<n;i++)
    	pq.push(A[i]);
    ListNode *head=NULL,*temp;
    while(!pq.empty())
    {
    	ListNode *t = pq.top();
    	pq.pop();

    	if(t->next)
    		pq.push(t->next);

    	if(head==NULL)
    	{
    		head = t;
    		temp = head;
    	}
    	else
    	{
    		temp->next = t;
    		temp = t;
    	}
    }
    return head;
}