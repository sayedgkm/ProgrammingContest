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
#define        N                               500010
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
int st[N],ed[N];
int t = 1;
vector<int> adj[N];
vector<pii> ans[N];
string s;
void dfs(int u,int p,int level) {
    st[u] = t;
    ans[level].pb(make_pair(t,ans[level].back().ss^(1<<(s[u]-'a'))));
    t++;
    for(auto it : adj[u]) {
        if(it==p) continue;
        dfs(it,u,level+1);
    }
    ed[u] = t-1;
}
bool cmp(pii a,pii b)  {
    return a.ff<b.ff;
}
int lower(int h,int shuru) {
    int b = 0;
    int e = ans[h].size()-1;
    while(b<=e) {
        int mid= (b+e)/2;
        if(ans[h][mid].ff<shuru) b  = mid+1;
        else e = mid - 1;
    }
    return b;
}
int upper(int h,int shuru) {
    int b = 0;
    int e = ans[h].size()-1;
    while(b<=e) {
        int mid= (b+e)/2;
        if(ans[h][mid].ff<=shuru) b  = mid+1;
        else e = mid - 1;
    }
    return b;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n = nxt();
    int q = nxt();
    FOR(i,2,n+1) {
        int a = nxt();
        adj[a].pb(i);
        ans[i].pb(make_pair(0,0));
    }
    ans[1].pb(make_pair(0,0));
    cin>>s;
    s = '?' + s;
    dfs(1,-1,1);
    while(q--){
        int node = nxt();
        int h = nxt();
        int shuru = st[node];
        int sesh = ed[node];
        int c = 0;
        int l = lower(h,shuru);
        int r = upper(h,sesh);
        l--;
        r --;
        debug(ans[h][2].ss);
        int f = 0;
        if(r>=0&&r<ans[h].size()){
            f =(int)(ans[h][r].ss);
        }
        if(l>=0&&l<ans[h].size()){
            f ^=(int) ans[h][l].ss;
        }
       // debug(l,r,f,ans[h][l].ss,ans[h][r].ss);


        f -= f&(-f);

        puts(f==0?"Yes":"No");
    }




    return 0;
}