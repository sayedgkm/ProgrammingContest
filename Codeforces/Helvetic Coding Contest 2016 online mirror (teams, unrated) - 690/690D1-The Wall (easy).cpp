//==========================================================================
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
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
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
char s[105][105];
bool color[105][105];
void dfs(int i,int j,int n,int m){
     color[i][j]=1;
   for(int k=0;k<4;k++){
        int x=i+dx[k];
        int y=j+dy[k];
        if(x<0||x>=n||y<0||y>=m||color[x][y]) continue;
        if(s[x][y]=='B')
          dfs(x,y,n,m);
    }

}
int main(){
     // freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   // cin.tie(0);
   int n=nxt(),m=nxt();
   f(i,0,n) scanf("%s",s[i]);
   int ans=0;
   for(int i=0;i<n;i++){
     for(int j=0;j<m;j++){
        if(!color[i][j]&&s[i][j]=='B'){
            dfs(i,j,n,m);
            ans++;

        }
      }
   }
   printf("%d\n",ans);

return 0;
}