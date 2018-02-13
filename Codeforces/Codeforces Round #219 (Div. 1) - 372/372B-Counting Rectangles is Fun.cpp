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
#define        inf                              (1e9)+1000
#define        eps                             1e-9
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
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<"|";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[41][41];
char s[50];
int query[41][41][41][41];

struct twod{
    int mat[41][41];
    void init(int n,int m){ /// 1 based index
    FOR(i,1,n+1) FOR(j,1,m+1){
         mat[i][j]=ar[i][j];
         mat[i][j]+=mat[i][j-1];
        }
     FOR(i,1,m+1) FOR(j,1,n+1){
       mat[j][i]+=mat[j-1][i];
        }
    }
   ll getsum(int x1,int y1,int x2,int y2){
      return mat[x2][y2]+mat[x1-1][y1-1]-mat[x2][y1-1]-mat[x1-1][y2];
    }
}S;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

     int n = nxt();
     int m = nxt();
     int k = nxt();
     for(int i = 1;i<=n;i++) {
         scanf("%s",s);
        for(int j = 1;j<=m;j++) {
             ar[i][j] = s[j-1]-'0';
        }
     }
     S.init(n,m);

     for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            for(int k = i ;k<=n;k++) {
                for(int l = j;l<=m;l++) {
                    query[i][j][k][l]+= (S.getsum(i,j,k,l)==0);
                //debug(i,j,k,l,query[i][j][k][l]);
                     query[i][j][k][l]+=query[i][j][k][l-1];
                }
            }
        }
     }
     for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            for(int l = j;l<=m;l++){
                for(int k = i;k<=n;k++){
                    query[i][j][k][l]+=query[i][j][k-1][l];
                }
            }
        }
     }
     while(k--) {

        int a = nxt();
        int b = nxt();
        int c = nxt();
        int d = nxt();
        ll ans = 0;
        for(int i  = a;i<=c;i++) {
            for(int j = b;j<=d;j++) {
                ans+=(ll)query[i][j][c][d];
            }
        }
        printf("%lld\n",ans);

     }

    return 0;
}