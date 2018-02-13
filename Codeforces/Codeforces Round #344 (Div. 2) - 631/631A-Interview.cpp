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
int ar[1005],br[1005];
int main()
{
    int n;ll ans=0;
    cin>>n;
    f(i,0,n) cin>>ar[i];
    f(i,0,n) cin>>br[i];
    f(i,0,n){
         ll p=ar[i];
         ll q=br[i];
        f(j,i+1,n){
            p=p|ar[j];
            q=q|br[j];
            ans=max(ans,p+q);
        }
        ans=max(ans,p+q);
    }
    cout<<ans<<endl;
      return 0;
}