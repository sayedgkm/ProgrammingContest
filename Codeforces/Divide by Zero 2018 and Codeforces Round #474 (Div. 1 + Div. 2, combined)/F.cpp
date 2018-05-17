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
class info{
    public:
    vector<int> tree;
    void init(int n) {
        tree.resize(4*n);
    }
    void update(int node,int low,int hi,int i,int value){

       if(low==hi){
        tree[node]=max(tree[node],value); return;
       }
       int mid=(low+hi)/2;
       int left=2*node;
       int right=left+1;
       if(i<=mid)
          update(left,low,mid,i,value);
       else
          update(right,mid+1,hi,i,value);
       tree[node]=max(tree[left],tree[right]);
    }
    ll query(int node,int low,int hi,int i,int j){
        if(i>hi||j<low) return 0;
        if(low>=i&&hi<=j)
          return tree[node];
        int mid=(low+hi)/2;
        int left=2*node;
        int right=left+1;
        return max(query(left,low,mid,i,j),
       query(right,mid+1,hi,i,j));

    }
};
int ar[N];
vector<info> all;
vector<pair<pair<int,int>,int> > edge;
map<pii,int> mp;
map<pii,int> :: iterator it;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    int n =nxt();
    int m = nxt();
    all.resize(n+1);
    for(int i = 0;i<m;i++) {
        int a= nxt();
        int b = nxt();
        int c = nxt();
        mp[pii(a,c)] = 0;
        mp[pii(b,c)] = 0;
        edge.pb(make_pair(make_pair(a,b),c));
    }
    int prev=-1;
    int cnt = 1;
    for(it = mp.begin();it!=mp.end();it++) {
        int val = (it->ff).ff;
        if(val!=prev) {
            cnt = 1;
            mp[it->ff] = cnt;
        } else {
            mp[it->ff] = cnt;
        }
        prev = val;
        cnt++;

    }
    for(it = mp.begin();it!=mp.end();it++) {
        int val = (it->ff).ff;
        ar[val] = max(it->ss,ar[val]);
    }
    all.resize(100001);
    for(int i = 1;i<=100000;i++) {
        if(ar[i]) {
            all[i].init(ar[i]+5);
        }
    }

    int ans = 0;
    for(int i = edge.size()-1;i>=0;i--) {
        int a= edge[i].ff.ff;
        int b = edge[i].ff.ss;
        int c = edge[i].ss;
        int id = mp[make_pair(a,c)];
        int id1 = mp[make_pair(b,c)];
        int val= all[b].query(1,1,ar[b],id1+1,ar[b]);
        ans= max(ans,val+1);
        val+=1;
        all[a].update(1,1,ar[a],id,val);
    }
    cout<<ans<<endl;
    return 0;
}
