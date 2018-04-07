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
char s[105][105];
int n,m;
struct info {
    int x,y;
    int cost;
    info(int _x,int _y,int _cost) : x(_x),y(_y),cost(_cost) {}
    bool operator< (const info& other) const{
        return cost>other.cost;
    }
};
int level[105][105];
int vis[105][105];
int dj(int i,int j) {
    for(int i = 0;i<n;i++) for(int j =0;j<m;j++) level[i][j] = inf,vis[i][j]=0;
    priority_queue<info> pq;
    pq.push(info(i,j,0));
    level[i][j] = 0;
    while(!pq.empty()) {
        info top= pq.top();
        if(top.x==0||top.x==n-1||top.y==0||top.y==m-1) return level[top.x][top.y];
        pq.pop();
        for(int k = 0;k<4;k++) {
            int nx = top.x+dx[k];
            int ny = top.y+dy[k];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&s[nx][ny]!='*'){
                int ncost= level[top.x][top.y]+(s[nx][ny]=='#');
                if(ncost<level[nx][ny]){
                    level[nx][ny]=ncost;
                    pq.push(info(nx,ny,ncost));
                }
            }
        }
    }

    return -1;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    int cs =1;
    while(test--) {
        n = nxt();
        m= nxt();
        for(int i = 0;i<n;i++) scanf("%s",s[i]);
        int res =-2;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(s[i][j]=='$') {
                    res =dj(i,j);
                    break;
                }
            }
            if (res>-2) break;
        }
        printf("Case %d: ",cs++);
        if(res==-1) printf("Impossible\n");
        else printf("%d\n",res);

    }

    return 0;
}
