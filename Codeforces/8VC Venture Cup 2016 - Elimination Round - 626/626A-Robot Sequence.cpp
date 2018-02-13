// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
int main()
{
   string s;
int n;
cin>>n;
cin>>s; int ans=0;
   f(i,0,n){
     int x=0,y=0;
     f(j,i,n){
      if(s[j]=='U') x--;
      if(s[j]=='D') x++;
      if(s[j]=='R') y++;
      if(s[j]=='L') y--;
       if(!x&&!y) ans++;

     }

   }
   cout<<ans<<endl;
      return 0;
}