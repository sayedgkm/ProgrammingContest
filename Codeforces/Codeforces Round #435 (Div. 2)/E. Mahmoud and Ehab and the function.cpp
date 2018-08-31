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
ll ar[N];
ll br[N];
ll sum[2][N];
ll found[N];
vector<ll> v;
int n,m;
ll go(int pos) {
    ll sum  = 0;
    for(int i = 1;i<=n;i++) {
        if(i%2) sum+=(ar[i]-br[i+pos-1]);
        else sum-=(ar[i]-br[i+pos-1]);
    }
    return sum;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    n = nxt();
    m = nxt();
    int q =nxt();
    for(int i = 1;i<=n;i++) ar[i] = lxt();
    ll initial = 0;
    for(int i = 1;i<=n;i++) if(i%2) initial+=ar[i];else initial-=ar[i];
    for(int i = 1;i<=m;i++){
        br[i] = lxt();
        if(i%2) sum[0][i]=-br[i];
        else sum[1][i] = br[i];
    }
    for(int i = 1;i<=m;i++) {
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
    }
    ll len = m-n;
    for(int i = 1;i<=len+1;i++) {
        ll neg,pos;
        neg = sum[0][i+n-1]-sum[0][i-1];
        pos = sum[1][i+n-1]-sum[1][i-1];
        if(i%2==0) neg*=-1,pos*=-1;
        found[i] = initial+neg+pos;


    }
    for(int i =1;i<=len+1;i++) v.pb(found[i]);
    ll add = 0;
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    v.pb(3e17);
    int b = 0;
    int e = v.size()-2;
    while(b<e) {
        int mid = (b+e)/2;
        if(abs(v[mid]+add)<abs(v[mid+1]+add)) e = mid;
        else b = mid+1;

    }
    printf("%lld\n",abs(v[b]+add));

    while(q--) {
        int l = nxt();
        int r = nxt();
        ll x = lxt();
        if((r-l+1)%2==1) {
            if(l%2) add += x;
            else add -=x;
        }
        ll res  = 3e17;
        int  b = lower_bound(ALL(v),-add)-v.begin();

        for(int i = max(0,b-5);i<min(b+5,(int)v.size()-1);i++)
            res = min(res,abs(v[i]+add));
        printf("%lld\n",res);

    }

    return 0;
}

