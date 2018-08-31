 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               200010
#define        M                               1000007
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
int dp[1005][1005];
char s1[1005],s2[1005];
int len1,len2;
int go(int i,int j){
    if(i==len1||j==len2) return dp[i][j]=0;
    int &res = dp[i][j];
    if(res!=-1) return res;
    res = 0;
    if(s1[i]==s2[j]) res = max(res,go(i+1,j+1)+1);
    else res = max(res,max(go(i+1,j),go(i,j+1)));
    return res;
}
int Next1[1005][26];
int Next2[1005][26];
int cnt[26];
int dp1[1005][1005];
int go1(int i,int j) {
    int lc = go(i,j);
    if(lc==0)return 1;
    int &res = dp1[i][j];
    if(res!=-1) return res;
    res = 0;
    for(int x = 0;x<26;x++) {
        if(Next1[i][x]<=len1 && Next2[j][x]<=len2&&go(Next1[i][x],Next2[j][x])==lc-1)
            res+=go1(Next1[i][x],Next2[j][x]);
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
    int test =nxt();
    int cs =1;
    while(test--) {
        scanf("%s%s",s1,s2);
        len1 = strlen(s1);
        len2= strlen(s2);
        SET(dp);
        CLR(cnt);
        CLR(Next1);
        CLR(Next2);
        for(int i = 0;i<26;i++) cnt[i] = len1+5;
        for(int i = len1-1;i>=0;i--) {
            cnt[s1[i]-'a'] = i;
            for(int j = 0;j<26;j++) Next1[i][j]= cnt[j]+1;
        }
        for(int i = 0;i<26;i++) cnt[i] = len2+5;
        for(int i = len2-1;i>=0;i--) {
            cnt[s2[i]-'a'] = i;
            for(int j = 0;j<26;j++) Next2[i][j]= cnt[j]+1;
        }
        SET(dp1);
        printf("Case %d: %d\n",cs++,go1(0,0));

    }

    return 0;
}
