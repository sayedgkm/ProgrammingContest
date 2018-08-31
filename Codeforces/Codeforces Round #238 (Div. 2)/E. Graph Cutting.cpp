 /// Bismillahir-Rahmanir-Rahim
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
vector<int> re[N];
int deg[N];
map<pii,int > mp;
vector<int > v;

multiset<pii> st;
multiset<int> adj[N];
vector<int> euler_cycle; /// 0 based node
void find_cycle(int u) {
    while(adj[u].size()) {
        int it = *adj[u].begin();
        int x= min(u,it);
        int y =max(u,it);
        adj[u].erase(adj[u].find(it));
        adj[it].erase(adj[it].find(u));
        find_cycle(it);
    }
    euler_cycle.pb(u);

}
vector<int> after_cut[N];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int m = nxt();
    FOR(i,0,m) {
        int a= nxt()-1;
        int b= nxt()-1;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }
    if(m%2) {
        printf("No solution\n");
        return 0;
    }
    for(int i = 0;i<n;i++) {
        if(deg[i]%2) v.pb(i);
    }
    for(int i = 1;i<v.size();i+=2) {
        adj[v[i-1]].insert(v[i]);
        adj[v[i]].insert(v[i-1]);
        mp[make_pair(v[i],v[i-1])] = 1;
        mp[make_pair(v[i-1],v[i])] = 1;
    }
    find_cycle(0);
    int ind = 0;
    for(int i = 0;i<euler_cycle.size();i++) {
        if(i) {
            if(mp[make_pair(euler_cycle[i],euler_cycle[i-1])]) {
                ind++;
                mp[make_pair(euler_cycle[i],euler_cycle[i-1])]=0;
                mp[make_pair(euler_cycle[i-1],euler_cycle[i])]=0;
            }
        }
        after_cut[ind].pb(euler_cycle[i]);
    }
//    for(int i = 0;i<=ind;i++) {
//        for(auto it : after_cut[i]) {
//            printf("%d ",it+1);
//        }
//        printf("\n");
//    }
    for(int i = 0;i<=ind;i++) {
        if(after_cut[i].size()==1) continue;
        else if(after_cut[i].size()%2==0) {
            int x = after_cut[i].back();
            after_cut[i].pop_back();
            int y = after_cut[i].back();
            debug(x,y);
            re[x].pb(y);
            re[y].pb(x);
        } else
        for(int j = 2;j<after_cut[i].size();j+=2) {
            printf("%d %d %d\n",after_cut[i][j-2]+1,after_cut[i][j-1]+1,after_cut[i][j]+1);
        }

    }
//    for(int i = 0;i<n;i++) {
//        while(re[i].size()) {
//            int b = re[i].back();
//
//            re[i].pop_back();
//            if(re[i].size()) {
//                printf("%d %d %d\n",b+1,i+1,re[i].back()+1);
//                re[i].pop_back();
//
//            } else if(re[b].size()){
//
//                int c = re[b].back();
//                re[b].pop_back();
//                printf("%d %d %d\n",i+1,b+1,c+1);
//
//            }
//        }
//    }

    return 0;
}

