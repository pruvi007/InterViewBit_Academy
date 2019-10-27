
ListNode *reverse(ListNode *head,int k)
{
    ListNode *cur = head, *prev = NULL, *next = NULL;
    int c = 0;
    while(cur!=NULL and c!=k)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        c++;
    }

    // (k+1)th node is the next pointer, so we will start reversing from here
    if(next!=NULL)
        head->next = reverse(next,k);
    return prev;
}

ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A==NULL || A->next==NULL)
        return A;
    
    return reverse(A,B);
    
}
