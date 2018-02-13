//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        All(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
ll ok(ll man,ll k){
    if(man<=0) return 0;
    ll sum=0;
    if(man<=k){
        sum+=(k*(k+1))/2;
        ll baki=k-man;
        sum-=baki*((baki+1))/2;
    } else {
       sum=man-k;
       sum+=(k*(k+1))/2;
    }
    //cout<<man<<" "<<k<<" "<<sum<<endl;
   return sum;
}
ll n;
bool go(ll mid,ll m,ll k){
   ll sum=mid;
     sum+=ok(n-k,max(mid-1,1LL));
     sum+=ok(k-1LL,max(1LL,mid-1));
    // cout<<mid<<" "<<sum<<endl;
   return sum<=m;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     ll m,k;
     n=lxt(),m=lxt(),k=lxt();
     ll b=1;
     ll e=1e10;
     while(b<=e){
         ll mid=(b+e)>>1;
         if(go(mid,m,k)) b=mid+1;
         else e=mid-1;
     }
   cout<<b-1<<endl;
return 0;
}