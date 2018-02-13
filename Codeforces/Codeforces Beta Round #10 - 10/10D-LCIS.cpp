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
int br[N];
map<int,int> mp;
int value[505];
int dp[505][505];
int tree[505][1005];
void update(int x,int y,int val,int lim1,int lim2) {
    for(int i = x;i<=lim1;i+=i&-i){
        for(int j= y;j<=lim2;j+=j&-j){
            tree[i][j] = max(tree[i][j],val);
        }
    }
}
int query(int x,int y) {
    int mx = 0;
    for(int i = x;i>0;i-=i&-i) {
        for(int j = y;j>0;j-=j&-j) {
            mx = max(mx,tree[i][j]);
        }
    }
    return mx;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    for(int i = 1;i<=n;i++) {
        ar[i] = nxt();
        mp[ar[i]] = 0;
    }
    int m = nxt();
    for(int i = 1;i<=m;i++){
        br[i] = nxt();
        mp[br[i]] = 0;
    }
    int rnk = 1;
    for(auto it : mp) {
        mp[it.ff] = rnk;
        rnk++;
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++) {
            if(ar[i]==br[j]) {
                dp[i][j] = query(j-1,mp[ar[i]]-1)+ 1;
                update(j,mp[ar[i]],dp[i][j],m,rnk);
                //debug(dp[i][j],i,j);
                ans = max(ans,dp[i][j]);
            }
        }
    }
    printf("%d\n",ans);
    vector<int> v;
    int last = inf;
    int lastind = m;
    for(int i = n;i>=1;i--) {
        for(int j = lastind;j>=1&&ans;j--) {
            if(dp[i][j]==ans&&ar[i]==br[j]&&ar[i]<last) {
                v.pb(ar[i]);
                ans--;
                last = ar[i];
                lastind = j-1;
                debug(i,j);
                break;
            }
        }
    }
    reverse(ALL(v));
    for(int i = 0;i<v.size();i++) {
        if(i) printf(" ");
        printf("%d",v[i]);
    }
    printf("\n");

    return 0;
}