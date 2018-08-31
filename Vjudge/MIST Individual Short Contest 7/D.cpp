 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               20000010
#define        M                               (ll)1000000007
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
int ar[N];
int lcm(int a,int b) {
    return (a/gcd(a,b))*b;
}
vector<ll>primes;
bool mark[N];
void sieve(int n) {
    primes.push_back(2);
    for(int i=3; i*i<=n; i+=2)
     for(int j = i*i; j <= n; j += i * 2)
            mark[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!mark[i]) primes.push_back(i);
    }
void nod(ll n){
    ll result=1;
    for(ll i=0;primes[i]*primes[i]<=n;i++){
        if(n%primes[i]==0){
            int c=1;
        while(n%primes[i]==0){
                n/=primes[i];
                cout<<primes[i]<<" ";
        }
       result=result*c;
    }
 }
  if(n>1)
     cout<<n<<" ";
  cout<<endl;

}
ll pre[N];
ll go(int i,int j) {
    ll res = pre[j];
    if(i) {
        res*=bigmod(pre[i-1],M-2,M);
    }
    return res%M;
}
ll howmany(ll n,ll p) {
    ll cnt = 0;
    while(n>=p) n/=p,cnt++;
    return cnt-1;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    sieve(N-1);

    for(int j =0;j<primes.size();j++) {
        pre[j] = primes[j];
        if(j) pre[j]*=pre[j-1];
        pre[j]%=M;
    }
    int test = nxt(); int cs = 1;
    while(test--){
//    int n = nxt();
//    ll ans = 1;
//    for(int i = 0; ;i++) {
//        int tmp= n;
//        ll cnt = 0;
//        while(tmp>=primes[i]) tmp/=primes[i],cnt++;
//        debug(cnt);
//        ans = ans*bigmod((ll)primes[i],cnt-1,(ll)M);
//        ans%=M;
//        if(cnt==1) break;
//    }
//    cout<<ans<<endl;
        ll n = lxt();

        ll ans = 1;
        for(int i = 0;i<primes.size();) {

            ll p = primes[i];
            ll cnt = howmany(n,p);
            if(cnt==0) break;
            ll b = i;
            ll e= primes.size()-1;
            while(b<=e) {

                ll mid = (b+e)/2;
                if(howmany(n,primes[mid])==cnt) b = mid+1;
                else e = mid-1;
            }
            ll tmp = go(i,b-1);
//            debug(i,b-1);
//            debug(go(i,b-1));
            ans*=bigmod(tmp,cnt,M);
            ans%=M;
            i= b;
        }
        printf("Case %d: %lld\n",cs++,ans);

   }


    return 0;
}

