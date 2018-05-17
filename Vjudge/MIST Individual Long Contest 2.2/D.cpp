 /// Bismillahir-Rahmanir-Rahim
#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               20010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (1e9)+1000
#define        eps                             1e-9
#define        ALL(x)                          x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T ison(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
//template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
inline ll lxt(){ll aaa;scanf("%lld",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}

///******************************************START******************************************
int ar[N];
map<pii,int> mp;
set<pii> adj[N];
vector<int> euler_cycle[N]; /// 0 based node
set<pii> st;
int tot = 0;
int m ;
vector<pii> edge;
void find_cycle(int u,int id) {
    while(adj[u].size()) {
        int it = (*adj[u].begin()).ss;
        int x = min(u,it);
        int y = max(u,it);
        if(st.find(make_pair(x,y))!=st.end()){
            adj[u].erase(adj[u].begin());
            continue;
        }
        ar[u]--;
        ar[it]--;
        tot++;
        if(tot>m) return ;
        st.insert(make_pair(x,y));
        find_cycle(it,id);
        break;
    }
    euler_cycle[id].pb(u);

}
bool cmp(int a,int b) {
    int x = ar[a]%2;
    int y = ar[b]%2;
    return x<y;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n= nxt();
    m= nxt();
    for(int i =0;i<m;i++) {
        int a = nxt();
        int b= nxt();
        a--;
        b--;
        ar[a]++;
        ar[b]++;
        edge.pb(make_pair(a,b));

    }
    for(int i =0;i<edge.size();i++) {
        int a= edge[i].ff;
        int b= edge[i].ss;
        adj[a].insert(make_pair(ar[b]%2,b));
        adj[b].insert(make_pair(ar[a]%2,a));
    }
    int id = 0;
    for(int i = 0;i<n;i++) {
        if(ar[i]%2&&tot<m) {
            find_cycle(i,id);
            id++;
        }
    }
    for(int i = 0;i<n;i++) if(ar[i]>=2&&tot<m){
        find_cycle(i,id++);

    }
    printf("%d\n",id);
    for(int i = 0;i<id;i++) {
        reverse(ALL(euler_cycle[i]));
        for(int j = 0;j<euler_cycle[i].size();j++) {
            if(j) printf(" ");
            printf("%d",euler_cycle[i][j]+1);
        }
        printf("\n");
    }


    return 0;
}
