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
#define        N                               300010
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
vector<pii>v[N];
int n;
ll t;
int go(int mid) {
    vector<int> tmp;
    for(int i = mid;i<=n;i++) {
        for(int j = 0;j<v[i].size();j++) {
            tmp.pb(v[i][j].ff);
        }
    }
    sort(ALL(tmp));
    ll sum = 0;
    int cnt = 0;
    for(int i =0;i<tmp.size();i++) {
        sum+=(ll)tmp[i];
        if(sum<=t) cnt++;
    }
    return cnt>=mid;
}
void print(int mid) {
     vector<pii> tmp;
    for(int i = mid;i<=n;i++) {
        for(int j = 0;j<v[i].size();j++) {
            tmp.pb(v[i][j]);
        }
    }
    sort(ALL(tmp));
    ll sum = 0;
    int cnt = 0;
    int sp = 0;
    for(int i =0;i<tmp.size();i++) {
        sum+=(ll)tmp[i].ff;
        if(sum<=t&&cnt<mid){
            if(sp) printf(" ");
            sp = 1;
            printf("%d",tmp[i].ss+1);
            cnt++;
        }
    }
    printf("\n");
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //cout<<setprecision(20)<<fixed<<(double)N*log2(N)*log2(N)<<endl;
    n = nxt();
    t = lxt();
    for(int i  = 0;i<n;i++) {
        int a = nxt();
        int t = nxt();
        v[a].pb(make_pair(t,i));
    }
    for(int i = 0;i<=n;i++) {
        sort(ALL(v[i]));
    }
    int b = 0;
    int e = n;
    int ans = 0;
    //cout<<go(3)<<endl;
    while(b<=e) {

        int mid = (b+e)/2;
        if(go(mid)) b = mid+1,ans = mid;
        else e = mid-1;
    }
    if(ans==0){
        cout<<0<<endl;
        cout<<0<<endl;
        return 0;
    }
    printf("%d\n%d\n",ans,ans);
    print(ans);


    return 0;
}