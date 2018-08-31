 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               500
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
int color[N];
vector<int>adj1[N];
int one,two;
int bfs(int st) {
    color[st] = 1;
    one++;
    queue<int> q;
    q.push(st);
    while(!q.empty()) {

        int u = q.front();
        q.pop();
        for(int i = 0;i<adj1[u].size();i++) {
            int v= adj1[u][i];
            if(color[v]==0) {
                if(color[u]==1) {
                    color[v] = 2;
                    two ++;
                } else color[v] = 1,one++;
                q.push(v);
            } else {
                if(color[u]==color[v]) return -1;
            }
        }
    }
    return true;
}

int main(){
    #ifdef sayed
   // freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--) {

        int n =nxt();
        int m = nxt();
        for(int i = 0;i<m;i++) {
            int a= nxt();
            int b= nxt();
          //  if(a==b) continue;
            adj1[a].pb(b);
            adj1[b].pb(a);
        }
        int res ;
        int ans = 0;
        for(int i = 0;i<n;i++) {
            if(!color[i]) {
                one = 0;
                two =0;
                res = bfs(i);
                ans+=min(one,two);
                if(two==0) ans++;
                if(res==-1) break;
            }

        }
        if(res==-1) printf("-1\n");
        else {
          printf("%d\n",ans);

        }

        CLR(color);
        for(int i=0;i<N;i++) {
            adj1[i].clear();

        }



    }

    return 0;
}
