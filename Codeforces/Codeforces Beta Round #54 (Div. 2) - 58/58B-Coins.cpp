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
ll ar[N];
int main()
{
    int n;
    cin>>n; vector<ll> v;
    v.pb(n);
    v.pb(1);
    for(int i=2; ;i++){
         if(n%i==0){
                v.pb(n/i);
              n/=i;
            i=1;
         }
         if(i>sqrt(n)) break;
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
            if(ar[v[i]]==0)
          cout<<v[i]<<" ";
           ar[v[i]]=1;
    }
      return 0;
}