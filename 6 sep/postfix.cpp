#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int isdigit(char ch) 
{
    return (ch >= '0' && ch <= '9');    
}

int exp(char ch, int op1, int op2) 
{
    switch(ch)
    {
        case '+': return (op1 + op2);
            break; 

        case '-': return (op1 - op2);
            break;

        case '*': return (op1 * op2);
            break;

        case '/': return (op1 / op2);
            break;

        case '^': return (pow(op1,op2));
            break;
    }
}

int evaluatePostfix(string postfix){
    stack<int> S;
    char ch;
    int op1, op2;
    
    for(int i = 0; i < postfix.length(); ++i){
        ch = postfix[i];
        if(isdigit(ch)){
            S.push(int(ch - '0')); 
        }
        else
        {
        
            op2 = S.top();
            S.pop();

            op1 = S.top();
            S.pop();

            int value = exp(ch, op1, op2);
            S.push(value);
        
        }
    }
    return S.top();
}
int main(){
    string postfix;
    cout<<"Enter Postfix Expression (without spaces): ";
    cin>>postfix;
    cout<<"The result is: "<<evaluatePostfix(postfix)<<endl;
}