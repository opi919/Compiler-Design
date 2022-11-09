#include<bits/stdc++.h>
#include<iostream>

using namespace std;

bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    return false;
}

bool isOperand(char ch){
    if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
        return true;
    return false;
}

int precedence(char ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}

bool checkPrecedence(char ch1, char ch2){
    int p1 = precedence(ch1);
    int p2 = precedence(ch2);
    if(p1 >= p2)
        return true;
    return false;
}

string convert(string infix){
    stack <char> s;
    string postfix;

    infix+=")";
    s.push('(');

    for(int i=0;i<infix.length();i++){
        char ch = infix[i];

        if(ch=='('){
            s.push(ch);
        }
        else if(isOperand(ch)){
            postfix+=ch;
        }
        else if(isOperator(ch)){
            while(!s.empty() && checkPrecedence(s.top(),ch)){
                postfix+=s.top();
                s.pop();
            }
            s.push(ch);
        }
        else if(ch==')'){
            while(!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
    }
    return postfix;
}

int main(){
    string infix, postfix;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    postfix = convert(infix);
    cout<<"Postfix expression: "<<postfix<<endl;
}