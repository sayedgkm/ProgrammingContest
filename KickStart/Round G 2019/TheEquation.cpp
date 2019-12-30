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
ll ar[N];
ll one[100];
ll MinPossibleSum(ll pos, ll n) {
   // debug(pos);
    ll sum = 0;
    for(ll i = pos;i>=0;i--) {
        ll o = one[i];
        ll z = n-o;
        ll mn = min(z,o);
        sum+=(1LL<<i)*mn;
    }
   // debug(sum);
    return sum;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    cout<<(ll)log2(1e15)<<endl;
    int test  = nxt(); int cs = 1;
    while(test--) {

        int n = nxt();
        ll limit = lxt();
        CLR(one);
        for(int i = 0;i<n;i++) {
            ar[i] = lxt();

            for(ll j = 0;j<=60;j++) {
                if(ison(ar[i],j)) {
                    one[j]++;
                }
            }
        }
        ll mxPossible = 0;
        ll k = 0;
        for(ll i = 50;i>=0;i--) {
            ll nextSum  = MinPossibleSum(i-1,n);
            ll oneSum = (1LL<<i)*(n-one[i]);
            ll zeroSum = (1LL<<i)* (one[i]);
            if(mxPossible+oneSum+nextSum<=limit) {
                mxPossible+=oneSum;
                k+=(1LL<<i);
            } else if(mxPossible+zeroSum+nextSum<=limit) {
                mxPossible+=zeroSum;
            } else {
                mxPossible = -1;
                k = -1;
                break;
            }
            debug(mxPossible,nextSum,oneSum,zeroSum,i,k);
        }
        printf("Case #%d: %lld\n",cs++,k);
    }
    return 0;
}
///0101
///1000
///0010
///0100
