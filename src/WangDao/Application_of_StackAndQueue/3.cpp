/*
用栈实现：
            1              n = 0
pn(x) =     2x             n = 1
            2xPn-1(x) - 2(n-1) Pn-2(x) n>1
# TODO: 感觉要定义一个结构体，存储其n值，并且要存储判断他是否分解了两次
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
        return p1 - p2;
    }
}
//书上答案：
double p(int n, double x)
{
    struct stack
    {
        int n;
        double value;
    }st[MaxSize];
    int top = -1, i;
    double fv1 = 1, fv2 = 2*x;
    for(i = n; i>=2; i--)
    {
        top++;
        st[top].n = i;
    }
    while( top >= 0)
    {
        st[top].value =2*x*fv2 - 2*(st[top].no - 1) * fv1;
        fv1 = fv2;
        fv2 = st[top].value;
        top--;
    }
    if(n==0) return fv1;
    return fv2;
}
//仿照答案写了一个：
//这样跟递归很像，但跟栈就没有关系了    
double p_test(int n, double x)
{
    int value[10];
    int top = 2;
    value[0] = 1, value[1] = 2*x;
    while( top <= n)
    {
        value[top] = 2*x*value[top-1] - 2*(top-1)*value[top-2];
        top++;
    }
    return value[top-1];
}