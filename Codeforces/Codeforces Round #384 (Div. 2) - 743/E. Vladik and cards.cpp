 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1005
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
int Next[N][N];
int ar[N];
int mid ;
int n;
int dp[N][1<<8][4];
int go(int pos,int mask,int flag) {
    if(pos==n) {
        if(mid==0) {
            return 0;
        } else if(mid==1) {
            if(flag==2) {
                if(mask==(1<<(8))-1) return 0;
                return -inf;
            } else if(flag==1||flag==3) {
                return 0;
            } else {
                return -inf;
            }
        }
        if(mask==(1<<(8))-1) return 0;
        return -inf;
    }
    if(pos>n) return -inf;
    int &res = dp[pos][mask][flag];
    if(res!=-1) return res;
    res = go(pos+1,mask,flag);
    if(ison(mask,ar[pos])==0) {
        if(flag==0) {
            res= max(res,go(Next[pos][mid]+1,biton(mask,ar[pos]),1)+mid);
        } else if(flag==1) {
            res= max(res,go(Next[pos][mid]+1,biton(mask,ar[pos]),1)+mid);
            res= max(res,go(Next[pos][mid+1]+1,biton(mask,ar[pos]),2)+mid+1);
            if(mid)
                res= max(res,go(Next[pos][mid-1]+1,biton(mask,ar[pos]),3)+mid-1);
        } else if(flag==2) {
            res= max(res,go(Next[pos][mid]+1,biton(mask,ar[pos]),flag)+mid);
            res= max(res,go(Next[pos][mid+1]+1,biton(mask,ar[pos]),flag)+mid+1);

        } else {
            res= max(res,go(Next[pos][mid]+1,biton(mask,ar[pos]),flag)+mid);
            res= max(res,go(Next[pos][mid-1]+1,biton(mask,ar[pos]),flag)+mid-1);

        }
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

    n =nxt();
    FOR(i,0,n) ar[i] =nxt()-1;
    FOR(i,0,n) FOR(j,0,n) Next[i][j] = n+5;
    FOR(i,0,n) {
        int cnt = 0;
        Next[i][0]=i-1;
        for(int j = i;j<n;j++) {
            if(ar[i]==ar[j]) {
                cnt++;
                Next[i][cnt] = j;
            }
        }
    }

    int lo = 0;
    int hi = n;
    while(lo<=hi) {

        mid = (lo+hi)/2;
        SET(dp);
        if(go(0,0,0)>=0) {
            lo = mid+1;
        } else hi = mid-1;
    }
    lo--;
    int ans =0;
    for(int  i =max(0,lo-1);i<=lo;i++) {
        mid=i;
        SET(dp);
       ans= max(ans,go(0,0,0));
    }

    cout<<ans<<endl;
    return 0;
}
