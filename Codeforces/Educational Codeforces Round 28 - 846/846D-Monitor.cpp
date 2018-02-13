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
#define        N                               505
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
ll ar[505][505];
struct twod{
    int mat[N][N];
    void init(int n,int m){ /// 1 based index
    FOR(i,1,n+1) FOR(j,1,m+1){
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
struct info{
int table[10][N];
int Log[N];
void RMQ_init(int n,int x) {
    for(int i=0; i<n; i++){
        table[0][i] = ar[x][i+1];
       // cout<<ar[x][i+1]<<" ";
    }
   // cout<<endl;
    for(int i=2; i<=n; i++) Log[i]=1+Log[i/2];
    for(int i =1; i<20; i++)
        for(int j=0; j+(1<<(i-1))<n; j++)
            table[i][j]=max(table[i-1][j],table[i-1][j+(1<<(i-1))]);  /// j+1<<(i-1) means shifting index
                                                                      /// at j+2^(i-1)
}

  int getmax(int i,int j) {
    int k = Log[j-i+1];
    return max(table[k][i],table[k][j-(1<<k)+1]);

  }
}st[N];
ll go(int x1,int y1,int x2,int y2) {
   int mx = -1;
   for(int i = x1;i<=x2;i++) {
      mx =max(mx, st[i].getmax(y1-1,y2-1));
   }
   return mx;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     FOR(i,0,N) FOR(j,0,N) ar[i][j] = -1,S.mat[i][j]=0;
      int  n = nxt();
      int m = nxt();
       int k = nxt();
       int q = nxt();
       for(int i = 1;i<=q;i++ ) {

           int x = nxt();
           int y = nxt();
           int t = nxt();
           S.mat[x][y] = 1;
           ar[x][y] = t;

       }
        // FOR(i,1,n+1) FOR(j,1,m+1) cout<<ar[i][j]<<" ";
       S.init(n,m);

       for(int i = 1;i<=n;i++) {
           st[i].RMQ_init(m,i);
       }
//       FOR(i,1,n+1) {
//          cout<<st[i].getmax(0,m-1)<<endl;
//       }
       ll ans = (ll)1e15;
       for(int i = 1;i+k-1<=n;i++) {

          for(int j = 1;j+k-1<=m;j++) {
                ll sum = S.getsum(i,j,i+k-1,j+k-1);
                // debug(sum);
                if(sum==k*k) {
                    ans = min(ans,go(i,j,i+k-1,j+k-1));

                }

          }

       }
   if(ans == (ll)1e15) puts("-1");
   else cout<<ans<<endl;
return 0;
}