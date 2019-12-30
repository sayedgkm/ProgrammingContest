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
int ar[N][4];
vector<int> adj[N];
map<pii,int> mp;
int visited[N];
bool isFound(int x, int temp[]) {
    for(int i =0;i<3;i++) {
        if(temp[i]==x) return true;
    }
    return false;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n = nxt();
    for(int i = 1;i<=n-2;i++) {
        vector<int> v(3);
        for(int j=0;j<3;j++) v[j] = nxt(),ar[i][j] = v[j];
        sort(ALL(v));
        pii a =make_pair(v[0],v[1]);
        if(mp.count(a)){
            adj[mp[a]].push_back(i);
            adj[i].push_back(mp[a]);
        }
        mp[a] = i;
        a =make_pair(v[0],v[2]);
        if(mp.count(a)){
            adj[mp[a]].push_back(i);
            adj[i].push_back(mp[a]);
        }
        mp[a] = i;
        a =make_pair(v[1],v[2]);
       // if(v[1]==2&&v[2]==4) debug(mp[a],i);
        if(mp.count(a)){
            adj[mp[a]].push_back(i);
            adj[i].push_back(mp[a]);
        }
        mp[a] = i;
    }
    int st = -1;
    for(int i = 1;i<=n-2;i++) {
        if(adj[i].size() == 1) {
            st = i;
            break;
        }
    }
    //debug(st);
    visited[st] = 1;
    vector<int> v;
    v.push_back(st);
    debug(adj[1].size());
    while(true) {
        bool f = 0;
        for(int i = 0;i<adj[st].size();i++) {
            int xx  = adj[st][i];
            if(visited[xx]) continue;
            visited[xx] = 1;
            v.push_back(xx);
            st = xx;
            f = 1;
        }
        if(!f) break;
    }
    for(auto it : v) debug(it);
    vector<int> answer;
    for(int i = 0;i<v.size();i++) {
        if(i==0) {
            int id = v[0];
            int id1 = v[1];
            int id2 = v[2];
            if(!isFound(ar[id][0],ar[id1])){
                answer.push_back(ar[id][0]);
                if(!isFound(ar[id][1],ar[id2])) {
                    answer.push_back(ar[id][1]);
                    answer.push_back(ar[id][2]);
                } else {
                    answer.push_back(ar[id][2]);
                    answer.push_back(ar[id][1]);
                }


            } else if(!isFound(ar[id][1],ar[id1])){
                answer.push_back(ar[id][1]);
                if(!isFound(ar[id][0],ar[id2])) {
                    answer.push_back(ar[id][0]);
                    answer.push_back(ar[id][2]);
                } else {
                    answer.push_back(ar[id][2]);
                    answer.push_back(ar[id][0]);
                }

            } else if(!isFound(ar[id][2],ar[id1])){
                answer.push_back(ar[id][2]);
                 if(!isFound(ar[id][0],ar[id2])) {
                   answer.push_back(ar[id][0]);
                    answer.push_back(ar[id][1]);
                } else {
                    answer.push_back(ar[id][1]);
                    answer.push_back(ar[id][0]);
                }

            }
        } else {
            int id = v[i];
            int prev = v[i-1];
            for(int j = 0;j<3;j++) {
                if(!isFound(ar[id][j],ar[prev])) {
                    answer.push_back(ar[id][j]);
                    break;
                }
            }

        }
    }
    for(auto it : answer) {
        printf("%d ",it);
    }
    printf("\n");

    return 0;
}
