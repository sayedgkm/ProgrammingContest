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
map<string,ll> mp,mp1;
int main()
{
    int n;
    cin>>n; ll mx=0;
            string p;
            string s[1005];ll point [1005]={0};

   f(i,0,n){
       cin>>s[i]>>point[i];
        mp[s[i]]+=point[i];

    }
    f(i,0,n){
      mx=max(mx,mp[s[i]]);
    }
    //cout<<mx<<endl;
    f(i,0,n){
       if(mp[s[i]]==mx){
          mp1[s[i]]+=point[i];
           if(mp1[s[i]]>=mx){
            cout<<s[i]<<endl;return 0;
           }
       }
      else mp1[s[i]]+=point[i];
    }
   // cout<<p<<endl;
      return 0;
}