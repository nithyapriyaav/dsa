#include<bits/stdc++.h>


using namespace std;
int main() {
  int V = 49;
  vector < int > res;
  int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
  int n = 9;
  int count=0;
  for(int i=n-1;i>=0;i--)
  {
      while(V>=coins[i])
      {
          V-=coins[i];
          count++;
          res.push_back(coins[i]);
      }
  }
  cout<< "Min num of coins "<<count<<endl;;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  return 0;
}