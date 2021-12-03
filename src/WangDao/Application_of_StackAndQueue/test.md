```C++
/*
用栈实现：
        1 n = 0
pn(x) = 2x n = 1
        2xPn-1(x) - 2(n-1) Pn-2(x) n>1
的变量，但是本身有很多数据，是否该声明为结构体数组。
*/
int Pnx( int x , int n)
{
    if( n == 0 )
        return 1;
    else if( n== 1)
        return 2*x;
    else
    {
        int p1 = 2 * x * Pnx(x, n-1);
        int p2 = 2 * (n-1) * pnx(x, n-2);
        return p1 - p2
    }
}
```