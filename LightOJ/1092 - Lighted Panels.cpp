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
int grid[10][10];
int n,m;
bool isvalid(int i,int j) {
    if(i>=0&&i<n&&j>=0&&j<m) return true;
    return false;
}
int go(int rowMask,int colMask) {
    int cnt = 0;
    int ar[10][10];
    for(int i =0;i<n;i++) for(int j =0;j<m;j++) ar[i][j] = grid[i][j];
    for(int i = 0;i<n;i++) {
        if(ison(rowMask,i)) {
            cnt++;
            ar[i][0]^=1;
            for(int j = 0;j<8;j++) {
                if(isvalid(i+dx[j],0+dy[j])) {
                    ar[i+dx[j]][0+dy[j]]^=1;
                }
            }
        }
    }

      for(int i = 0;i<m;i++) {
        if(ison(colMask,i)) {
            cnt++;
            ar[0][i]^=1;
            for(int j = 0;j<8;j++) {
                if(isvalid(0+dx[j],i+dy[j])) {
                    ar[0+dx[j]][i+dy[j]]^=1;
                }
            }
        }
    }
    for(int i = 1;i<n;i++) {
        for(int j = 1;j<m;j++) {
            if(ar[i-1][j-1]==0) {
                ar[i][j]^=1;
                cnt++;
                for(int k = 0;k<8;k++) {
                    if(isvalid(i+dx[k],j+dy[k])) {
                        ar[i+dx[k]][j+dy[k]]^=1;
                    }
                }
            }
        }
    }
    for(int i =0;i<n;i++) {
        for(int j =0;j<m;j++) {
            if(ar[i][j]==0) return inf;
        }
    }
    return cnt;
}
int main(){
    #ifdef sayed
    freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test =nxt();
    int cs = 1;
    while(test--) {
        n =nxt();
        m = nxt();
        CLR(grid);
        for(int i = 0;i<n;i++){
            char t[10];
            scanf("%s",t);
            int len = strlen(t);
            for(int j = 0;j<len;j++) {
                if(t[j]=='.') grid[i][j]=0;
                else grid[i][j] = 1;
            }
        }
        int res = inf;
        for(int i = 0;i<(1<<n);i++) {
            for(int j = 0;j<(1<<m);j++) {
              //  debug(i,j);
                res =min(res,go(i,j));
            }
        }
        printf("Case %d: ",cs++);
        if(res==inf) printf("impossible\n");
        else printf("%d\n",res);
    }


    return 0;
}
