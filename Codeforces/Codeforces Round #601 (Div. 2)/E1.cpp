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
vector<int> pos;
ll cost[N];
ll go(int x, int y) {
    ll tot = 0;
    ll cnt = 0;
    debug(x,y);
    for(int i = pos[x];i<=pos[y];i++) {
        tot+=cnt;
        if(ar[i]==1) cnt++;
        cost[i] = tot;
    }
    ll mn = LLONG_MAX;
    tot = 0;
    cnt = 0;
    for(int i = pos[y];i>=pos[x];i--) {
        tot+=cnt;
        if(ar[i]==1) cnt++;
       // debug(i,tot,cost[i]);
        if(tot+cost[i]<mn) mn = tot+cost[i];
    }
    return mn;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int cnt = 0;
    for(int i = 1;i<=n;i++) {
        ar[i] = nxt();
        cnt+=ar[i]==1;
        if(ar[i]==1) {
            pos.pb(i);
        }
    }
    int div = -1;
    vector<int> v;
    for(int i = 2;i<=cnt;i++) {
        if(cnt%i==0) {
            div = i;
            v.push_back(i);
        }
    }
    if(div==-1) {
        cout<<-1<<endl;
        return 0;
    }
    ll ans = LLONG_MAX;
    for(auto it : v) {
        ll sum = 0;
        div = it;
        for(int i = 0 ;i<pos.size();i+=div) {
            sum+=go(i,i+div-1);
        }
        debug(sum,div);
        ans = min(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
