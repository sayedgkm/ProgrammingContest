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
#define        N                               100000
#define        M                               100000
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
ll bigmod(ll b,ll p){
   if(p==0) return 1;
   if(p%2==0){
    ll ret=bigmod(b,p/2);
     return (ret%M*ret%M)%M;
   }
   else
     return (b%M*bigmod(b,p-1)%M)%M;
}
int main()
{
    string s;
    cin>>s; vector<int>v;
    ll number=(s[0]-'0')*10000+(s[2]-'0')*1000+(s[4]-'0')*100+(s[3]-'0')*10+(s[1]-'0');
    ll ans=bigmod(number,5)%M;
     while(ans){
        v.pb(ans%10);
        ans/=10;
     }
     for(int i=0;i<5-v.size();i++)
           cout<<"0";
     for(int i=v.size()-1;i>=0;i--)
           cout<<v[i];
      return 0;
}