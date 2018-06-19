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
int mat[200][200];
void  reset(int n){
   FOR(i,0,n+1) FOR(j,0,n+1) mat[i][j]=inf;
   mat[0][0] = 0;

 }
void warshall(int n){
   FOR(k,0,n+1) FOR(i,0,n+1) FOR(j,0,n+1)
       if(mat[i][k]+mat[k][j]<mat[i][j]) mat[i][j]=mat[i][k]+mat[k][j];
}
vector<pair<int,int> > v;
int  dp[13][(1<<13)+5];
int vis[13][(1<<13)+5];
int mark[100];
int cnt ;
int go(int cur,int mask,int cs) {

    if(mask==(1<<cnt)-1){
        return mat[cur][0];
    }
    int &res = dp[mark[cur]][mask];
    int &vs = vis[mark[cur]][mask];
    if(vs==cs) return res;
    vs = cs;
    res = inf;
    for(int  i = 0;i<cnt;i++) {
        if(ison(mask,mark[v[i].ff])) continue;
        res = min(res,go(v[i].ff,biton(mask,mark[v[i].ff]),cs)+mat[cur][v[i].ff]);
        //res = min(res,go(cur,biton(mask,mark[v[i].ff]),cs)+v[i].ss);
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
    int test =nxt(); int cs=0;
    while(test--) {

        int n= nxt();
        int m =nxt();
        reset(n);
        for(int i = 0;i<m;i++) {
            int a= nxt();
            int b = nxt();
            int D,C;
            char c;
            scanf("%d%c%d",&D,&c,&C);
            mat[a][b] =min(mat[a][b],D*100+C);
            mat[b][a] = min(mat[b][a],mat[a][b]);
        }
        warshall(n);
        int sp = nxt();
        int tot= 0;
        int given[55]={0};
        int visited[55]={0};
        for(int i =0;i<sp;i++){
            int a = nxt();
            visited[a] = 1;
            int D,C;
            char c;
            scanf("%d%c%d",&D,&c,&C);
            int dx = D*100+C;
            given[a]+=dx;
            tot+=dx;

        }
        for(int i =0;i<55;i++) if(visited[i]) v.pb(make_pair(i,given[i]));
        sort(ALL(v));
        cnt = 0;
        for(int i = 0;i<v.size();i++) mark[v[i].ff] = cnt++;
        int res = inf;
        cs++;
        for(int i = (1<<cnt)-1;i>=0;i--) {
            int tmp = 0;
            for(int j = 0;j<cnt;j++) if(ison(i,j)) tmp+=v[j].ss;
            res = min(res,go(0,i,++cs)+tmp);
        }
      //  debug(tot,res);
        if(res<tot) {
            printf("Daniel can save $%0.2f\n",(double)(tot-res)/100);
        } else printf("Don't leave the house\n");
        v.clear();
        CLR(mark);

    }



    return 0;
}
