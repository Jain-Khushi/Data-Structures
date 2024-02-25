#include<bits/stdc++.h>
using namespace std;

void reverse(string str)
{
    stack<char> st;
    stack<char> rev;
    for (int i = 0; i < str.length(); i++)
    {
        st.push(str[i]);
    }
    cout<<endl<<"Reversed Stack : ";
    while (!st.empty())
    {
        cout<<st.top();
        rev.push(st.top());
        st.pop();
    }
    
    /*cout<<endl<<"Reversed string : ";
    while (!rev.empty())
    {
        cout<<rev.top();
        rev.pop();
    }*/
    return;
}
int main()
{
    string num;
    cout<<"Enter the contents of stack : ";
    cin>>num;
    reverse(num);
    return 0;
}