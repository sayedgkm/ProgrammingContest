#include<bits/stdc++.h>
using namespace std;
int ar[300000+10];
int main(){

  int n;
  cin>>n;
  int mn=(int)1e9+(int)1e5;
  for(int i=1;i<=n;i++)
    cin>>ar[i];
    sort(ar+1,ar+1+n);

  cout<<ar[(n+1)/2];

}