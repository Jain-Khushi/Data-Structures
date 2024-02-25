#include<bits/stdc++.h>
using namespace std;

void Add(string num1 , string num2)
{
    stack<int> st1;
    stack<int> st2;
    stack<int> st3;
    int carry=0;
    int sum=0;

    //Adding elements in stack 1
    for (int i = 0; i < num1.length(); i++)
    {
        st1.push(num1[i]-'0');
    }

    //Adding elements in stack 2
    for (int i = 0; i < num2.length(); i++)
    {
        st2.push(num2[i]-'0');
    }
    
     
    // Push elements in the final stack
    while (!st1.empty() && !st2.empty())
    {
        sum=sum+carry+st1.top()+st2.top();
        if(sum>9)
        {
            carry=1;
            st3.push(sum%10);
        }
        else
        {
            carry=0;
            st3.push(sum);
        }
        sum=0;
        st1.pop();
        st2.pop();
    }

    // If stack 1 is still non empty
    while (!st1.empty())
    {
        sum=sum+carry+st1.top();
        if(sum>9)
        {
            carry=1;
            st3.push(sum%10);
        }
        else
        {
            carry=0;
            st3.push(sum);
        }
        sum=0;
        st1.pop();
    }

    // If the stack 2 is still non empty
    while (!st2.empty())
    {
        sum=sum+carry+st2.top();
        if(sum>9)
        {
            carry=1;
            st3.push(sum%10);
        }
        else
        {
            carry=0;
            st3.push(sum);
        }
        sum=0;
        st2.pop();
    }

    //If the carry is still greater than 0 then add is into the final stack
    if(carry>0)
    {
        st3.push(carry);
    }

    // Print the final stack 
    while(!st3.empty())
    {
        cout<<st3.top();
        st3.pop();
    }
    cout<<endl;
}

int main()
{
    string num1="";
    string num2="";
    cout<<"Enter First Number : ";
    cin>>num1;

    cout<<"Enter Second Number : ";
    cin>>num2;

    Add(num1,num2);
    return 0;
}