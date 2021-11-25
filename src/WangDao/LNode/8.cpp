/*
两个单链表找公共结点
假设都不带头结点
参考了别人的思路：两个链表尾部长度一样，先得到两链表的长度，
长的先走，直到两者等长，再一起遍历
有一个问题：现在在比较值，若要比较结点，需要更改类型
*/
void OverlapLL(LNode *L1, LNode *L2)
{
    int len1=0, len2=0;
    LNode *p1=L1, *p2=L2;
    while( p1 != NULL)
    {
        len1++;
        p1 = p1->next;
    }
    while( p2 != NULL)
    {
        len2++;
        p2 = p2->next;
    }
    p1 = L1, p2 = L2;
    int count, flag;
    if(len1 > len2)
    {
        count = len1 - len2;
        flag = 1;
    }
    else
    {
        count = len2 - len1;
        flag = 0;
    }
    while(count > 0)
    {
        if(flag)
            p1 = p1->next;
        else
            p2 = p2->next;
        count--;
    }   
    while( (p1->data != p2->data) && (p1!= NULL) && (p2 != NULL))
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    while( p1!= NULL && p2!=NULL)
    {
        cout << p1->data << " ";
        p1 = p1->next;
        p2 = p2->next;
    }
}