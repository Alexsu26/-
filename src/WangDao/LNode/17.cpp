/*
带头结点，循环双链表，判断是否对称
*/
bool Symm(LNode *L)
{
    LNode *head = L->next;
    LNode *rare = L->pre;
    while( head->next != rare && head != rare)  //第一个条件可以写成
    {                                           //rare->next != head;
        if( head->data == rare->data )          //就可以不用下面那个判断head和rare的data的if了
        {
            head = head->next;
            rare = rare->pre;
        }
        else
            break;                              //return 0;
    }
    if( head->data == rare->data )
        return true;
    else
        return false;
}