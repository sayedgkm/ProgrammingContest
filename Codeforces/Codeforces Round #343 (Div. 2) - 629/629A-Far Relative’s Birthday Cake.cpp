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
char s[105][105];
int main()
{
     int n;
     take1(n);
     f(i,0,n) scanf("%s",s[i]);
     ll ans=0;
     f(i,0,n){
        int c=0;
        f(j,0,n){
          if(s[i][j]=='C') c++;
        }
        ans+=(c*(c-1))/2;
     }
     f(i,0,n){
        int c=0;
        f(j,0,n){
          if(s[j][i]=='C') c++;
        }
        ans+=(c*(c-1))/2;
     }
    cout<<ans<<endl;
      return 0;
}