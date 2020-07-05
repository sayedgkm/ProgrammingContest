
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
ll a[N], b[N], c[N];
int x,y,z;

ll get(int i, int j ,int k) {
    ll res = 0;
    res += (a[i]-b[j]) * (a[i]-b[j]);
    res += (b[j]-c[k]) * (b[j]-c[k]);
    res += (c[k]-a[i]) * (c[k]-a[i]);
    return res;
}


ll getta(ll a, ll b, ll c) {
    ll res = 0;
    res += (a-b) * (a-b);
    res += (b-c) * (b-c);
    res += (c-a) * (c-a);
    return res;
}
ll getSolution(int i, int j) {
    ll diff = (a[i] + b[j])/2;

    int l = lower_bound(c, c+ z, diff) - c;

    ll mx = LLONG_MAX;
   // debug(z);
    for(int k = max(0, l-10) ; k<=min(z-1, l+10) ; k++) {
        mx = min(mx, get(i,j,k));
    }

    return mx;
}

ll solve(){
    ll ans = LLONG_MAX;
    for(int i = 0;i<x;i++) {
            int l = lower_bound(b, b + y, a[i]) - b;
            for(int j = max(l-5, 0); j<=min(y-1, l+5) ; j++) {
                ans = min(getSolution(i, j), ans);
        }
    }

    return ans;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    int test = nxt();
    while(test--) {
         x = nxt();
         y = nxt();
         z = nxt();
        for(int i = 0;i< x;i++) {
            a[i] = lxt();
        }
        for(int i = 0;i< y; i++) {
            b[i] = lxt();
        }

        for(int i = 0; i<z;i++) {
            c[i] = lxt();
        }
        sort(a,a+x);
        sort(b,b+y);
        sort(c,c+z);

        ll ans = LLONG_MAX;
        ans = min(ans, solve());
        swap(y,z);
        swap(b,c);
        ans = min(ans, solve());
        swap(x, z);
        swap(a, c);
        swap(b, c);
        swap(y, z);
        ans = min(ans, solve());
        swap(b, c);
        swap(y, z);
        ans = min(ans, solve());
        swap(a,b);
        swap(x,y);
        ans = min(ans, solve());
        swap(b,c);
        swap(y,z);
        ans = min(ans, solve());


        printf("%lld\n",ans);
    }
     return 0;
}

