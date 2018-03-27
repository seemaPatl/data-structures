// To reverse a string using the stl stack

#include<iostream>
#include<stack>
#include<string>
using namespace std;
/*

  Objective         : To reverse the string.
  Input Parameters  : s - string
  Return Value      : reversed string.
  Approach          : using the stl stack.
 */



int main()
{
	stack<char> stk;// stack initialisation
	string s;
	cout<<"enter a string:";
	getline(cin,s);
	for(int i=0;i<s.size();i++)// psuhing the string into the stack st
	{
		stk.push(s[i]);
	}
	cout<<"reverse of a string is:";
	while(!stk.empty())
{
	cout<<stk.top();// printing reverse string
	stk.pop();
	}	
	return 0;
}

