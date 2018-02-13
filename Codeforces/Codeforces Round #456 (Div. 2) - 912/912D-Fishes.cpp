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
int ar[N];
ll n,m,r;
struct info {
    int x,y,cost;
    info(int _x,int _y,int _cost) : x(_x), y(_y), cost(_cost){}
    bool operator< (const info &other) const {
      return  cost<other.cost;
    }
};


ll give(ll i,ll j) {
//    for(int i = 1;i<=n;i++) {
//        for(int j = 1;j<=m;j++) {
//            int a = min(r,min(j,m-max(r,j)+1));
//            int b = min(r,min(i,n-max(r,i)+1));
//            cout<<a*b<<" ";
//        }
//        cout<<endl;
//    }

            ll a = min(r,min(j,m-max(r,j)+1));
            ll b = min(r,min(i,n-max(r,i)+1));
            return a*b;

}
map<pii,int> mp;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
priority_queue<info> pq;
//    pq.push(info(2,2,2));
//    pq.push(info(1,2,1));
//    cout<<pq.top().cost<<endl;
     n = lxt();
     m = lxt();
     r = lxt();
     ll k = lxt();
     int stx = (n+1)/2;
     int sty = (m+1)/2;
     pq.push(info(stx,sty,give(stx,sty)));
     ll sum =0;
     mp[{stx,sty}] = 1;
     while(!pq.empty()&&k--) {

        info temp = pq.top();
        //debug(temp.cost);
        sum+=temp.cost;
        pq.pop();
        for(int i = 0;i<8;i++) {
            int nx  = temp.x+dx[i];
            int ny = temp.y+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!mp.count({nx,ny})) {
                debug(give(nx,ny));
                pq.push(info(nx,ny,give(nx,ny)));
                mp[make_pair(nx,ny)] = 1;
            }
        }

     }
   //  debug(k);

    cout<<setprecision(20)<<fixed<<(double)sum/(double)((m-r+1)*(n-r+1))<<endl;
    return 0;
}