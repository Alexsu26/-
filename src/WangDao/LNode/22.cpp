/*
 带头结点保存单词，有相同后缀的享用相同空间；
 str1和str2分别指向头结点，找到两链表共同后缀的起始位置
1. 若两字符有相同后缀，则从后往前遍历到共同后缀的起始位置应该是相同
的，因此，先分别遍历str1和str2，得到链表长度，将较长者指针先
移动到和较短者的位置，再一起移动，直到碰到第一个相同data；
3. 时间复杂度O(n), 空间复杂度O(1)
*/
void Search_1st_Common(LNode *str1, LNode *str2)
{
    LNode *longlist = str1->next, *shortlist = str2->next;
    int len1 = 0, len2 = 0, dist;
    while(longlist != NULL)
    {
        len1++;
        longlist = longlist->next;
    }
    while( shortlist != NULL)
    {
        len2++;
        shortlist = shortlist->next;
    }
    if( len1 > len2)
    {
        longlist = str1->next;
        shortlist = str2->next;
        dist = len1 - len2;
    }
    else
    {
        longlist = str2->next;
        shortlist = str1->next;
        dist = len2 - len1;
    }
    while( dist-- )
        longlist = longlist->next;
    int count = 0;
    while(shortlist != NULL )
    {
        count++;
        LNode *p = longlist, *q = shortlist;
        while(p != NULL && p->data == q->data)
        {
            p = p->next;
            q = q->next;
        } 
        if( p == NULL )
        {
            cout << count << "\n";
            break;
        }
        else
        {
            shortlist = shortlist->next;
            longlist = longlist->next;
        }
    }
}
//这类题都理解错了意思，以后凡是求后缀相同的起始位置，一律按照求结点，而不是求值
//书上 是不用longlist的方法，也可以，值得学习
SNode* find_addr(SNode * str1, SNode * str2)
{
    int m,n;
    SNode *p, *q;
    m = listlen(str1);
    n = listlen(str2);
    for(p=str1; m>n; m--)           //只用判断两次就行，甚至还讲pq都指向了头结点
        p = p->next;
    for(q=str2; n>m; n--)
        q = q->next;
    
    while(p->next!=NULL && p->next != q->next)  //用p->next != q->next判断是否存在相同后缀
    {
        p = p->next;
        q = q->next;
    }
    return p->next;
}
