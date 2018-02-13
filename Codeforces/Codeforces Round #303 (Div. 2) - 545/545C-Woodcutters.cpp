// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     100010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
pii ar[N];
int main()
{
  take1(n);f(i,0,n) cin>>ar[i].first>>ar[i].second;
  if(n==1){
    puts("1"); return 0;
  }
  int c=2; int x=0;
  f(i,1,n-1){
        if(x==0){
       if(ar[i].first-ar[i-1].first>ar[i].second){
         c++;x=0;continue;
       }
    }
    else
    {
        if(ar[i].first-x>ar[i].second){
         c++;x=0;
         continue;
       }

    }
    if(ar[i+1].first-ar[i].first>ar[i].second)
    {
        c++;x=ar[i].first+ar[i].second;

    }
    else x=0;
  }
  cout<<c<<endl;
return 0;
}