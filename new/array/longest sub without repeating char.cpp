#include<bits/stdc++.h>

using namespace std;

int solve(string str) 
{
    int left=0;
    int len=INT_MIN;
    unordered_map<char,int> mp;
    for(int i=0;i<str.size();i++)
    {
        if(mp.find(str[i])!=mp.end())
           left=max(left,mp[str[i]]+1);
        len=max(len,i-left+1);
        mp[str[i]]=i;
    }
    return len;
}

int main() {
  string str = "abcaabcdba";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}