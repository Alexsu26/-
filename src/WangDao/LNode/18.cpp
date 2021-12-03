/*
循环单链表h1，h2，将h2连接到h1之后，且仍为循环单链表
*/

void Addition_h1_h2(LNode *h1, LNode *h2)
{
    LNode *r1 = h1->next, *r2 = h2->next;
    while( r1->next != h1)
        r1 = r1->next;
    while( r2->next != h2 )
        r2 = r2->next;
    r1->next = h2->next;
    r2->next = h1;
    free(h2);
}