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
int oddA[N],oddB[N],oddQ[N];
int evenA[N],evenB[N],evenQ[N];
int n;
pii dp[N];
int cost(int i,int m) {
    int j = i+m-1;
    if(j>n) return inf;
    int a,b,qa,qb;
    if(i%2) {
      //  debug(j);
      //  debug(oddA[j]);
        a = oddA[j]-oddA[i-1];
        b = evenB[j]-evenB[i-1];
        qa = oddQ[j]-oddQ[i-1];
        qb = evenQ[j]-evenQ[i-1];
    } else {
        a = evenA[j]-evenA[i-1];
        b = oddB[j]-oddB[i-1];
        qa = evenQ[j]-evenQ[i-1];
        qb = oddQ[j]-oddQ[i-1];
    }
    int needa = (m+1)/2;
    int needb = m/2;
   // debug(a,b,qa,qb);
   // debug(needa,needb);
    int cost = 0 ;
    if(a<needa) {
        if(a+qa>=needa){
            cost+=needa-a;
        } else return inf ;
    }
    if(b<needb) {
        if(b+qb>=needb) {
            cost+=needb-b;
        } else return inf;
    }
    return cost;
}
pii go(pii a,pii b,int c) {
    a.ff++;
    a.ss+=c;
    if(a.ff>b.ff) return a;
    if(a.ff<b.ff) return b;
    if(a.ff==b.ff) {
        if(a.ss<b.ss) return a;
        else return b;
    }
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m;
    string s;
    cin>>n>>s>>m;
    s="." +s;
    FOR(i,1,n+1) {
        if(i%2){
            if(s[i]=='a') oddA[i]++;
            if(s[i]=='b') oddB[i]++;
            if(s[i]=='?') oddQ[i]++;
        } else {
            if(s[i]=='a') evenA[i]++;
            if(s[i]=='b') evenB[i]++;
            if(s[i]=='?') evenQ[i]++;
        }
        oddA[i]+=oddA[i-1];
        oddB[i]+=oddB[i-1];
        oddQ[i]+=oddQ[i-1];
        evenA[i]+=evenA[i-1];
        evenB[i]+=evenB[i-1];
        evenQ[i]+=evenQ[i-1];

    }
    dp[n+1] = make_pair(0,0);
    for(int i = n;i>=1;i--) {
        int c = cost(i,m);
        if(c<inf) {
            dp[i] = go(dp[i+m],dp[i+1],c);
        } else {
            dp[i] = dp[i+1];
        }
    }
    cout<<dp[1].ss<<endl;

    return 0;
}