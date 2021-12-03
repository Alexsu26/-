/*
两个递增单链表，归并为一个递减单链表，不创建新链表,假设都带头结点
通过头插法
*/

void Union_L1_L2(LNode *&L1, LNode *&L2)
{
    LNode *p = L1->next;
    LNode *q = L2->next;
    LNode *temp;
    L1->next = NULL;        //很重要，之前的错误都源于此
    free(L2);
    while( p!=NULL && q != NULL)
    {
        if( p->data < q->data )
        {
            temp = p;
            p = p->next;
            temp->next = L1->next;
            L1->next = temp;
        }
        else
        {
            temp = q;
            q = q->next;
            temp->next = L1->next;
            L1->next = temp;
        }
    }
    while( p!= NULL)                    //只用1句；
    {                                   //if(p) q = p;
        temp = p;                       //这样将两种情况统一为一段代码
        p = p->next;
        temp->next = L1->next;
        L1->next = temp;
    }
    while( q!= NULL)
    {
        temp = q;
        q = q->next;
        temp->next = L1->next;
        L1->next = temp;
    }
}