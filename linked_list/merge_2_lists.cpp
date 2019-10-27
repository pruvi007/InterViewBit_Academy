ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode *p;
    if(A->val<B->val)
    {
        p = A;
        A = A->next;
    }
    else 
    {
        p = B;
        B = B->next;
    }
    ListNode *head = p;
    while(A!=NULL && B!=NULL)
    {
        if(A->val<B->val)
        {
            head->next = A;
            A = A->next;
            
        }
        else 
        {
            head->next = B;
            B = B->next;
            
        }
        
        head = head->next;
        
    }
    if(A!=NULL)
    {
        head->next = A;
    }
    if(B!=NULL)
    {
        head->next = B;
    }
    return p;
    
}