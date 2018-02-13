// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
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
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
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
int ar[105][105];
struct ab{
 int q,r,c,data;
};
int main()
{
    ///ios_base::sync_with_stdio(0); cin.tie(0);
    /// freopen("out.txt","w",stdout);
    vector<ab>v;
    int n=nxt();
    int m=nxt();
    int q=nxt();
    f(i,0,q){
      int a=nxt();
      if(a==1||a==2){
            int r=nxt();
            ab mm;
            mm.q=a;
            mm.r=r;
            mm.c=0;
            mm.data=0;
            v.pb(ab(mm));
      } else if(a==3){
          int r=nxt(),c=nxt(),x=nxt();
          ab mm;
            mm.q=a;
            mm.r=r;
            mm.c=c;
            mm.data=x;
        v.pb(ab(mm));
      }
    }
    for(int i=v.size()-1;i>=0;i--){

        if(v[i].q==1){
                int x=v[i].r;
            for(int i=m;i>1;i--)
               swap(ar[x][i],ar[x][i-1]);

        } else if(v[i].q==2){
               int x=v[i].r;
            for(int i=n;i>1;i--)
               swap(ar[i][x],ar[i-1][x]);

        }
        else if(v[i].q==3){
            ar[v[i].r][v[i].c]=v[i].data;
        }

    }
   f(i,1,n+1){
     f(j,1,m+1)
        printf("%d ",ar[i][j]);
        printf("\n");
   }

      return 0;
}