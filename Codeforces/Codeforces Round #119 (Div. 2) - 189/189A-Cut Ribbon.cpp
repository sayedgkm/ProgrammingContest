#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <string>

using namespace std;

int n,a[5];


int DP[4010];

int dp(int remlen){
   //cout<<remlen<<endl;
   if(remlen==0)
      return 0;
   if(DP[remlen]!=-1)
       return DP[remlen];
       //cout << remlen <<endl;

   for(int i=1;i<=3;i++){

       if(remlen-a[i]>=0){
//          cout<<"going for "<<a[i]<<endl;
          int x=dp(remlen-a[i]);
          if(x!=-2)
             DP[remlen]=max(DP[remlen],1+x);
       }
   }
   if(DP[remlen]==-1) DP[remlen]=-2;
   //DP[remlen]=max(0,DP[remlen]);
//   cout<<DP[remlen]<<endl;
   return DP[remlen];
}



int main(){

   memset(DP,-1,sizeof(DP));
   cin>>n;
   for(int i=1;i<=3;i++)
     cin>>a[i];

   sort(a+1,a+4);
   cout<<dp(n)<<endl;
   return 0;
}