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
#define        pii                             pair<ll,ll>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
pii ar[N];
int main()
{
    int n;
    cin>>n;ll mx=0;
    f(i,0,n){
     cin>>ar[i].ff>>ar[i].ss;
    }
    f(i,0,n){
      f(j,0,n){
        if(i!=j){
            ll p=ar[i].ff-ar[j].ff;
            ll q=ar[i].ss-ar[j].ss;
            mx=max(mx,max(abs(p),abs(q)));
        }


      }

    }

    cout<<(mx*mx)<<endl;
      return 0;
}