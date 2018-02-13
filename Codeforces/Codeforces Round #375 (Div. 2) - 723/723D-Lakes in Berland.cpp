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
 char grid[100][100];
 int n,m,k;
 int lake=1;
 int ocean=0;
 int c=0;
 int color[100][100];
 int visited[100][100];
 void dfs(int i,int j){
       if(i==0||j==0||i==n-1||j==m-1) ocean=1;
          c++;
          visited[i][j]=1;
          for(int k=0;k<4;k++){
              int x=dx[k]+i;
              int y=dy[k]+j;
              if(x<0||x>=n||y<0||y>=m||visited[x][y]||grid[x][y]=='*') continue;

              dfs(x,y);

          }


 }

 int type[100][100];
 void dfs1(int i,int j,int number){
          type[i][j]=number;
          color[i][j]=1;
          for(int k=0;k<4;k++){
              int x=dx[k]+i;
              int y=dy[k]+j;
              if(x<0||x>=n||y<0||y>=m||color[x][y]||grid[x][y]=='*') continue;

              dfs1(x,y,number);

          }


 }
 void Fill(int number){
    f(i,0,n){
      f(j,0,m) if(type[i][j]==number) grid[i][j]='*';
     }

 }
 vector<pii>v;
 int main(){

      n=nxt(),m=nxt(),k=nxt();
      f(i,0,n) scanf("%s",grid[i]);

      f(i,0,n) f(j,0,m){

          if(grid[i][j]=='.'&&!visited[i][j]){
               dfs(i,j);
                  //cout<<i<<" "<<j<<" "<<ocean<<endl;
               if(!ocean){

                   v.pb(pii(c,lake));

                   dfs1(i,j,lake);
                   lake++;
               }

            ocean=0;
            c=0;
          }


      }
     // for(int i=0;i<n;i++){ for(int j=0;j<m;j++) cout<<type[i][j]<<" ";
     // puts("");
    //  }
      sort(v.begin(),v.end());
      int x=0;
      lake--;
      f(i,0,v.size()){
          if(lake==k) break;
         Fill(v[i].ss);
         x+=v[i].ff;
         lake--;
        }
        cout<<x<<endl;
        f(i,0,n) printf("%s\n",grid[i]);
 return 0;
}