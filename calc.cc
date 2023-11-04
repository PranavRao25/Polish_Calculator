#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
#include <cmath>

using namespace std;

/* string exp
 * exp : d1 d2 o
 * 1. extract tokens
 * 2. convert into their data types
 * 3. push
 */

vector<string> process(string exp) {
	vector<string> token;
	int i=0;
	string s="";
	while(i<exp.length()) {
		if(exp[i]!=' ')	s +=exp[i];
		else {	
			token.push_back(s);
			s = "";
		}
		i++;
	}
	token.push_back(s);
	
	return token;
}

bool isDigit(string s) {
	for(int i=0;i<s.length();i++) {
		if(int(s[i])<48 || int(s[i])>57) {
			return false;
		}
	}
	return true;
}

int operate(string& s, int a,int b) {
	char ch = s[0];
	switch(ch) {
		case '*':	return a*b;
		case '+':	return a+b;
		case '-':	return a-b;
		case '^':	return pow(b,a);
		case '/':	if(b==0)	return INT_MIN;
				else 		return (a/b);
		default:	break;
	}
	return INT_MAX;
}

int result(string exp) {
	vector<string>token = process(exp);
	stack<int>stack;
	string s;
	int a,b,val;

	// 2 5 * => 10 
	for(int i=0;i<token.size();i++) {
		s = token[i];
		if(isDigit(s)) {
			stack.push(stoi(s));
		}
		else {
			if(s.length()>1) {
				cout << "Illegal Operation" << endl;
				return INT_MIN;
			}
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();

			val = operate(s,a,b);
			if(val==INT_MIN) {
				cout << "Divide by 0 attempt" << endl;
				return val;
			}
			else if(val==INT_MAX) {
				cout << "Illegal Instruction" << endl;
				return INT_MIN;
			}
			stack.push(val);
		}
	}

	if(stack.size()==1)	return stack.top();
	else	return INT_MIN;
}

int main() {
	string exp;
	cout << "Enter expression" << endl;
	getline(cin,exp);
	int ans = result(exp);

	if(ans!=INT_MIN)	cout << ans << endl;
	else	cout << endl;
}
