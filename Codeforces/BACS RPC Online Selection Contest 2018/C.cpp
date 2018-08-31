 /// Bismillahir-Rahmanir-Rahim
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
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************

ll cnt(ll n,ll x) {
    if(x>n) return 0;
    if(x%2==0) return 0;
    ll hi = 2;
    ll c = 0;
    while((hi-1)<=n) {
        if(x<=(hi-1)) c++;
        hi*=2LL;
    }
    hi/=2;
    hi--;
    n = n-hi;
//debug(hi,n);
    n*=2;
    n--;
    c+=x<=n;
    return c;
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    //debug(cnt(33,5));
   int test= nxt();
   int cs = 1;
   while(test--) {
        ll self = lxt();
        ll l = lxt();
        ll n = lxt();
        ll up,down;
        printf("Case %d: ",cs++);
        if(self>=l) {
            up = cnt(n,self)-cnt(self-1,self);
            up+=(self-l);
            down= n-l+1;

        } else {

            up = cnt(n,self)-cnt(l-1,self);
            down = n-l+1;

        }
        ll gc = gcd(up,down);
        if(gc) {
            up/=gc;
            down/=gc;
        }
        if(up==0) {
            printf("0/1\n");
        } else {
            printf("%lld/%lld\n",up,down);
        }


   }


    return 0;
}
