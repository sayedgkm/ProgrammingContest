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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
int ar[N];
int visited[N];
int level[N];
int path[N];
vector<int> adj[N];
void go(int st) {
    CLR(level);
    queue<int>q ;
    q.push(st);
    visited[st] = 1;

    while(!q.empty()) {
        int u = q.front();
            q.pop();

        for(int i =0;i<adj[u].size();i++) {

            int v  = adj[u][i];

            if(!visited[v]){
          //  debug(u,v);
                visited[v] = 1;
                path[v] = u;
                level[v] = level[u]+1;
                q.push(v);
            }
        }

    }
}

vector<int> ans;
int mid ,l,r;
int c ;
vector<int> vv;
void dfs(int u,int p = -1,int x =-1){
    c++;
    if(x>0&&p!=-1){
        debug(p,mid,x);
        ans.pb(p);
    }
    ans.pb(u);
    int tmp = 0;
    for(int i = 0;i<adj[u].size();i++){
        int x = adj[u][i];
        if(mid==u&&x==l){
        tmp++;
        continue;
        }
        if(mid==u&&x==r) {
            tmp++;
            continue;
        }
        if(x==p) {
            tmp++;
            continue;
        }

        dfs(x,u,i-tmp);


    }
    if(u!=mid&&adj[u].size()>1)
        ans.pb(u);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n = nxt();
    FOR(i,0,n-1) {
     int a= nxt();
     int b = nxt();
     adj[a].pb(b);
     adj[b].pb(a);
    }
    go(1);
    int mx = -1;
    int node;
    for(int i = 1;i<=n;i++){
       // debug(level[i]);
        if(level[i]>=mx){
            mx = level[i];
            node = i;
        }
    }
    SET(path);
    CLR(level);
    CLR(visited);
    go(node);
    int node1 ;
    mx = 0;
    for(int i = 1;i<=n;i++){
         //  debug(level[i]);
        if(level[i]>=mx){
            mx =level[i];
            node1 = i;
        }
    }
    vector<int> v ;
    v.pb(node1);
    while(node1!=node){
        node1= path[node1];
        v.pb(node1);
    }
    for(int i= 0;i<v.size();i++){
        mid = l = r = -1;
        mid =v[i];
        c= 0;
        if(i-1>=0) l = v[i-1];
        if(i+1<v.size()) r = v[i+1];
        dfs(v[i]);
        if(c>1) ans.pb(v[i]);
    }
    printf("%d\n",(int)ans.size()-1);
   for(int i= 0;i<ans.size();i++){
        if(i) printf(" ");
        printf("%d",ans[i]);
   }
   printf("\n");
    return 0;
}
