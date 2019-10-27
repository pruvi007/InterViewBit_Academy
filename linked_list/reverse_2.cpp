ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    if(A==NULL || A->next==NULL)
        return A;

    ListNode *curr = A;
    ListNode *n = A;
    ListNode *prev=NULL;
    int c = 0,size = C-B+1;
    
    ListNode *lstart=NULL,*start=A,*rend=NULL,*end;
    while( curr!=NULL and c<B-1)
    {
        lstart = curr;
        curr = curr->next;
        c++;
    }
    // cout << curr->val << endl;
    start = curr;
    c=0;
    while( curr!=NULL and c<size )
    {
        n = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n;
        c++;
    }
    // cout << prev->val << " "  << endl;
    rend = curr;
    end = prev;
    
    // case if m is the 1st node then head will change
    if( lstart!=NULL )
        lstart->next = end;
    else
        A = end;
    start->next = rend;
    
    return A;
    
}