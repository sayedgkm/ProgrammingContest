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
int ar[]={2,3,5,7};
int main()
{
ll n;
  cin>>n;ll res=0;
   for(int i=0;i<4;i++) res+=n/ar[i];
   f(i,0,4) f(j,i+1,4) res-=n/(ar[i]*ar[j]);
   f(i,0,4) f(j,i+1,4) f(k,j+1,4) res+=n/(ar[i]*ar[j]*ar[k]);
     res-=n/(ar[0]*ar[1]*ar[2]*ar[3]);
     cout<<n-res<<endl;
    return 0;
}