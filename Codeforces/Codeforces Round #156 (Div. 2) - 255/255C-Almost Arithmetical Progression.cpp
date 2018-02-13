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
#define        N                               100010
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
int ar[N],x[N*10],br[N*10];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n=nxt(); int cs=1;
    for(int i=1;i<=n;i++) {
         ar[i]=nxt();
    }
    int mx=1;
     for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ar[j]==ar[i]){
                for(int k=j-1;k>=1;k--){
                     if(ar[k]==ar[i]) break;
                     if(!x[ar[k]])
                        br[ar[k]]+=2;
                      x[ar[k]]=1;
                     mx=max(br[ar[k]]+1,mx);
                }
                for(int k=j-1;k>=1;k--){
                     if(ar[k]==ar[i]) break;
                   x[ar[k]]=0;
               }
            }
        }

        for(int j=n; ;j--){
             if(ar[j]==ar[i]) break;
             if(!x[ar[j]])
             br[ar[j]]++;
             x[ar[j]]=1;
             mx=max(mx,br[ar[j]]+1);
        }
        for(int j=i;j<=n;j++) br[ar[j]]=0,x[ar[j]]=0;
        int c=0;
        for(int j=i;j<=n;j++) if(ar[j]==ar[i]) c++;
        mx=max(mx,c);
     }
     cout<<mx<<endl;
return 0;
}