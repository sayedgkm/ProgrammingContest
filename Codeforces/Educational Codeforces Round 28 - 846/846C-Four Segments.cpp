//====================================
//======================================
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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              1e9
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
ll ar[N];
pll subans[N];
ll sum[N];
ll getsum(int i,int j) {
    if(i>j) return 0 ;
   return sum[j] - sum[i-1];
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n = nxt();
       FOR(i,1,n+1) {
            ar[i] = lxt();
            sum[i] = sum[i-1] + ar[i];
       }
       for(int i = 1;i<=n;i++) {
            ll mx = -(ll)1e17;
            ll in = -1;
          for(int j = i; j<=n+1;j++) {
              ll temp = getsum(i,j-1)-getsum(j,n);
              if(temp>mx) {
                  mx = temp;
                  in = j;
              }
          }
//          debug(mx);
//          debug(in);
        subans[i]=make_pair(mx,in);
       }
            int a ,b, c;
            ll mx = -(ll)1e17;
      for(int i = 1;i<=n+1;i++) {
          for(int j = i; j<=n+1;j++) {
              ll temp = getsum(1,i-1)-getsum(i,j-1)+subans[j].ff;
//              debug(temp);
//              if(temp==6) {
//                  cout<<i<<" "<<j<<" "<<subans[j].ss<<endl;
//              }
              if(temp>mx) {
                  mx = temp;
                  a = i;
                  b = j;
                  c = subans[j].ss;
              }

          }

       }
       cout<<a-1<<" "<<b-1<<" "<<c-1<<endl;
return 0;
}