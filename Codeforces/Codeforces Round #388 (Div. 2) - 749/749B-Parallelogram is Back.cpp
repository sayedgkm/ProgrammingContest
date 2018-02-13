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
set<int> a,b;
int ar[N];char s[N];
int dis(int x1,int y1,int x2,int y2){
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
bool check(int x,int y,int x1,int y1,int x2,int y2,int x3,int y3){

    int ab=dis(x,y,x1,y1);
    int cd=dis(x2,y2,x3,y3);
    if(ab!=cd) return 0;
    int ad=dis(x,y,x3,y3);
    int bc=dis(x1,y1,x2,y2);
     if(ad!=bc) return 0;
    int nx1=x+x2;
    int nx2=x1+x3;
    int ny1=y+y2;
    int ny2=y1+y3;
    if(nx1==nx2&&ny1==ny2) return 1;
    return 0;

}
int main(){
     //freopen("out.txt","w",stdout);
   ios_base::sync_with_stdio(false);
   cin.tie(0);
     int x1,y1,x2,y2,x3,y3;
     cin>>x1>>y1>>x2>>y2>>x3>>y3;
      vector<pii> v;
     for(int i=-3000;i<=3000;i++){
        for(int j=-3000;j<=3000;j++){
            if(check(i,j,x1,y1,x2,y2,x3,y3)||check(i,j,x3,y3,x1,y1,x2,y2)||check(i,j,x2,y2,x3,y3,x1,y1))
                 v.pb({i,j});
        }
     }
   cout<<v.size()<<endl;
   for(auto it: v) cout<<it.ff<<" "<<it.ss<<endl;

return 0;
}