
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
int ar[N];
vector<int> adj[N];
bool oddFound = 0;
int dis[N];
int paren[N];
vector<int> v[N];
void dfs(int u, int p  = -1) {
    bool isOdd = 0;
    bool isEven = 0;
    //debug(u,p);
    paren[u] = p;
    for(auto it : adj[u]) {
        if(it!=p) {
            dfs(it, u);
            if(dis[it]%2==0) {
                isEven = true;
            }
            if(dis[it]%2) {
                isOdd = true;
            }
        }
    }
    if(isOdd && isEven) {
        oddFound = true;
    }
    if(isEven) {
        dis[u] = 1;
    } else {
        dis[u] = 0;
    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    int n = nxt();

    for(int i = 0;i<n-1;i++) {
        int a= nxt();
        int b= nxt();
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = 1;
    for(int i = 1;i<=n;i++) {
        if(adj[i].size()>1) {
            root = i;
            break;
        }
    }

    dfs(root);

    if(oddFound) {
        cout<<3;
    } else cout<<1;

    int mx = n-1;
   // debug(paren[1],paren[2]);
    for(int i = 1;i<=n;i++) {
        if(adj[i].size()==1) {
            int p = paren[i];
            v[p].push_back(i);
        }
    }

    for(int i = 1;i<=n;i++) {
       // debug(v[i].size(), i);
        if(v[i].size()) {
            mx-=((int)v[i].size()-1);
        }
    }

    cout<<" " <<mx<<endl;

     return 0;
}

