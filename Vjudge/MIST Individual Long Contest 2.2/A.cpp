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
map<pii,int> mp;
vector<int> adj[N];
vector<int> euler_cycle; /// 0 based node
void find_cycle(int u) {

    for(int i =0;i<adj[u].size();i++) {
        int it = adj[u][i];
        if(mp[make_pair(u,it)]==0) continue;
        mp[make_pair(u,it)]--;
        find_cycle(it);
    }
    euler_cycle.pb(u);

}
int in[N],out[N];
bool is_euler_cycle(int n) {
    for(int i =0;i<n;i++) {
        if(in[i]!=out[i]) return false;
    }
    return true;
}
bool is_euler_path(int n) {
    int odd = 0;
    int even = 0;
    for(int i =0;i<n;i++){
        if(in[i]==out[i]) even++;
        else {
            if(abs(in[i]-out[i])>1) return false;
            odd++;
        }
    }
    return odd==2;
}
string s[1005];
char t[30];
vector<int> v[27][27];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt(); int cs = 1;
    while(test--){
        int n= nxt();
        for(int i = 0;i<n;i++) {
            scanf("%s",t);
            s[i] = t;
        }
      //  debug("ok");
        for(int i = 0;i<n;i++) {
            int a = s[i][0]-'a';
            int b = s[i][s[i].size()-1]-'a';
            mp[make_pair(a,b)]++;
            adj[a].pb(b);
            v[a][b].pb(i);
            in[b]++;
            out[a]++;
        }
        printf("Case %d: ",cs++);
        bool flag = 0;
        if(is_euler_cycle(26)) {
            int a = -1;
            for(int i =0;i<26;i++) if(in[i]>0) {a= i;break;}
            find_cycle(a);
            reverse(ALL(euler_cycle));
            //euler_cycle.pop_back();
        } else if(is_euler_path(26)){
            int a = -1;
            int b = -1;
            for(int i = 0;i<26;i++){
                if(in[i]!=out[i]){
                    if(a==-1) a= i;
                    else b = i;
                }
            }
            if(out[a]<in[a]) swap(a,b);
            find_cycle(a);
            reverse(ALL(euler_cycle));
        } else {
            flag = 1;
        }
        if(euler_cycle.size()!=n+1) flag= 1;
        if(flag==1) printf("No\n");
        else {
            printf("Yes\n");

            for(int i =0;i<euler_cycle.size()-1;i++) {
                if(i) printf(" ");
                int a = euler_cycle[i];
                int b = euler_cycle[i+1];

                printf("%s",s[v[a][b].back()].c_str());
                v[a][b].pop_back();
            }
            printf("\n");
        }
        CLR(in);CLR(out);
        euler_cycle.clear();
        mp.clear();
        for(int i =0;i<27;i++) adj[i].clear();
        for(int i =0;i<27;i++) for(int j = 0;j<27;j++) v[i][j].clear();
    }




    return 0;
}


