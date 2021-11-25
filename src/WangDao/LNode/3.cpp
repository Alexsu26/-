//带头结点，反向输出结点值
void ReversePrint(LNode* L)     //调用时使用ReversePrint(head->next)
{
    LNode* p = L;
    if( p->next != NULL)
        ReversePrint(p->next);
    if( p!= NULL)
        cout << p->data << " ";
}