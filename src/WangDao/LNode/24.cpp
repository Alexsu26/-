/*
判断一个链表是否有环，如果有，找到环的入口点并返回，否则返回NULL
*/
LNode* CheckCircle(LNode *L)
{
    LNode *p = L->next;
    LNode *start, *temp;
    while( p!= NULL)
    {
        temp = p;
        while( temp != NULL)
            if( temp->next == p)
                break;
        if( temp != NULL )
            return p;
        else
            p = p->next;
    }
}

//没看懂啊存疑
//看了知乎的解答，勉强懂了，暂时放着
LNode* FindLoopStart(LNode *head)
{
    LNode *fast = head, *slow = head;
    while(slow!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
            break;
    }
    if(slow==NULL || fast->next == NULL)
        return NULL;
    LNode *p1 = head, *p2 = slow;
    while( p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}