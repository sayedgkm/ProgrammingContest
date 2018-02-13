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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
char s[1005][1005];
int k ;
int level[1005][1005];
int vis[1005][1005];
int n ;
int m;
int mark[4][1005][1005];

int bfs(int x,int y,int ex,int ey) {

   queue<pii> q;
   q.push(make_pair(x,y));
    vis[x][y]= 0;
    while(!q.empty()) {

         pii first =q.front();
         if(first.ff==ex&&first.ss==ey) return level[ex][ey];
         q.pop();
         FOR(i,0,4) {
             int nx =first.ff;
             int ny =first.ss;
           FOR(j,0,k) {
              nx+=dx[i];
              ny+=dy[i];
              if(nx<0||nx>=n||ny<0||ny>=m||s[nx][ny]=='#') {
                  break;
              }
              if(vis[nx][ny]&&level[nx][ny]==level[first.ff][first.ss]) break;
                if(!vis[nx][ny]) {
                      level[nx][ny]+=level[first.ff][first.ss]+1;
                      vis[nx][ny] = 1;
                       q.push(make_pair(nx,ny));
                }

           }

        }

    }
 return -1;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
  freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     n = nxt();
     m = nxt();
     k = nxt();

    FOR(i,0,n) scanf("%s",s[i]);

     int x= nxt();
     int y = nxt();
     int ex = nxt();
     int ey =nxt();
     printf("%d\n",bfs(x-1,y-1,ex-1,ey-1));


return 0;
}