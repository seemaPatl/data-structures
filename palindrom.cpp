//To check whether the input string is palindrom or not.
/*
	Objective:To check of the input string is palindrom or not.
	Input parameter:str-string.
	Return value:palindrom or not -(boolean return value).
	approach: using a stl queue and stl stack.
	
*/
#include <iostream>
#include<stack>
#include<queue>

using namespace std;

int main()
{
    int len;
    string str;
    stack<char>s;
    queue<char>q;
    cout<<"Enter the string: ";
    cin>>str;
    len=str.length();
    
    for(int i=0;i<len;i++)
    {
		//to push string into the stack and queue.
        s.push(str[i]);
        q.push(str[i]);
    }
    bool flag=1;
    while(!s.empty()&&!q.empty())
    {	//to pop and compare the elements of the stack and queue to check if palindrom or not.
        if(s.top()!=q.front())
        {
            flag=0;
            break;
        }
        else
        {
            s.pop();
            q.pop();
        }
    }
    if(flag==1 &&(!s.empty()&&!q.empty()))
    {
        cout<<"\n not palindrom";
    }
    else
    {
        cout<<"palindrom";
    }
    return 0;
}
