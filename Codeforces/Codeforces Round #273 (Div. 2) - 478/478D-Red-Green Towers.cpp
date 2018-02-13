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
int ar[N];
int height;
int go(int x) {
    for(int i = 0;; i++) {

        if((i*(i+1))/2>x) return i - 1;
    }

}
int red,green;
//ll go(int pos,int g){
//
//     if(pos>height) return 1 ;
//        int x = pos-1;
//     int tot = (x*(x+1))/2;
//     int r =tot- (green-g);
//     r = red- r;
//     ll res = 0 ;
//     if(g>=pos) res+= go(pos+1,g-pos) ;
//     if(r>=pos) res+= go(pos+1,g) ;
//     return res;
//}
ll dp[2][N];
ll go(int pos,int g) {
    //FOR(i,0,g+1)
    dp[0][0] = 1 ;
    ll mx = 0 ;
  for(int i = 1;i<= pos;i++) {
           int p = i&1;
        for(int j = 0;j<=g;j++) {
              dp[p][j] = 0;
            int x = i-1;
            int tot = (x*(x+1))/2;
            int r = tot- (j) ;
                r= red - r;
              if(j>=i) {
                  dp[p][j]+=dp[p^1][j-i];
              }
              if(r>=i) dp[p][j]+=dp[p^1][j];
              if(dp[p][j]>=M) dp[p][j] -= M;
        }
    }
   // return dp[pos%2][];
    ll ans = 0 ;
    FOR(i,0,g+1) {
       ans+=dp[pos&1][i];
       if(ans>=M) ans-=M;
    }

  return ans ;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
      red = nxt();
      green = nxt();
      height = go(red+green) ;
      cout<<go(height,green) <<endl;

return 0;
}