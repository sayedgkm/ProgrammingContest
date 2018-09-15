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
int ar[N];
vector< tuple < int,int, int> > edge;
vector<int> adj[5];
set<int> com[5];
int comId= 0;
int color[5]={0};
int x=-1 , y=-1;
void dfs(int u) {
    com[comId].insert(u);
    color[u] = 1;
    for(auto it :adj[u]){
            if((u==x&&it==y)||(u==y&&it==x)) continue;if(!color[it]) dfs(it);
    }
}
set<int> node;
int deg[5]={0};
int recal(int a,int b,int c) {
    CLR(color);
    com[0].clear();
    com[1].clear();
    comId = 0;
    x = a;
    y = b;
    for(auto it : node) {
        if(!color[it]) dfs(it),comId++;
    }
    if(comId==1) return c;
    int res[2]={0};
    int cnt = 0;
    for(auto it : edge) {

        int a= get<0> (it);
        int b= get<1> (it);
        if(a==x&&y==b) cnt++;
        if(a==y&&x==b) cnt++;
        int c= get<2> (it);
        for(int i = 0;i<comId;i++) {
            if(com[i].find(a)!=com[i].end()&&com[i].find(b)!=com[i].end()) {
                res[i]+=c;
                break;
            }
        }
    }
    if(cnt>1) return c;
    return c+(*min_element(res,res+2));

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    ll tot = 0;
    for(int i = 0;i<n;i++) {
        int a= nxt();
        int c= nxt();
        int b = nxt();
        deg[a]++;
        deg[b]++;
        node.insert(a);
        node.insert(b);
        edge.pb(make_tuple(a,b,c));
        adj[a].pb(b);
        adj[b].pb(a);
        tot+=c;
    }
    for(int i = 1;i<=4;i++)  {
        if(!color[i]&&node.find(i)!=node.end()) {
            dfs(i);
            comId++;
        }
    }

    if(comId==1) { /// handle separately
        int Minus = inf;
        if(com[comId-1].size()==4) {
            int cnt = 0;
            for(int i = 1;i<=4;i++) {
                cnt+=deg[i]%2;
            }
            debug(cnt);
            if(cnt==4){ for(auto it : edge) if(get<0>(it)!=get<1>(it)) Minus =  min(Minus , recal(get<0>(it),get<1>(it),get<2> (it)));}
            else Minus = 0;
        } else {
            Minus = 0;
        }
        debug(Minus);
        cout<<tot-Minus<<endl;
    } else {
        int res[5]={0};
        for(auto it : edge) {

            int a= get<0> (it);
            int b= get<1> (it);
            int c= get<2> (it);
            for(int i = 0;i<comId;i++) {
                if(com[i].find(a)!=com[i].end()&&com[i].find(b)!=com[i].end()) {
                    res[i]+=c;
                    break;
                }
            }
        }
        cout<<*max_element(res,res+5)<<endl;
    }


    return 0;
}

