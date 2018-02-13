
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
int cnt[75];
int mark[75];
ll pow2[N];
int maskcnt[75];
vector<int>primes;
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
}
int dp[71][(1<<19)+5];
int go(int pos,int mask) {
   // debug(pos,mask);
    if(pos>70) {
        return mask==0;
    }
    if(dp[pos][mask]!=-1) return dp[pos][mask];
    ll res = 0;
    ll gun;
    if(cnt[pos]==0) gun = 1;
    else gun = pow2[cnt[pos]-1];
    res = res+go(pos+1,mask)*gun;
    res%=M;
    if(cnt[pos])
    res= res+go(pos+1,mask^maskcnt[pos])*gun;
    res%=M;
    return dp[pos][mask] = (int) res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    sieve(74);

    int rnk = 0;
    CLR(mark);
    for(auto it: primes) mark[it]=rnk++;
    pow2[0] = 1;
    for(int i =1 ;i<N;i++) pow2[i]= pow2[i-1]*2LL,pow2[i]%=M;
    for(int i = 2;i<=70;i++) {
            int x = i;
        for(int j = 0;primes[j]*primes[j]<=x;j++) {
            int c = 0;
            if(x%primes[j]==0) {
                while(x%primes[j]==0) {
                 c++;
                 x/=primes[j];
                }
            }
           // debug(c,primes[j]);
            if(c%2) {
                maskcnt[i]=biton(maskcnt[i],mark[primes[j]]);
            }
        }
        if(x>1) maskcnt[i]=biton(maskcnt[i],mark[x]);
    }
    debug(maskcnt[36]);
    int n = nxt();
    FOR(i,0,n) {
        int a = nxt();
        cnt[a]++;
    }
   // debug(cnt[2]);
    SET(dp);
    ll res = go(1,0)-1;
    res+=M;
    res%=M;
    printf("%lld\n",res);




    return 0;
}
