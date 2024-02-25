#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int prec(char c) {
	if(c == '^')
		return 3;
	else if(c == '/' || c =='*')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else
		return -1;
}

int infixToPostfix(string infix) {

	stack<int> S; 
	string result;

	for(int i = 0; i < infix.length(); i++) {
		char c = infix[i];

		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
			result += c;

		
		else if(c == '(')
			S.push('(');

		else if(c == ')') {
			while(S.top() != '(')
			{
				result += S.top();
				S.pop();
			}
			S.pop();
		}

		
		else {
			while(!S.empty() && prec(infix[i]) <= prec(S.top())) {
				result += S.top();
				S.pop();
			}
			S.push(c);
		}
	}

	
	while(!S.empty()) {
		result += S.top();
		S.pop();
	}

	cout<<"Infix to Postfix: "<<result<< endl;
}

int main() {
    string exp;
    cout<<"Enter Infix Expression (without spaces): ";
    cin>>exp;
    infixToPostfix(exp);
}
