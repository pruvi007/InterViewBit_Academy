/*
	Merge K sorted linked Lists
	Idea: keep merging two at a time
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

ListNode* mergeTwo(ListNode *a,ListNode *b)
{
    ListNode *t1 = a,*t2 = b;
    ListNode *t;

    // select the head of the merged LL
    if(t1->val < t2->val)
    {
        t = t1;
        t1=t1->next;
    }
    else
    {
        t = t2;
        t2 = t2->next;
    }

    // now merge the two LL
    ListNode *itr = t;
    while(t1 && t2)
    {
        if(t1->val < t2->val)
        {
            itr->next = t1;
            t1 = t1->next;
            
        }
        else 
        {
            itr->next = t2;
            t2 = t2->next;
            
        }
        itr=itr->next;
        
            
    }

    // append the left out LL
    if(t1)
    {
        itr->next = t1;
    }
    if(t2)
    {
        itr->next = t2;
    }
    
    return t;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    int n = A.size();
    if(n<=1)
    {
        ListNode *t = A[0];
        return t;
    }
    else
    {
        ListNode* temp = mergeTwo(A[0],A[1]);
        for(int i=2;i<n;i++)
        {
            temp = mergeTwo(temp,A[i]);
        }
        return temp;
            
    }
    
}
