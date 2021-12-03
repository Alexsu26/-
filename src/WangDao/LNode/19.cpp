/*
带头结点循环单链表，找到最小值输出并删除结点
*/
void ReleaseL(LNode *L)
{
    LNode *p, *pre, *temp;
    while( L->next != L)
    {
        p = L->next, pre = L;
        while( p->next != L)
        {
            if( p->next->data < pre->data)
                pre = p;
            p = p->next;
        }
        temp = pre->next;
        pre->next = temp->next;
        cout << temp->data << " ";
        free(temp);
    }
    //free(L);              释放头结点
}