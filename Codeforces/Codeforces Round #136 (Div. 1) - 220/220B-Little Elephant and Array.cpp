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
vector<int> v;
int ar[N],br[N];int ans[N]; int check[N]; pii qu[N];
int main()
{
    int n,q;
    cin>>n>>q;
    f(i,1,n+1){
        take1(ar[i]);
        if(ar[i]<=n)
        br[ar[i]]++;
    }
    f(i,1,n+1){
       if(br[i]>=i)
        v.pb(i);
    }
    f(i,0,q)
       cin>>qu[i].ff>>qu[i].ss;
   f(j,0,v.size()){
     int val=v[j];
      f(i,1,n+1){
          check[i]=check[i-1];
          if(ar[i]==val)
              check[i]++;
        }
       // cout<<val<<" ";
       // f(i,1,n+1)  cout<<check[i]<<" ";
       // puts("");
        f(i,0,q){
           ans[i]+=check[qu[i].ss]-check[qu[i].ff-1]==val;

        }

   }
   f(i,0,q)
    cout<<ans[i]<<endl;
      return 0;
}