#include<iostream>
#include<stack>

using namespace std;

bool delimiter(string str)
{
    stack<char> st;
    bool ans=true;

    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            st.push(str[i]);
        }
        else if (str[i]==')')
        {
            if(!st.empty() && (st.top()=='('))
            {
                st.pop();
            }
            else
            {  
                ans=false;
                break;
            }
        }
        else if (str[i]=='}')
        {
            if(!st.empty() && (st.top()=='{'))
            {
                st.pop();
            }
            else
            {  
                ans=false;
                break;
            }
        }
        else if (str[i]==']')
        {
            if(!st.empty() && (st.top()=='['))
            {
                st.pop();
            }
            else
            {  
                ans=false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        return false;
    }
    return ans;
}

int main()
{
    string str;
    cout<<"Enter a string : ";
    cin>>str;
    if(delimiter(str))
    {
        cout<<"Valid string"<<endl;
    }
    else
    {
        cout<<"Invalid string"<<endl;
    }
    return 0;
}