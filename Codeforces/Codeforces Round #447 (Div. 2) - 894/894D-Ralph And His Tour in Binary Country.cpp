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
#define        N                               2000010
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
inline long double dxt(){long double aaa;scanf("%lf",&aaa);return aaa;}
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
ll ar[N];
vector<ll> subTree[N];
vector<ll> subTreeSum[N];
int n,q;
void Merge(vector<ll> &res, vector<ll> a,vector<ll> b) {

    int i = 0;
    int j = 0;
    while(i<a.size()&&j<b.size()) {
        if(a[i]<b[j]) {
            res.pb(a[i]);
            i++;
        } else {
            res.pb(b[j]);
            j++;
        }
    }
    while(i<a.size()) res.pb(a[i]),i++;
    while(j<b.size()) res.pb(b[j]),j++;

}
void dfs(int u) {
    if(2*u<=n) dfs(2*u);
    if(2*u+1<=n) dfs(2*u+1);

    int left = 2*u;
    int right = 2*u+1;
    vector<ll> a;
    vector<ll> b;
    if(left<=n) {
        int cost = ar[2*u-1];
        bool flag = 0;
        for(int i = 0;i<subTree[left].size();i++){
            a.pb(subTree[left][i]+cost);
        }
    }
    if(right<=n) {
        ll cost = ar[2*u];
        for(int i = 0;i<subTree[right].size();i++){
            b.pb(subTree[right][i]+cost);
        }
    }
    Merge(subTree[u],a,b);
//    if(u==2) {
//        for(auto it : a) debug(it);
//        cout<<endl;
//        for(auto it : b) debug(it);
//        cout<<endl;
//        for(auto it : subTree[u]) debug(it);
//        cout<<endl;
//    }

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n = nxt(),q = nxt();
    FOR(i,1,n) {
        ar[i] = lxt();
        subTree[i].pb(0);
    }
    subTree[n].pb(0);
    dfs(1);
    FOR(i,1,n+1) {
        subTreeSum[i].resize((int)subTree[i].size());
        FOR(j,0,subTree[i].size()) {
            if(j==0) {
                subTreeSum[i][j] = subTree[i][j];
            } else {
                subTreeSum[i][j] += subTreeSum[i][j-1] + subTree[i][j];
            }
        }
    }
    ll sumUp = 0;
    while(q--) {
        int u = nxt();
        ll h = lxt();
        ll ans = 0;
        sumUp=0;
        int up = upper_bound(ALL(subTree[u]),h)-subTree[u].begin();
        up--;
        if(up>=0) {
            ans+=(up+1)*h-subTreeSum[u][up];
        }
        if(u>1)
        while(1) {
            int v = u^1;
            int i = u/2;
            ll cost = 0;
            ll cost1= 0;
            if(u==i*2)  {
                cost = ar[i*2-1];
                cost1 = ar[i*2];
            } else {
                cost = ar[i*2];
                cost1=ar[i*2-1];
            }
           debug(v,cost,cost1);
            sumUp+=cost;
            if(sumUp>h) break;
            ans+=(h-sumUp);
            up = upper_bound(ALL(subTree[v]),h-sumUp-cost1)-subTree[v].begin();
            up--;
            if(up>=0) {
                ans+=(up+1)*(h-sumUp-cost1)-subTreeSum[v][up];
            }
            if(i==1) break;
            else u = i;
        }
        printf("%lld\n",ans);
    }

    return 0;
}