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
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
//    ll a= lxt();
//    ll b= lxt();
//    ll p = (a+b)*2;
//    cout<<(1.0*p*p)/(a*b)<<endl;
//    main();
    int test = nxt();
    while(test--) {
        int n = nxt();
        vector<int> v;
        for(int i = 0;i<n;i++){
            int a= nxt();
            if(ar[a]==0) v.pb(a);
            ar[a]++;
        }
        vector<int> valid;
        for(int i =0;i<v.size();i++) {
            if(ar[v[i]]>=4) {
                valid.pb(v[i]);
                valid.pb(v[i]);
            } else if(ar[v[i]]>=2) {
                valid.pb(v[i]);
            }
            ar[v[i]] = 0;
        }
        sort(ALL(valid));
        int x=-1,y=-1;
        long double mn = 3e18;
        for(int i = 1;i<valid.size();i++) {
            long double a = valid[i-1];
            long double b = valid[i];
            long double p = (a+b)*2.0;
            long double ar = a*b;
            long double ans = (p*p)/ar;
            if(ans<mn){
                x = a;
                y = b;
                mn = ans;
            }
        }
        printf("%d %d %d %d\n",x,x,y,y);
        valid.clear();

    }

    return 0;
}

