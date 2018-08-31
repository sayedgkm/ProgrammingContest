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

struct info{
    int x1,y1,x2,y2;

}ar[N];
vector<pii> v;
int n;
bool go(int x,int y) {
    int cnt = 0;
    for(int i = 0;i<n;i++) {
        if(x>=ar[i].x1&&x<=ar[i].x2&&y>=ar[i].y1&&y<=ar[i].y2) cnt++;
    }
    return cnt>=(n-1);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n = nxt();
    for(int i = 0;i<n;i++) {
        ar[i].x1 = nxt();
        ar[i].y1 = nxt();
        ar[i].x2 = nxt();
        ar[i].y2 = nxt();
        v.pb(make_pair(ar[i].x1,0));
        v.pb(make_pair(ar[i].x2,1));
    }
    sort(ALL(v));
    vector<int> x;
    int cnt = 0;
    for(int i = 0;i<v.size();i++) {
        if(v[i].ss==0) cnt++;
        if(cnt>=n-1) {
            x.pb(v[i].ff);
        }
        if(v[i].ss==1) cnt--;

    }
    v.clear();
      for(int i = 0;i<n;i++) {
        v.pb(make_pair(ar[i].y1,0));
        v.pb(make_pair(ar[i].y2,1));
    }
    sort(ALL(v));
    vector<int> y;
    cnt= 0;
    for(int i = 0;i<v.size();i++) {
        if(v[i].ss==0) cnt++;
        if(cnt>=n-1) {
            y.pb(v[i].ff);
        }
        if(v[i].ss==1) cnt--;

    }
    assert(x.size()<5&&y.size()<5);
    debug(x.size(),y.size());
    for(int i = 0;i<x.size();i++) {
        for(int j = 0;j<y.size();j++) {
            if(go(x[i],y[j])) {
                cout<<x[i]<<" "<<y[j]<<endl;
                return 0;
            }
        }
    }
    assert(0);
    return 0;
}
