/*
带头结点，递增输出并删除
*/
void SortDelete(LNode *L)
{
    if( L->next == NULL )
        return;
    LNode *head = L;
    while( head->next != NULL )
    {
        LNode *p = head->next, *pre = head;
        LNode *temp = head->next;
        int min = 10000000;
        while( temp != NULL)
        {
            if( temp->data < min)
            {
                min = temp->data;
                while( p != temp)
                    p = p->next;
                while( pre->next != p)
                    pre = pre->next;
            }
            temp = temp->next;
        }
        cout << p->data << " ";
        pre->next = p->next;
        free(p);
    }
}