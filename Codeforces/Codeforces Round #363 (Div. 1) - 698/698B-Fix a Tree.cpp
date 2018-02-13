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

vector<pii> v;
int ar[N];
int path[N];
void root(int n) {
    for(int i=0; i<=n; i++)
        path[i]=i;
}
int findUnion(int x) {      ///Find root of x
    if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
void mergeUnion(int x,int y) {
    path[findUnion(x)]=findUnion(y); ///making same root of both x and y
}
bool sameset(int x,int y) { ///check two elements are in same set or not
    return findUnion(x)==findUnion(y);
}

int main(){
 // freopen("out.txt","w",stdout);
 //ios_base::sync_with_stdio(false);
 // cin.tie(0);
 root(N-1);
 int n = nxt(); int self=-1;
 for(int i=1;i<=n;i++){
          int a=nxt();
          ar[i]=a;
         if(sameset(i,a)){
                if(i==a&&self==-1) {
                     self=i;
                     continue;
                }
             v.pb({i,a});
         }  else mergeUnion(i,a);
  }
   int ans=0;
    if(!v.size()) goto ok;

   if(self==-1){
     self=v.back().ff;
      ar[self]=self;
      v.pop_back();
      ans++;
   }
  for(int i=v.size()-1;i>=1;i--){
    pii temp=v.back();
     v.pop_back();
    ar[temp.ff]=v.back().ss;
    ans++;
  }
    if(v.size()){
    ar[v.back().ff]=self;
     ans++;
    }
     ok:
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<ar[i]<<" ";

 return 0;
}