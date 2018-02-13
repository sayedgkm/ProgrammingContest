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
struct info{
  int t,d,p,id;

  bool operator < (const info &st) const{
     return d<st.d;
  }
}ar[N];
int n;
ll dp[105][2005];
int path[105][2005];
ll go(int pos,int current) {
    if(pos>n ) return 0 ;
   if(dp[pos][current]!=-1) return dp[pos][current];
    ll res = 0 ;
    ll a=0,b=0;
    a= go(pos+1,current) ;
    if(current+ar[pos].t<ar[pos].d) b = go(pos+1,current+ar[pos].t) + ar[pos].p;
    if(b>a) {
        path[pos][current] = 1;
    }
    return dp[pos][current]=max(a,b) ;
}
vector<int> v;
void print(int pos,int current) {

     if(pos>n) return;
     if(path[pos][current]==1){
         v.pb(ar[pos].id);
           print(pos+1,current+ar[pos].t);
     } else {
        print(pos+1,current);
     }

}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     n = nxt();
    FOR(i,1,n+1) {
       ar[i].t = nxt();
       ar[i].d = nxt();
       ar[i].p = nxt();
       ar[i].id= i;
    }
    sort(ar+1,ar+n+1);
    SET(dp);
    cout<<go(1,0) <<endl;
    print(1,0) ;
    printf("%d\n",v.size());
    FOR(i,0,v.size()) printf("%d ",v[i]);
return 0;
}