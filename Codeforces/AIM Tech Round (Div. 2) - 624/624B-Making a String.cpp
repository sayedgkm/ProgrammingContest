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
map<ll,int> mp;
ll ar[50];
int main()
{
    int n;
    cin>>n;
    f(i,0,n){
      cin>>ar[i];
    }
    sort(ar,ar+n);
    reverse(ar,ar+n);
    ll ans=0;
    f(i,0,n){
      if(!mp[ar[i]]){

         mp[ar[i]]=1;
         ans+=ar[i];

      }
      else {
        for(ll j=ar[i];j>=0;j--){
             if(!mp[j]){
                mp[j]=1;
                ans+=j;
                break;
             }

         }

      }

    }
    cout<<ans<<endl;
      return 0;
}