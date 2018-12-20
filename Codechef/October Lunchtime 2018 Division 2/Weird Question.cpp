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
vector<int> tree[4*N];
 vector<int> filter;
///Each of tree nodes keep all values sorted from index low to high
void buildSegment_tree(int node,int low,int high) {
    if(low==high) {
        tree[node].clear();
        tree[node].pb(ar[filter[low]]);
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    buildSegment_tree(left,low,mid);
    buildSegment_tree(right,mid+1,high);
    int sz=tree[left].size();
    int sz1=tree[right].size();
    //tree[node].clear();
    tree[node].resize(sz+sz1);
    merge(tree[left].begin(),tree[left].begin()+sz,tree[right].begin(),tree[right].begin()+sz1,tree[node].begin());
}
int query(int node,int low,int hi,int i,int j,int val) {
    /// returns how many numbers are less than or equal to value
    /// from index i to j
    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j){
       // debug(low,hi,tree[node].size(),node);
        return lower_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
    }
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    int x= query(left,low,mid,i,j,val);
    int y= query(right,mid+1,hi,i,j,val);
    return x+y;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int test = nxt();
    while(test--) {
        int n = nxt();
        filter.pb(0);
        for(int i = 0;i<n;i++) {
            int a= nxt();
            if(ar[a]==0) filter.pb(a);
            ar[a]++;

        }
        sort(ALL(filter));
        buildSegment_tree(1,1,filter.size()-1);
        ll res = 0;
        for(int i =1;i<filter.size();i++) {
            int oc = ar[filter[i]];
            int l = upper_bound(ALL(filter),oc)-filter.begin();
            l--;
            res+=l-query(1,1,filter.size()-1,1,l,filter[i]);
            //debug(l,filter[i],res);
        }
        printf("%lld\n",res);
        for(auto it : filter) ar[it] =0;
        for(int i =0;i<4*(int)filter.size();i++) tree[i].clear();
        filter.clear();

    }


    return 0;
}
