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
int miu[N];
int mark[N];
void mobius(int n){
 for(int i=0;i<=n;i++) miu[i]=1;
       miu[0]=0;
       miu[1]=1;
      for(int i=2;i<=n;i++){
             if(mark[i]) continue;
                miu[i]=-1;
           for(int j=i*2;j<=n;j+=i){
               if(miu[j]!=0){
                   if(j%(i*i)==0) miu[j]=0;
                   else miu[j]*=-1;
                   mark[j]=1;
               }
           }
    }

}
ll root(ll n,ll x) {
    ll tmp = pow(n,1/(double)x);
    tmp-=2;
    tmp = max(0LL,tmp);
    ll ans = 1;
    while(1){
        ans = 1;
        for(int i = 0;i<x;i++) {
                ans*=tmp;
        }
        if(ans>n||ans<0) return tmp-1;
        tmp++;
    }


}
ll go(ll l,ll r,ll p) {
    ll tmp = 0;
    if(l>r) return 0;
    for(int i = 1;i<=97;i++) {
        tmp+=(ll)miu[i]*root(r,i);
    }
    ll res = 0;
    for(int i =1;i<=97;i++) {
        res+=(ll)miu[i]*root(l-1,i);
    }
    return tmp-res;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    mobius(100);
    debug(miu[6]);
    vector<int> prime;
    for(int i  = 2;i<=100;i++) {
        bool f= 0;
        for(int j =2;j<i;j++) {
            if(i%j==0) {
                f = 1;
                break;
            }
        }
        if(!f) prime.pb(i);
    }
    int n= nxt();
    while(n--) {
        ll l = lxt();
        ll r= lxt();
        ll ans = 0;
        if(l==1) {
            l++;
            ans++;
        }
        for(int i = 0;i<prime.size();i++) {
            ans+=go(l,r,prime[i]);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
