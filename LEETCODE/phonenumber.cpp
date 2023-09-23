#include<bits/stdc++.h>
using namespace std;

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";


        vector<string>ans;
        if(digits.size()==1)
        {
            char c=digits[0];
            string s=mp[c];
            for(int i=0;i<s.size();i++)
            {
                string p="";
                p+=s[i];
                ans.push_back(p);
            }

        }
        else
        {
            for(int i=0;i<digits.size()-1;i++)
            {
                for(int j=i+1;j<digits.size();j++)
                {
                    string s1=mp[digits[i]];
                    string s2=mp[digits[j]];

                    for(int p=0;p<s1.size();p++)
                    {
                        for(int q=0;q<s2.size();q++)
                        {
                            string s="";
                            s.push_back(s1[p]);
                            s.push_back(s2[q]);
                            ans.push_back(s);
                        }
                    }
                }
            }
        }
        return ans;

    }
    int main()
    {
        string s="24";
        vector<string>ans=letterCombinations(s);
        for(auto x:ans)
        {
            cout<<x<<" ";

        }
    }
