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
int ar[N];
int ans[N];
int temp[N];
int table[22][N];
int Log[N];
int index[N];
void RMQ_init(int n) {
    for(int i=0; i<n; i++)
        table[0][i] = ar[i];
    for(int i=2; i<=n; i++) Log[i]=1+Log[i/2];
    for(int i =1; i<20; i++)
        for(int j=0; j+(1<<(i-1))<n; j++)
            table[i][j]=max(table[i-1][j],table[i-1][j+(1<<(i-1))]);  /// j+1<<(i-1) means shifting index
                                                                      /// at j+2^(i-1)
}

int getmax(int i,int j) {
    if(j<i) return -inf;
    int k = Log[j-i+1];
    return max(table[k][i],table[k][j-(1<<k)+1]);

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    FOR(i,0,n) ar[i] = nxt(),index[ar[i]]= i;
     int mx = 0;
     for(int i = 0;i<n;i++) {
        mx = max(ar[i],mx);
        if(mx==ar[i]) ans[i]=1;
     }
     int tot = 0;
     for(int i = 0;i<n;i++) tot+=ans[i];
     RMQ_init(n);
     FOR(i,1,n) {
        int val = getmax(0,i);
        int ind = index[val];
        int mx = 0;
        mx = max(mx,getmax(0,ind-1));
        mx = max(mx,getmax(ind+1,i-1));
        if(ar[i]>mx&&ar[i]<val) {
//            debug(i);
//            debug(mx);
            temp[ind]++;
        }
     }
     int res = 0;
     for(int i = 0;i<n;i++) {
         if(ans[i]) {
            res = max(res,tot+temp[i]-1);
         } else {
            res  = max(res,tot+temp[i]);
         }
     }
     debug(tot);
     debug(res);
     int val = inf;
     for(int i = 0;i<n;i++) {
         int  x;
        if(ans[i]) {
            x = tot+temp[i]-1;
         } else {
            x  = tot+temp[i];
         }
        if(x==res){
            val = min(ar[i],val);
        }
     }
     //if(res<=1) val = *min_element(ar,ar+n);
     cout<<val<<endl;




    return 0;
}