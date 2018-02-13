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
int ar[105][105];
int mx[105][105];
int go(int x,int t) {
   int mx = 0;
    int sum = 0 ;
  FOR(i,0,t+1) {
     int c = i;
      if(i) sum+=ar[x][i] ;
       int last = ar[x][0];
         int tot = 0 ;
       for(int j = last;c<t ;j--,c++) {
            tot+=ar[x][j] ;
       }
      mx = max(mx,tot+sum);
  }
  return mx;
}
int dp[105][10005] ;
int n;
int come(int pos,int k) {
//    debug(pos) ;
//    debug(k) ;
    if(k==0) return 0 ;
    if(pos>n) return -inf ;
    int &res = dp[pos][k]  ;
   if(res!=-1) return res;
   res = 0 ;
  FOR(i,0,ar[pos][0]+1) {
      if(k>=i) res=max(res,come(pos+1,k-i) + mx[pos][i]);
  }
  return res;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
      n = nxt();
      int m = nxt();
      FOR(i,1,n+1) {
         int x = nxt();
         ar[i][0] = x;
         FOR(j,1,x+1) ar[i][j] = nxt();
      }

      FOR(i,1,n+1) {
          FOR(j,1,ar[i][0]+1) {
             mx[i][j] = go(i,j) ;
          }
      }
     // debug(mx[2][0]) ;
      SET(dp) ;
      printf("%d\n",come(1,m));

return 0;
}