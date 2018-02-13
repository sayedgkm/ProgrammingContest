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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                              1e-9
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
vector<int> bid[N];
set<pii> a,b;
int ar[N];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n=nxt();
  for(int i=0;i<n;i++){
      int a=nxt(),b=nxt();
      bid[a].pb(b);
  }
  for(int i=1;i<=n;i++){
     if(bid[i].size()){
        a.insert({bid[i].back(),i});
     }
  }
    b=a;
    int m=nxt();
    while(m--){

         int q=nxt();
         for(int i=0;i<q;i++){
             ar[i]=nxt();
             if(bid[ar[i]].size())
             a.erase({bid[ar[i]].back(),ar[i]});
         }
         if(a.size()==0){
             puts("0 0");
         } else if(a.size()==1){
             pii in=*--a.end();
             int i=in.ss;
             printf("%d %d\n",i,bid[i][0]);
         } else {

             auto it=a.end();
             it--;
             pii in=*it;
             int fs=in.ss;
             it--;
              in=*it;
             int val=bid[in.ss].back();
             int l=lower_bound(bid[fs].begin(),bid[fs].end(),val)-bid[fs].begin();
             printf("%d %d\n",fs,bid[fs][l]);

         }
         for(int i=0;i<q;i++){
                if(bid[ar[i]].size())
             a.insert({bid[ar[i]].back(),ar[i]});
         }
    }
return 0;
}