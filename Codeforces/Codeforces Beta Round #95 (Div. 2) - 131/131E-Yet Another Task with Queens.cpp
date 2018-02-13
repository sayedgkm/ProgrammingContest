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
#define        N                               200010
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
pii ar[N];
vector<int> row[N];
vector<int> clm[N];
vector<int> mainDiagonal[N];
vector<int> diagonal[N];
int ans [10];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int q = nxt();
    FOR(i,0,q) {
        ar[i].ff = nxt();
        ar[i].ss = nxt();
        row[ar[i].ff].pb(ar[i].ss);
        clm[ar[i].ss].pb(ar[i].ff);
        mainDiagonal[ar[i].ss-ar[i].ff+n].pb(ar[i].ss);
        diagonal[ar[i].ff+ar[i].ss].pb(ar[i].ss);
    }
    for(int i= 0;i<N;i++) {
        sort(ALL(row[i]));
        sort(ALL(clm[i]));
        sort(ALL(mainDiagonal[i]));
        sort(ALL(diagonal[i]));
    }
    for(int i = 0;i<q;i++) {
        int cnt = 0;
        int l =lower_bound(ALL(row[ar[i].ff]),ar[i].ss)-row[ar[i].ff].begin();
        if(l>0) cnt++;
        if(l<row[ar[i].ff].size()-1) cnt++;
       // debug(cnt);
        l =lower_bound(ALL(clm[ar[i].ss]),ar[i].ff)-clm[ar[i].ss].begin();
        if(l>0) cnt++;
        if(l<clm[ar[i].ss].size()-1) cnt++;
      //  debug(cnt);
        l = lower_bound(ALL(mainDiagonal[ar[i].ss-ar[i].ff+n]),ar[i].ss)-mainDiagonal[ar[i].ss-ar[i].ff+n].begin();
        if(l>0) cnt++;
        if(l<mainDiagonal[ar[i].ss-ar[i].ff+n].size()-1) cnt++;
        l = lower_bound(ALL(diagonal[ar[i].ff+ar[i].ss]),ar[i].ss)-diagonal[ar[i].ff+ar[i].ss].begin();
        if(l>0) cnt++;
        if(l<diagonal[ar[i].ff+ar[i].ss].size()-1) cnt++;
        ans[cnt]++;
       // debug(cnt,i);
    }
    for(int i = 0;i<9;i++) {
        printf("%d ",ans[i]);
    }
    return 0;
}