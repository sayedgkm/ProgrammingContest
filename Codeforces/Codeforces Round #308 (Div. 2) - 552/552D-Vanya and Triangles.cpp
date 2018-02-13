//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************

pii point[N];
map<pii, int> mp;
ll cal(ll n,bool x){
    if(x)
 return n*(n - 1)*(n - 2) / (ll)6;
 else return n*(n-1)/(ll)2;
}
pii ok(pii a){
 if (a.ff<0) {
  a.ff = a.ff*-1;
  a.ss *= -1;
 }
 if(a.ff==0){
        if(a.ss<0) a.ss*=-1;
 }
 int gc = __gcd(abs(a.ff), abs(a.ss));
    if (gc != 0){
     a.ff /= gc;
     a.ss /= gc;
    }
 return a;
}
int main(){
 // freopen("out.txt","w",stdout);
 //ios_base::sync_with_stdio(false);
 // cin.tie(0);
  // cout<<gcd(0,5)<<gcd(5,0)<<endl;
 ll n = lxt();
 f(i, 0, n) point[i].ff = nxt(), point[i].ss = nxt();
 //puts("b");
 ll res = cal(n,1);
 for (int i = 0; i<n; i++){

  for (int j = i+1; j<n; j++){

    pii x;
    x.ff = point[i].ff - point[j].ff;
    x.ss = point[i].ss - point[j].ss;
    x = ok(x);
    mp[pii(x.ff, x.ss)]++;
               //cout<<mp[pii(x.ff,x.ss)]<<endl;
  }
  for (auto it = mp.begin(); it != mp.end(); it++)
  res -= cal((ll)it->ss,0);
  mp.clear();
 }
 //cout<<res<<endl;

 printf("%I64d\n", res);

 return 0;
}