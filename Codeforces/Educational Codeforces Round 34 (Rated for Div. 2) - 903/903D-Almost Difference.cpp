//====================================
//======================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
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
inline long double dxt(){long double aaa;scanf("%lf",&aaa);return aaa;}
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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
 ll ar[N];vector<ll> tree[4*N];
 vector<double> sum[4*N];
 void make(int node) {
    sum[node].resize((int)tree[node].size());
    sum[node][0] = (long double)tree[node][0];
    for(int i = 1;i<tree[node].size();i++) {
        sum[node][i] += sum[node][i-1]+(long double)tree[node][i];
    }

 }
void buildSegment_tree(int node,int low,int high) {
    if(low==high) {
        sum[node].pb((long double)ar[low]);
        tree[node].pb(ar[low]);
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    buildSegment_tree(left,low,mid);
    buildSegment_tree(right,mid+1,high);
    int sz=tree[left].size();
    int sz1=tree[right].size();
    tree[node].resize(sz+sz1);
    merge(tree[left].begin(),tree[left].begin()+sz,tree[right].begin(),tree[right].begin()+sz1,tree[node].begin());
    make(node);
}
long double mxsum,mxcnt , mncnt,mnsum;
void query(int node,int low,int hi,int i,int j,ll val) {
    /// returns how many numbers are less than or equal to value
    /// from index i to j
    if(i>hi||j<low) return;
    if(low>=i&&hi<=j){
       // debug(low,hi);
        int l = upper_bound(ALL(tree[node]),val-2)-tree[node].begin();
        l--;
        if(l>=0) {
            mnsum+=sum[node][l];
            mncnt+=(l+1);
        }
        //debug(l);
        l = lower_bound(ALL(tree[node]),val+2)-tree[node].begin();
        int r = tree[node].size()-1;
        //debug(l,r);
        if(r>=l)
        mxsum += sum[node][r];
        if(l>0&&r>=l) mxsum-=sum[node][l-1];
        mxcnt+=r-l+1;
        return;
    }

    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    query(left,low,mid,i,j,val);
     query(right,mid+1,hi,i,j,val);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
   // cout<<LLONG_MAX-(ll)9999999990000000000<<endl;
    int n = nxt();
    FOR(i,1,n+1) {
        ar[i] = lxt();
    }
    buildSegment_tree(1,1,n);
    long double ans = 0;
    FOR(i,1,n) {
        mxsum = mnsum = mxcnt = mncnt= 0;
        query(1,1,n,i+1,n,ar[i]);
        ans+=mxsum-(long double)ar[i]*mxcnt;
        ans-=(long double)ar[i]*mncnt-mnsum;
    }
    cout<<setprecision(0)<<fixed<<ans<<endl;

    return 0;
}