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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
vector<int>v; ll n;
ll check(int n){
   ll c=0;
    while(n){
        c+=n/5;
        n/=5;
    } return c;
}
void go(int low,int hi){
    if(low>=hi) return;
      int mid=(low+hi)>>1;
      int val=check(mid);
      if(val==n){
          v.pb(mid);
          go(low,mid);
          go(mid+1,hi);
        }
      else if(val>n)
         go(low,mid);
      else go(mid+1,hi);

}
int main()
{

    cin>>n;
    go(1,100000000);
    cout<<v.size()<<endl;
     sort(v.begin(),v.end());
       f(i,0,v.size()) cout<<v[i]<<" ";
       puts("");
      return 0;
}