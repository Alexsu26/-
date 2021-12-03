/*
带头结点，data，link，头指针list，
查找链表倒数第k个位置的结点，输出data值，返回1；否则返回0
1. 通过两个指针p，q，其中q指针与p指针相差k个单位，当p指针指到链尾时，q指针即指向所求
3. 时间复杂度O(n) 空间复杂度O(1)
*/
Elemtype FindLastK(LNode *list, elemtype k) 
{
    LNode *p = list->next, *q = list->next;
    while( p != NULL)
    {
        if(k>0)
            k--;
        else
            q = q->next;
        p = p->next;
    }
    if( k == 0 )
    {
        cout << q->data << "\n";
        return 1;
    }
    else
        return 0;
}