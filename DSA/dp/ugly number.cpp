#include<bits/stdc++.h>

using namespace std;
int main() {
   int n = 150;
   set<long long int> s;
   s.insert(1);
   n--;
   while(n--)
   {
       auto it=s.begin();
       long long int ugly=*it;
       s.insert(ugly*2);
       s.insert(ugly*3);
       s.insert(ugly*5);
       s.erase(it);
   }
   cout<<*s.begin();
   return 0;
} 