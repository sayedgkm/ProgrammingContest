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
#define        N                               500010
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
        cerr.write(names, comma - names) << " is " << arg1 <<endl;
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
ll ar[N];
struct info{
   ll sum;
   ll mx;
}tree[N*4];
void segment_tree(int node,int low,int high){
     if(low==high){
        tree[node].sum=ar[low];
        return;
     }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    segment_tree(left,low,mid);
    segment_tree(right,mid+1,high);
    tree[node].sum=gcd(tree[left].sum,tree[right].sum);
}
void update(int node,int low,int hi,int i,ll value){

   if(low==hi){
    tree[node].sum=value; return;
   }
   int mid=(low+hi)/2;
   int left=2*node;
   int right=left+1;
   if(i<=mid)
      update(left,low,mid,i,value);
   else
      update(right,mid+1,hi,i,value);
   tree[node].sum=gcd(tree[left].sum,tree[right].sum);
}
ll query(int node,int low,int hi,int i,int j){
    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j)
      return tree[node].sum;
    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    ll x= query(left,low,mid,i,j);
    ll y= query(right,mid+1,hi,i,j);
    return gcd(x,y);
}
int queryIndex(int node,int low,int hi,int i,int j,ll val) {
    debug(low,hi);
    if(i>hi||j<low) return -1;
    if(tree[node].sum%val==0) return -1;
    if(low==hi) {
        return low;
    }
    int mid = (low+hi)/2;
    int left = 2*node;
    int right = left+1;
    if(low>=i&&hi<=j){
       int x = queryIndex(left,low,mid,i,j,val);
       if(x!=-1) return x;
       return queryIndex(right,mid+1,hi,i,j,val);
    }
    int y = queryIndex(left,low,mid,i,j,val);
    if(y!=-1) return y;
    return queryIndex(right,mid+1,hi,i,j,val);
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    for(int i = 1;i<=n;i++) ar[i] = lxt();
    segment_tree(1,1,n);
    int q = nxt();
    while(q--) {
        int t= nxt();
        if(t==1){
            int l = nxt();
            int r = nxt();
            ll val = lxt();
            int res = query(1,1,n,l,r);
            if(res%val==0||l==r){
                printf("YES\n");
            } else {

                int index = queryIndex(1,1,n,l,r,val);
                debug(index);
                if(index==r) printf("YES\n");
                else if(query(1,1,n,index+1,r)%val==0) printf("YES\n");
                else printf("NO\n");
            }
        } else {
            int ind = nxt();
            ll val = lxt();
            update(1,1,n,ind,val);
        }

    }

    return 0;
}