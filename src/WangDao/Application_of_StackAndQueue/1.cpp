/*
匹配括号()[]{}

*/
bool Match(char str[])
{
    stack<char> S;
    int i = 0;
    char x = str[i];
    while( x != '\0' )
    {
        if(x == '(' || x== '[' || x== '{')
            S.push(x);
        else if( x == ')' && S.top() != '(')
            return false;
        else if( x== ']' && S.top() != '[')
            return false;
        else if( x== '}' && S.top() != '{')
            return false;
        else 
            S.pop();
        x = str[++i];
    }
    if( S.empty() )
        return true;
    else 
        return false;   
}