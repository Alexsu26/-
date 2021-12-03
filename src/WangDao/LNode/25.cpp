/*
要求空间复杂度O（1），重排L(a1,a2,,,an-1,an)
L` = {a1, an, a2, an-1,,,,,,}

1. 若每次遍历尾结点再找到插入位置，可满足，但时间复杂度太高了
有没有简单点的办法
try：采用链表逆置，从第二个结点到最后一个
3. 时间复杂度O(n)，空间复杂度O(1);
*/
void ReSortLL(LNode *L)
{
    LNode *rL = L->next;
    LNode *p, *r, *head;
    while( rL->next != NULL )
    {
        p = rL->next;
        head = p;
        while( p->next != NULL )
        {
            r = p->next;
            p->next = r->next;
            r->next = head;
            head = r;
        }
        rL->next = head;
        rL = rL->next;
    }
}
//书上想法为：找到中间结点，先把后半部分逆置，再从头向中间插入
//找到中间结点的算法同24题，采用两个指针pq，p走一步，q走两步
//q到表尾，p到中间
void change_list(LNode *h)
{
    LNode *p, *q, *r, *s;
    p = q = h;
    while( q->next != NULL )        //p即为中间结点
    {
        p = p->next;
        q = q->next;
        if( q->next != NULL )
            q = q->next;
    }
    q = p->next;                    //q为后半部分第一个结点
    
    p->next = NULL;                 //后半部分逆置
    while( q!=NULL )
    {
        r = q->next;
        q->next = p->next;
        p->next = q;
        q = r;
    }

    s = head->next;                 //s为前半部分第一个插入结点
    q = p->next;                    //q为后半部分第一个待插入结点
    p->next = NULL;
    while( q!=NULL)
    {
        r = q->next;
        q->next = s->next;
        s->next = q;
        s = q->next;
        q = r;
    }
}
