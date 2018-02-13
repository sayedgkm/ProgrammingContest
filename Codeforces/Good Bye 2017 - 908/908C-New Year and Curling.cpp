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
#define        pd                            pair<long double,long double>
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
long double ar[N];
vector<pd> v;
int n ;
long double r;
long double dist (long double x1,long double y1,long double x2,long double y2){
    long double dx = x1 - x2;
    dx= dx*dx;
    long double dy = y1 - y2;
    dy= dy*dy;
    return   sqrt(dx+dy);
}
long double go(int i,int j) {
//    long double b = v[j].ss;
//    long double e = b+r+r+r;
////    if(i==3&&j==2){
////        debug(b);
////        debug(e);
////    }
//    for(int t= 0;t<=100;t++) {
//        long double mid = (b+e)/2;
//        long double d= dist(ar[i],mid,v[j].ff,v[j].ss);
//        if(d<=(long double)2*r) b = mid;
//        else e = mid;
//
//    }
//    return b;

 return v[j].ss+sqrt(4*r*r-(ar[i]-v[j].ff)*(ar[i]-v[j].ff));
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        cin>>n>>r;
    FOR(i,0,n){
        cin>>ar[i];
    }

    v.pb(make_pair(ar[0],r));
    for(int i = 1;i<n;i++) {
        long double y = r;
        for(int j = 0;j<v.size();j++) {
            if(fabs(v[j].ff-ar[i])<=(long double)2*r) {
                y = max(y,go(i,j));
            }
        }
        v.pb(make_pair(ar[i],y));
    }
    for(int i = 0;i<v.size();i++){
        if(i) cout<<" ";
        cout<<setprecision(10)<<fixed<<v[i].ss;
    }
    cout<<endl;
    return 0;
}