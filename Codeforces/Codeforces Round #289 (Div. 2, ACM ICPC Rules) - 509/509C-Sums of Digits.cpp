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
string prv;
char path[400];
int dp[400][400][3];
int go(int pos,int sum,int isbig) {
    if(pos>=prv.size()) {
        if(sum!=0) return 0 ;
        if(isbig) return 1 ;
        return 0;
    }
    int &t = dp[pos][sum][isbig];
     //debug(t);
    if(t!=-1) return t;
    t =0;
    int start =isbig?0:prv[pos]-'0';
    if(pos==0) {
        if(start==0) start++;
    }
    for(int i=start;i<=9;i++) {
         if(i<=sum){
          path[pos] = i+'0';
         t = go(pos+1,sum-i,isbig|i>prv[pos]-'0');
          if(t) return t;
         }
    }
    return t;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
//          prv = "0000000000000000";
//          SET(dp);
//          go(0,139,0);
//          cout<<path<<endl;
   prv = "0";
     int n = nxt();
     while(n--) {
          int t = nxt();
          bool f = 0;
            SET(dp);
          while(!go(0,t,f)) {
            SET(dp);
            CLR(path);
            prv = "0"+prv;
           // debug(prv)
            f= 1;
          }
           printf("%s\n",path);
           prv = path;
     }

return 0;
}