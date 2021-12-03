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
            if( temp->data < min)               //这里的找最小值不必要
            {                                   //只需要找到最小值的结点的前驱就可以了可以这样写
                min = temp->data;               //while(p->next != NULL)    
                while( p != temp)               // if(p->next->data < pre->next->data) pre = p;
                    p = p->next;                // p = p->next;
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