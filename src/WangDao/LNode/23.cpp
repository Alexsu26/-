/*
带头结点,data<n, 删除绝对值相等的结点，保留第一次出现的，
1. 利用大小为n的数组存储已访问过的data值；
遍历链表，若data值未存储，则num【data】=1；否则删除该结点；
2. typedef struct LNode{
    int data;
    LNode* link;
}LNode;
4. 时间复杂度O(n), 空间复杂度 O(n)
*/
void UniqueLL(LNode *head, int n)
{
    int num[n];
    for(int i=0; i<n; i++)
        num[i] = 0;
    LNode *p = head->next;
    LNode *pre = head;
    while( p != NULL )
    {
        if( num[abs(p->data)+1] )
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            num[abs(p->data)+1] = 1;
            pre = p;
            p = p->next;
        }
    }
}
//致命错误：data < n，应该用n+1的数组；要考虑0；
//删除的时候，可以把循环条件改为：while(p->next != NULL)
//每次判断 p->next->data 是否出现过
//这样删除可以用：r = p->next; p->next = r->next; free(r);
//删除结点，就少一个pre指针