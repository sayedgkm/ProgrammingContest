#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
#define        M                               998244353
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
int path[N];
int Size[N];
void root(int n) {
    for(int i=0; i<=n; i++)
        path[i]=i,Size[i] = 1;
}
int findUnion(int x) {      ///Find root of x
    if(path[x]==x) return x;
    return path[x]=findUnion(path[x]);

}
void mergeUnion(int x,int y) {
    path[findUnion(x)]=findUnion(y); ///making same root of both x and y
}
bool sameset(int x,int y) { ///check two element are in same set or not
    return findUnion(x)==findUnion(y);
}
vector<pii> edge[N];
vector<pii> query;
ll res[N];
ll nc2(ll n) {
    return ((ll)n*(n-1LL))/2LL;
}
int main() {
    root(N-1);

    int n = nxt();
    int  m = nxt();
    for(int i =0;i<n-1;i++) {
        int a = nxt();
        int b= nxt();
        int c =nxt();
        edge[c].push_back(make_pair(a,b));
    }
    for(int i = 0;i<m;i++) {
        int a= nxt();
        query.push_back(make_pair(a,i));
    }
    sort(ALL(query));
    ll ans = 0;
    int ind = 0;
    for(int i = 0;i<query.size();i++) {
        int val = query[i].ff;
        while(ind<=val) {

            for(auto it : edge[ind]) {
                int a = it.ff;
                int b = it.ss;
                ll sza = Size[findUnion(a)];
                ll szb = Size[findUnion(b)];
                ans-=nc2(sza);
                ans-=nc2(szb);
                ll sz = sza+szb;
                ans+=nc2(sz);
                mergeUnion(a,b);
                Size[findUnion(a)] = Size[findUnion(b)]=sz;
            }

            ind++;
        }
        res[query[i].ss] = ans;
    }

    for(int i = 0;i<m;i++) {
        if(i) printf(" ");
        printf("%lld",res[i]);
    }
    printf("\n");
   return 0 ;
}
