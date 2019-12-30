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
ll ar[N];
struct Node{
    vector<ll> value;
    vector<ll> sum;
}tree[4*N];

void buildSegment_tree(int node,int low,int high) {
    if(low==high) {
        tree[node].value.pb(ar[low]);
        tree[node].sum.pb(ar[low]);
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    buildSegment_tree(left,low,mid);
    buildSegment_tree(right,mid+1,high);
    int sz=tree[left].value.size();
    int sz1=tree[right].value.size();
    tree[node].value.resize(sz+sz1);
    tree[node].sum.resize(sz+sz1);
    merge(tree[left].value.begin(),tree[left].value.begin()+sz,tree[right].value.begin(),tree[right].value.begin()+sz1,tree[node].value.begin());
    for(int i =0;i<tree[node].value.size();i++) {
        if(i==0) tree[node].sum[i] = tree[node].value[i];
        else tree[node].sum[i]+=tree[node].value[i]+tree[node].sum[i-1];
    }
}
ll query(int node,int low,int hi,int i,int j,long long val) {

    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j){
        int l = upper_bound(tree[node].value.begin(),tree[node].value.end(),val)-tree[node].value.begin();
        l--;
        if(l>=0&&l<tree[node].sum.size())return tree[node].sum[l];
        return 0;
    }

    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    ll x = query(left,low,mid,i,j,val);
    ll y = query(right,mid+1,hi,i,j,val);
    return x+y;
}

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    for(int i = 1;i<=n;i++) {
        ar[i] = lxt();
    }
    buildSegment_tree(1,1,n);
    int q= nxt();
    int x = 0;
    while(q--) {

        int l = nxt();
        int r =nxt();
        vector<ll> v;
        ll minMoney = lxt();
        ll lo = 1;
        ll hi = (ll)1e12;
        while(lo<=hi) {
            ll mid = (lo+hi)/2;
            ll totalMoney = query(1,1,n,l,r,mid);
            if(totalMoney>=minMoney) hi = mid-1;
            else lo = mid + 1;

        }
        ll totalMoney = query(1,1,n,l,r,lo);
        //debug(lo);
        if(totalMoney>=minMoney) {
            printf("%lld\n",totalMoney);
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
