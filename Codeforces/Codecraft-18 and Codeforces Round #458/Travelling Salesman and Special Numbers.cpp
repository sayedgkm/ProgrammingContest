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
int go(ll x){
    int c = 0;
    while(x!=1){
        x = __builtin_popcount(x);
        c++;
    }
    return c;
}
int lagbe[N];
string s;
ll dp[1005][1010][3];
int vis[1005][1010][3];
int k;
int cs ;
int mx = 0;
ll go(int pos,int cnt,int isSmall){
      if(pos>=s.length()){
         return cnt==0;
      }
      ll &res = dp[pos][cnt][isSmall];
      if(vis[pos][cnt][isSmall]==cs) return res;
      vis[pos][cnt][isSmall] = cs;
      res = 0;
      int limit=isSmall?1:s[pos]-'0';
      for(int i = 0;i<=limit;i++){
        res += go(pos+1,cnt-(i==1),isSmall|i<(s[pos]-'0'));
        res%=M;
      }
      return res;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    for(int i = 1;i<N;i++){
        lagbe[i] = go(i)+1;
    }

    cin>>s;

    cin>>k;
    if(k==0){
        cout<<1<<endl;
        return 0 ;
    }
    SET(dp);
    ll ans =  0;
    for(int i = 1;i<=1005;i++){
        if(lagbe[i]==k){
            cs++;
            ans+=go(0,i,0);
            ans%=M;
        }
    }
    if(k==1){
        ans--;
    }
    ans+=M;
    ans%=M;
    cout<<ans<<endl;


    return 0;
}