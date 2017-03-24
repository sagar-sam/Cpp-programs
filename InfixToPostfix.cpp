#include <iostream>
#include <stack>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    stack<char> st;
    string s,ans;
    cout << "enter infix string: " << endl;
    cin>>s;
    int n=s.length();
    int i=0;
    while(n--)
    {
        if(s[i]>='a'&&s[i]<='z')
        {
            if(s[i+1]>='a' && s[i+1]<='z')
            {
                cout<<"invalid expression"<<endl;
                return 0;
            }
            ans=ans+s[i];
        }
        else if(st.empty()||st.top()=='('||s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(st.top()!='(')
            {
                char ch=st.top();
                st.pop();
                ans=ans+ch;
            }
            st.pop();
        }
        else if(s[i]=='^')
        {
            st.push(s[i]);
        }
        else if(s[i]=='/')
        {
            while(!st.empty()&&(st.top()=='^' || st.top()=='*'))
            {
                    char ch=st.top();
                    st.pop();
                    ans=ans+ch;
            }
            st.push(s[i]);
        }
        else if(s[i]=='*')
        {
            while(!st.empty() && (st.top()=='^' || st.top()=='/'))
            {
                    char ch=st.top();
                    st.pop();
                    ans=ans+ch;
            }
            st.push(s[i]);
        }
        else if(s[i]=='+' )
        {
            while( !st.empty()&&(st.top()=='*' || st.top()=='/' || st.top()=='^' || st.top()=='-' || st.top()=='+'))
            {
                    char ch=st.top();
                    st.pop();
                    ans=ans+ch;
            }
            st.push(s[i]);
        }
        else if(s[i]=='-')
        {
            while( !st.empty()&&(st.top()=='*' || st.top()=='/' || st.top()=='^' || st.top()=='+' || st.top()=='-') )
            {
                    char ch=st.top();
                    st.pop();
                    ans=ans+ch;
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        char ch=st.top();
        st.pop();
        ans=ans+ch;
    }
    cout<<ans<<endl;
    return 0;
}

