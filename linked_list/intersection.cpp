ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    ListNode *nl = NULL;
    if(A==NULL || B==NULL)
        return nl;
        
    int l1=0,l2=0;
    ListNode *t1=A,*t2=B;
    while(t1)
    {
        l1++;
        t1=t1->next;
    }
    while(t2)
    {
        l2++;
        t2 = t2->next;
    }
    if(l1>l2)
    {
        int d = abs(l1-l2);
        t1 = A;t2=B;
        int c =0;
        while(t1)
        {
        
            if(c==d)
                break;
            t1=t1->next;
            c++;
            
        }
        while(t1 && t2)
        {
            if(t1 == t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        ListNode *n=NULL;
        return n;
    }
    else
    {
        int d = abs(l1-l2);
        t1 = A;t2=B;
        int c =0;
        while(t2)
        {
            
            if(c==d)
                break;
            t2=t2->next;
            c++;
            
        }
        while(t1 && t2)
        {
            if(t1 == t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        ListNode *n=NULL;
        return n;
    }
}