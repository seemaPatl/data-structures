#include<iostream>
#include<stdio.h>
#include<stack>
#include<string>

using namespace std;

bool checkOperator(char opr) {
    /*
     objective : check whether the character is an operator
     input : character at current index of string
     return value : true if operator otherwise false
     approach : using if else to check
    */
    if(opr=='+' || opr=='-' || opr=='*' || opr=='^' || opr=='/') {
        return true;
    }
    return false;
}

char precedence(char opr) {
    /*
     objective : calculating precedence of the operator
     input : operator
     return value : precedence according to operator
     approach : using if else to calculate
     */
    if(opr == '+' || opr == '-') {
        return '1';
    }
    else if(opr == '*' || opr == '/') {
        return '2';
    }
    else {
        return '3';
    }
}
void infix_to_postfix(string str)  {
    /*
     objective : converting to postfix expresstion
     input : infix string
     return value : none
     approach : using function precedence and check operator
    */
    int length = str.length();
    stack <char> object;
    //printing Postifix expression
    cout << "\nPostifix Expression\t\t:\t";
    for ( int i = 0; i < length; ++i) {
        if(str[i]=='(') {
            object.push(str[i]);
        }
        else if(str[i]==')') {
            while( !object.empty() && object.top()!='('){
                cout<<object.top();
                object.pop();
            }
            object.pop();
        }
        else {
            if( object.empty() )
                object.push(str[i]);
            else if(  precedence(str[i]) > precedence(object.top()) )
                object.push(str[i]);
            else{
                while( !object.empty() && object.top()!='(' && precedence(str[i]) <= precedence(object.top()) ){
                    cout<<object.top();
                    object.pop();
                }
                object.push(str[i]);
            }
        }
    }
    while(!object.empty()) {
        cout<<object.top();
        object.pop();
    }
}


int main() {
    string str;
    cout << "\nEnter Infix Expression\t:\t";
    cin >> str;
    infix_to_postfix(str);
    cout << endl;
    return 0;
}