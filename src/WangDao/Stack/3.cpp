bool isValid(char op[])
{
    stack<char> S;
    int i = 0;
    while( i>=0 )
    {
        if(op[i] == 'I')
            S.push(op[i]);
        else if( op[i] == 'O')
        // {                                //需要判断的是输入是否合法，不能在栈空的时候pop
        //     if(Emptu(S))   
        //         return false;
        //     S.pop();
        // }
            S.pop(op[i]);
        else
            break;
        ++i;
    }
    if( Empty(S))
        return true;
    else
        return false;
}