void Delete_head_x(LNode *&L, Elemtype x)
{
    LNode *p = L->next, *pre = L;         //LNode *q; 存放待删除结点
    while( p != NULL)                     //while( p!= NULL){
    {                                     //    if(p->data == x)
        if( p->data != x)                 //    {q=p; p=p->next; pre-next=p;free(q);}
        {                                 //    else{ pre=p; p=p->next;}
            pre = p;                      //    }  
            p = p->next;                  // 好处是用q存放待删除结点，不用判断p是否为最后一个结点
        }   
        else if(p->next != NULL)
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            free(p);
        }
    }
}