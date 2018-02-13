/// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               300010
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
struct info
{
    ll sum;
    ll two;
    ll one;

} tree[N*4];
void segment_tree(int node,int low,int high)
{
    if(low==high)
    {
        tree[node].sum=ar[low];
        if(ar[low]==1) tree[node].one = 1;
        if(ar[low]==2) tree[node].two = 1;
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    segment_tree(left,low,mid);
    segment_tree(right,mid+1,high);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;
}
int divisor[N*10];
void update(int node,int low,int hi,int i,int j)
{
    int left=2*node;
    int right=left+1;
    if(hi<i||j<low) return;
    if(low>=i&&hi<=j)
    {
        if(low==hi){
            tree[node].sum =divisor[tree[node].sum];
            if(tree[node].sum==1) tree[node].one = 1;
            if(tree[node].sum==2) tree[node].two= 1;
            return;
        }
        if((tree[node].one+tree[node].two)==(hi-low+1)) return;

    }
    int mid=(low+hi)/2;
    update(left,low,mid,i,j);
    update(right,mid+1,hi,i,j);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;

}
ll query(int node,int low,int hi,int i,int j)
{

    int left=2*node;
    int right=left+1;
    //if(tree[node].lazy)propagate(node,low,hi);
    if(hi<i||j<low) return 0;
    if(low>=i&&hi<=j)
        return tree[node].sum;
    int mid=(low+hi)/2;
    ll x= query(left,low,mid,i,j);
    ll y= query(right,mid+1,hi,i,j);
    return x+y;

}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    for(int i = 1;i<10*N;i++) {
        for(int j = i;j<10*N;j+=i) {
            divisor[j]++;
        }
    }
    int n = nxt();
    int m= nxt();
    for(int i = 1;i<=n;i++){
        ar[i] = lxt();
    }
    segment_tree(1,1,n);

    while(m--) {

        int t = nxt();
        int l = nxt();
        int r = nxt();
       // debug(t,l,r);
        if(t==1)  update(1,1,n,l,r);
        else printf("%lld\n",query(1,1,n,l,r));
    }


    return 0;
}