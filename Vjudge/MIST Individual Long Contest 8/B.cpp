 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
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

int ar[1005][1005];
int x= 0;
int n ,m;
int get(int x,int k) {
    if(x==0) return 0;
    else if(x==n*m+1) return 2*((n-1)*(m-1))+1;
    return k+((x-1)*2);
}
int rectangle(int i,int j) {
    if(i==1||j==m) return 0;
    else if(i==n+1||j==0) return (n*m)+1;
    else {
        return (i-2)*(m-1)+j;
    }
}
vector<pll> adj[N];
ll level[N];
int dijkstra(int st) {
    int dest =2*((n-1)*(m-1))+1;
    for(int i = 0;i<=dest;i++) level[i] = (ll)3e17;
    level[0] = 0;
    priority_queue<pii> pq;
    pq.push(make_pair(-level[0],0));
    while(!pq.empty()) {
        pii top = pq.top();
        if(top.ss==dest) return -top.ff;
        pq.pop();
        for(auto it : adj[top.ss]) {
            if(level[top.ss]+it.ss<level[it.ff]) {
               level[it.ff]=(ll)level[top.ss]+it.ss;
               pq.push(make_pair(-level[it.ff],it.ff));
            }

        }

    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int cs  = 1;
    while(1) {


        scanf("%d %d",&n,&m);
        if(!n&&!m) break;

        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<m;j++) {
                int a= nxt();
                int up = rectangle(i,j);
                int down = rectangle(i+1,j);
                int x= get(up,2);
                int y =get(down,1);
                adj[x].pb(make_pair(y,a));
                adj[y].pb(make_pair(x,a));
            }
        }
        for(int i =1;i<n;i++) {
            for(int j = 1;j<=m;j++) {
                int a= nxt();
                int Left = rectangle(i+1,j-1);
                int Right = rectangle(i+1,j);
                int x= get(Left,1);
                int y = get(Right,2);
                 adj[x].pb(make_pair(y,a));
                adj[y].pb(make_pair(x,a));
            }
        }
        for(int i = 1;i<n;i++) {
            for(int j = 1;j<m;j++) {
                int a= nxt();
                int no =rectangle(i+1,j);
                int x = get(no,1);
                int y= get(no,2);
                 adj[x].pb(make_pair(y,a));
                adj[y].pb(make_pair(x,a));

            }
        }
       printf("Case %d: Minimum = %d\n",cs++,dijkstra(0));
       FOR(i,0,N) adj[i].clear();
    }


    return 0;
}

