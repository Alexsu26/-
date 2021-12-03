/*
非循环双链表，设计Locate（L，x）函数，每次访问x使freq+1，
并使freq大的排前面，最后访问的排前面
*/

LNode* Locate(LNode* L, Elemtype x)
{
    LNode* p = L->next;
    while( p->data != x)            //while( p && p->data != x)
        p = p->next;                // p = p->next;
    p->freq++;                      //if(!p) {cout << "don`t exit"; exit(0)}
    LNode* q = p->pred;             
    while( q->freq <= p->freq)      //while( q!=L && q->freq<=p->freq )
    {
        q = q->pred;
    }
    p->pred->next = p->next;        //可以
    p->next->pred = p->pred;        //需判断if(p->next != NULL)
    q->next->pred = p;
    p->next = q->next;
    q->next = p;
    p->pred = q;

    return p;
}
//完整代码如下：
DLnode* Locate( DLnode* L, Elemtype x)
{
    DLNode *p = L->next, *q;
    while(p && p->data !=x)
        p = p->next
    if( !p )
    {
        cout << "do not exist x\n";
        exit(0);
    }
    else
    {
        p->freq++;
        if(p->next != NULL) 
            p->next->pred = p->pred;        //判断后面是否还有
        p->pred->next = p->next;            //p从链表脱离
        while(q != L && q->freq <= p->freq) //找到插入位置
         q = q->pred;
        p->next = q->next;                  //p插入q的后面
        q->next->pred = p;
        p->pred = q;
        q->next = p;
    }
    return p;
}