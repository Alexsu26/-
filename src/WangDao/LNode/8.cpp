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
//比较结点的代码与比值差不多，但是不好实现；书上源码用到了longlist和
//shortlist，避免了分情况讨论，还是有参考价值
LNode* Search_1st_Common(LNode *L1, LNode* L2)
{
    int len1 = length(L1),len2 = length(L2);
    LNode *longlist, *shortlist;
    if( len1 > len2 ) 
    {
        longlist = L1;
        shortlist = L2;
        dist = len1 - len2;
    }
    else
    {
        longlist = L2;
        shortlist = L1;
        dist = len2 - len1;
    }
    while(dist--)
        longlist = longlist->next;
    while(longlist != NULL)
    {
        if(longlist == shortlist)
            return longlist;
        else
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
    return NULL;

}