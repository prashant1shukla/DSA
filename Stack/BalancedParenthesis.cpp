#include<bits/stdc++.h>
using namespace std;
bool BalPar(string s)
{
    stack<char>st;
    for(int i=0;i<s.size();i++)
    {
        if(st.empty()==true)
            st.push(s[i]);
        else if((st.top()=='('&&s[i]==')')||(st.top()=='{'&&s[i]=='}')||(st.top()=='['&&s[i]==']'))
            st.pop();
        else 
            st.push(s[i]);        
    }
    if(st.empty()==true)
        return true;
    else
    return false;
}
int main()
{
    string s ="{()}[]";
    if(BalPar(s))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}