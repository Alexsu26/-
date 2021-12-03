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

