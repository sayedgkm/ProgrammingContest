 /// Bismillahir-Rahmanir-Rahim
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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
struct EDGE{
 int u,v,cost;
}edge[N];
bool compare(EDGE a,EDGE b){
  return a.cost<b.cost;
 }
 int path[N];
void root(int n){
   for(int i=0;i<=n;i++)
       path[i]=i;
}
int findUnion(int x){
   if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
int port=0;int visited[N];int ans=0;
vector<pii> mp[N];
int mst(int n,int m){
    root(n);
    sort(edge,edge+m,compare);
  int c=0;
 for(int i=0;i<m;i++){
      int u=findUnion(edge[i].u);
      int v=findUnion(edge[i].v);
      if(u!=v){
          mp[edge[i].u].pb(pii(edge[i].v,edge[i].cost));
          mp[edge[i].v].pb(pii(edge[i].u,edge[i].cost));
        path[u]=v;
        c++;
        if(c==n-1) break;
      }

   }
}
void bfs(int s,int cost){
   visited[s]=1;
   queue<int>q;
   q.push(s);
   while(!q.empty()){
      s=q.front();
      q.pop();
      FOR(i,0,mp[s].size()){
        int t=mp[s][i].ff;
        int c=mp[s][i].ss;
        if(!visited[t]){
            visited[t]=1;
             if(cost<=c) ans+=cost,port++;
             else ans+=c;
             q.push(t);
        }

      }

   }
}
int main()
{
    // freopen("out.txt","w",stdout);
    int test=nxt();
    int cs=0;
    while(test--){
        int n=nxt(),m=nxt(),cost=nxt();
      FOR(i,0,m){
            int a=nxt(),b=nxt(),c=nxt();
            edge[i].u=a;
            edge[i].v=b;
            edge[i].cost=c;

        }
        mst(n,m);
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                port++;ans+=cost;
                bfs(i,cost);
            }
        }
        printf("Case %d: %d %d\n",++cs,ans,port);
        CLR(visited);
        ans=port=0;
        FOR(i,0,N) mp[i].clear();
    }


      return 0;
}

