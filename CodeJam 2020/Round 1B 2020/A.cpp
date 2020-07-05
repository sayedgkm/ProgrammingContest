
///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
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
long long two[70];
map<pll, pll> parent;
bool bfs(long long x, long long y) {

    set<pll> visited;
    visited.insert(make_pair(0,0));
    queue<pair<pll, int> > q;
    q.push(make_pair(make_pair(0,0),-1));
    while(!q.empty()) {

        ll xx = q.front().first.first;
        ll yy = q.front().first.second;
        int step = q.front().second;
        q.pop();
        if(xx==x && yy==y) {
            return true;
        }
        step++;

        for(int i = 0;i<4;i++) {
            ll nx = xx + two[step]*(ll)dx[i];
            ll ny = yy + two[step]*(ll)dy[i];
            if(abs(nx)> abs(x) || abs(ny) > abs(y)) continue;
            if(visited.find(make_pair(nx, ny))!=visited.end()) continue;
            visited.insert(make_pair(nx, ny));
            q.push(make_pair(make_pair(nx, ny), step));
            parent[make_pair(nx, ny)] = make_pair(xx, yy);
        }

    }

    return false;

}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

    two[0] = 1;
    for(int i = 1;i<=60;i++) {
        two[i] = two[i-1]*2LL;
    }
    int test =nxt(); int cs = 1;
    while(test--) {

        int x = nxt();
        int y = nxt();

        bool res = bfs(x, y);
        if(res) {
            string ans;
            while(true) {

                if(x==0 && y==0) break;

                pll p = parent[make_pair(x,y)];
                ll px = p.first;
                ll py = p.second;
                if(px<x) {
                    ans+="E";
                }
                if(px>x) {
                    ans+="W";
                }

                if(py>y) {
                    ans+= "S";
                }
                if(py<y) {
                    ans+="N";
                }

                x = px;
                y = py;

            }
            reverse(ans.begin(), ans.end());
            printf("Case #%d: ",cs++);
            cout<<ans<<endl;
        } else {
            printf("Case #%d: IMPOSSIBLE\n", cs++);
        }
        parent.clear();
    }

     return 0;
}

