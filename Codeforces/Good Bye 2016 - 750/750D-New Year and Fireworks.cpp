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
int table[310][310];
int ar[100];
struct info{
  int x,y,dir,in;
  info(int a,int b, int c,int d){
       x=a,y=b,in=c,dir=d;
  }
};
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={1,  0,-1,-1,-1,0,1,1};
int fx[]={1,0,-1,-1,-1,0,1,1};
int fy[]={1,1,1,0,-1,-1,-1,0};
bool visited[310][310][32][8];
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
    for(int i=1;i<=n;i++) ar[i]=nxt();

    int x=155;int y=155;
    for(int i=1;i<=ar[1];i++){
           y++;
          table[x][y]=1;
    }
    queue<info> q;
    q.push(info(x,y,1,0));
    //visited[x][y][1][0]=1;
    while(!q.empty()){
    info temp=q.front();
         q.pop();
         if(temp.in==n) break;
if(visited[temp.x][temp.y][temp.in][temp.dir]){
       // puts("b");
    continue;
}
visited[temp.x][temp.y][temp.in][temp.dir]=1;

       int t=temp.in;
       t++;
       int dir=temp.dir;
       int x=temp.x;
       int y=temp.y;
       for(int i=0;i<ar[t];i++){
            x+=dx[dir];
            y+=dy[dir];
            table[x][y]=1;
       }
        q.push(info(x,y,t,(dir+1)%8));
        x=temp.x;
        y=temp.y;
       for(int i=0;i<ar[t];i++){
            x+=fx[dir];
            y+=fy[dir];
            table[x][y]=1;
       }
        q.push(info(x,y,t,dir-1==-1?7:dir-1));

  }
  int c=0;
  for(int i=0;i<310;i++) for(int j=0;j<310;j++) if(table[i][j]) c++;
  cout<<c<<endl;


return 0;
}