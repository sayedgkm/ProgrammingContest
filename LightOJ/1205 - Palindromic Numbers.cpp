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
int ar[N];
vector<int> v;
ll dp[20][2][2][20];
ll go(int pos,int len,int baki) {
    //debug(pos,len,baki);
    ll num = 0;
    for(int i = pos-len;i<v.size();i++) num*=10,num+=v[i];
    ll palin = 0;
    for(int i = pos-len;i<pos;i++) palin*=10,palin+=v[i];
    ll tmp;
    if(baki==len)
         tmp = palin;
    else tmp = palin/10;
        while(tmp) {
            palin*=10;
            palin+=tmp%10;
            tmp/=10;
        }
    return palin<=num;

}
ll go(int pos,int isSmall,int isStart,int len){
    int baki = v.size()-pos;
   // if(baki==0&&len==0) return 0;
    if(len==baki||len-1==baki) {
        if(!isStart) return 0;
        if(isSmall) return 1;
        return go(pos,len,baki);
    }

    int limit = isSmall?9:v[pos];
    ll &res =dp[pos][isSmall][isStart][len];
    if(res!=-1) return res;
    res = 0;
    for(int i = 0;i<=limit;i++){
        res+=go(pos+1,isSmall|(i<limit),isStart|i>0,len+(isStart|i>0));
    }
    return res;
}
ll f(ll n) {
    if(n==-1) return 0;
    v.clear();
    while(n) {
        v.pb(n%10);
        n/=10;
    }
    reverse(ALL(v));
    SET(dp);
    return go(0,0,0,0);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();int cs = 1;
    while(test--) {
        ll a = lxt();
        ll b= lxt();
        if(a>b) swap(a,b);
        printf("Case %d: %lld\n",cs++,f(b)-f(a-1)+(a==0));

    }


    return 0;
}
