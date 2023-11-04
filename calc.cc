#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>
#include <cmath>
#include <iomanip>

using namespace std;

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

double operate(string& s, double a,double b) {
	char ch = s[0];
	switch(ch) {
		case '*':	return b*a;
		case '+':	return b+a;
		case '-':	return b-a;
		case '^':	return pow(b,a);
		case '/':	return (b==0)?(INT_MIN):(a/b);
		default:	break;
	}
	return INT_MAX;
}

double result(string exp) {
	vector<string>token = process(exp);
	stack<double>stack;
	string s;
	double a,b,val;

	for(int i=0;i<token.size();i++) {
		s = token[i];
		try {
			stack.push(stod(s));
		}
		catch (...) {
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
	else {
		cout << "Invalid Expression" << endl;
		return INT_MIN;
	}
}

int main() {
	string exp;

	cout << "Enter expression" << endl;	
	while(getline(cin,exp)) {
		double ans = result(exp);

		if(ans!=INT_MIN)	cout << setprecision(5) <<ans << endl;
		else			break;
		cout << "Enter expression" << endl;	
	}
}
