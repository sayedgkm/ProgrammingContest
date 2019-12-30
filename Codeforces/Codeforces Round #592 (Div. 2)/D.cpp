///Bismillahir-Rahmanir-Rahim
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
int ar[3][N];
vector<int> adj[N];
vector<int> nodes;
int visited[N];
int n;
ll dp[N][5][5];

ll go(int pos,int last, int lastOflast) {
     if(pos>=n) {
        return 0;
     }
    ll &res = dp[pos][last][lastOflast];
    if(res!=-1) return res;
    res = (ll)1e18;
    for(int i = 0;i<3;i++) {
        if(last==i||lastOflast==i) continue;
        res = min(res,go(pos+1,i,last)+(ll)ar[i][nodes[pos]]);
    }
    return res;

}
int ans[N];
void print(int pos,int last, int lastOflast, ll tot) {
     if(pos>=n) {
        return ;
     }

    ll res = (ll)1e18;
    int tempLast ;
    for(int i = 0;i<3;i++) {
        if(last==i||lastOflast==i) continue;
        if(go(pos+1,i,last) + (ll)ar[i][nodes[pos]]==tot) {
            res = go(pos+1,i,last)+(ll)ar[i][nodes[pos]];
            tempLast = i;
        }
    }
    ans[nodes[pos]] = tempLast;
    print(pos+1,tempLast,last,tot-ar[tempLast][nodes[pos]]);

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    n = nxt();
    for(int i = 0;i<3;i++) {
        for(int j = 1;j<=n;j++) ar[i][j] = nxt();
    }
    for(int i = 0;i<n-1;i++) {
        int a= nxt();
        int b= nxt();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int node = - 1;
    for(int i = 1;i<=n;i++) {
      //  debug(adj[i].size());
        if(adj[i].size()>2) {
            cout<<-1<<endl;
            return 0;
        }
        if(adj[i].size()==1) {
            node = i;
        }
    }
    visited[node] = 1;
    while(true) {

        nodes.push_back(node);
        for(int i = 0;i<adj[node].size();i++) {
            int v = adj[node][i];
            if(visited[v]) continue;
            visited[v] = 1;
            node = v;
        }
        if(nodes.size()==n) break;

    }
    SET(dp);
    cout<<go(0,3,3)<<endl;
    print(0,3,3,go(0,3,3));
    for(int i = 1;i<=n;i++) {
        printf("%d ",ans[i]+1);
    }
    printf("\n");

    return 0;
}
