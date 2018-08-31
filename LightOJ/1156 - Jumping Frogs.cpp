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
namespace mf
{
    const int MAXN = 10004;
    struct edge {
        int a, b, cap, flow ;
        edge(int _a,int _b,int _c,int _d) {
            a=_a,b=_b,cap=_c,flow=_d;
        }
    } ;

    int INF=1500000001;

    int n, s, t, d [ MAXN*2 ] , ptr [ MAXN*2 ] , q [ MAXN*2*10 ] ;
    vector < edge > e ;
    vector < int > g [ MAXN * 2 ] ;

    void addEdge ( int a, int b, int cap ,int cap2=0) {
        edge e1 =edge( a, b, cap, 0 ) ; /// forward cap
        edge e2 =edge( b, a, cap2 , 0 ) ; /// backward cap change here if needed
        g [ a ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back ( e1 ) ;
        g [ b ] . push_back ( ( int ) e. size ( ) ) ;
        e. push_back( e2 ) ;
    }

    bool bfs ( ) {
        int qh = 0 , qt = 0 ;
        q [ qt ++ ] = s ;
        memset ( d, -1 , sizeof d ) ;
        d [ s ] = 0 ;
        while ( qh < qt && d [ t ] == - 1 ) {
            int v = q [ qh ++ ] ;
            for ( size_t i = 0 ; i < g [ v ] . size ( ) ; ++ i ) {
                int id = g [ v ] [ i ] ,
                    to = e [ id ] . b ;
                if ( d [ to ] == - 1 && e [ id ] . flow < e [ id ] . cap ) {
                    q [ qt ++ ] = to ;
                    d [ to ] = d [ v ] + 1 ;
                }
            }
        }
        return d [ t ] != -1;
    }

    int dfs ( int v, int flow ) {
        if ( ! flow )  return 0 ;
        if ( v == t )  return flow ;
        for ( ; ptr [ v ] < ( int ) g [ v ] . size ( ) ; ++ ptr [ v ] ) {
            int id = g [ v ] [ ptr [ v ] ] ,
                to = e [ id ] . b ;
            if ( d [ to ] != d [ v ] + 1 )  continue ;
            int pushed = dfs ( to, min ( flow, e [ id ] . cap - e [ id ] . flow ) ) ;
            if ( pushed ) {
                e [ id ] . flow += pushed ;
                e [ id ^ 1 ] . flow -= pushed ;
                return pushed ;
            }
        }
        return 0 ;
    }

    ll dinic ( ) {
        ll flow = 0 ;
        for ( ;; ) {
            if ( !bfs () )  break ;
            memset ( ptr, 0 , sizeof ptr ) ;
            while ( int pushed = dfs ( s, INF ) ) {
                flow += (ll)pushed ;
                if(pushed == 0)break;
            }
        }
        return flow ;
    }

    void init(int src, int dest , int nodes){
        e.clear();
        FOR(i,0,n+n) g[i].clear();
        n = nodes; s = src; t = dest;
    }
};

vector<pii> v;
bool go(int mid) {
    int extra = v.size();
    mf::init(0,(v.size()-1)+extra,v.size()*2);
    for(int i = 0;i<v.size();i++){
        mf::addEdge(i,i+extra,1+(v[i].ss==1));
        for(int j = i+1;j<v.size();j++) {
            if(v[i].ff+mid>=v[j].ff) {
                mf::addEdge(i+extra,j,inf);
            } else break;
        }
    }
    return mf::dinic()>=2;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    string s;int cs= 1;
    char t[20];
    while(test--) {

        int n= nxt();
        int l = nxt();
        v.pb(make_pair(0,1));
        v.pb(make_pair(l,1));
        for(int i = 0;i<n;i++) {
            scanf("%s",t);
            s = t;
            int f= 1;
            if(s[0]=='S') f =0;
            s = s.substr(2);
            stringstream ss;
            ss<<s;
            int num;
            ss>>num;
            v.pb(make_pair(num,f));
        }
        sort(ALL(v));
       // debug(go(18));
        int lo = 0;
        int hi = l;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(go(mid)) hi =  mid-1;
            else  lo = mid+1;
        }
        printf("Case %d: %d\n",cs++,lo);
        v.clear();
    }

    return 0;
}

