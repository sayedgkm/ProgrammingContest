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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
 int ar[N];
 int l[N];
 int r[N];
 ordered_set tr[4*N];
void buildSegment_tree(int node,int low,int high) {
    if(low==high) {
        tr[node].insert(make_pair(l[low],low));
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(low+high)/2;
    buildSegment_tree(left,low,mid);
    buildSegment_tree(right,mid+1,high);
    tr[node] = tr[left];
    for(auto it : tr[right]){
        tr[node].insert(it);
    }

}
void update(int node,int lo,int hi,int i,int newval,int oldval) {
    int mid = (lo+hi)/2;
    int left=2*node;
    int right=2*node+1;
    if(lo==hi) {
        tr[node].erase(make_pair(oldval,i));
        tr[node].insert(make_pair(newval,i));
        return;
    }
    tr[node].erase(make_pair(oldval,i));
    tr[node].insert(make_pair(newval,i));

    if(i<=mid) update(left,lo,mid,i,newval,oldval);
    else update(right,mid+1,hi,i,newval,oldval);

}
int query(int node,int low,int hi,int i,int j,int val) {
    /// returns how many numbers are less than or equal to value
    /// from index i to j
    if(i>hi||j<low) return 0;
    if(low>=i&&hi<=j){
        int l = tr[node].order_of_key(make_pair(val,-inf));
        return (int) tr[node].size()-(l);
    }

    int mid=(low+hi)/2;
    int left=2*node;
    int right=left+1;
    int x= query(left,low,mid,i,j,val);
    int y= query(right,mid+1,hi,i,j,val);
    return x+y;
}
int tmp[N*10];
set<int> st[N*10];
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    int n = nxt();
    int q = nxt();
    for(int i = 1;i<=n;i++) ar[i] = nxt();
    for(int i = 1;i<=n;i++) st[ar[i]].insert(i);
    for(int i = 0;i<N*10;i++) tmp[i] = inf;
    for(int i = n;i>=1;i--) {
        l[i]=tmp[ar[i]];
        tmp[ar[i]] = i;
    }
    buildSegment_tree(1,1,n);
    while(q--) {
        char c[2];
        scanf("%s",c);
        if(c[0]=='Q') {
            int a= nxt();
            int b = nxt();
            a++;
            b++;
            printf("%d\n",query(1,1,n,a,b-1,b+1));
        } else {
            int a =nxt();
            a++;
            int b= nxt();
            if(b==ar[a]) continue;
            int oldval = ar[a];
            int newval = b;
            ar[a] = b;
            auto it = st[oldval].lower_bound(a);
            if(*st[oldval].begin()!=a) {
                it--;
                int ind = *it;
                update(1,1,n,ind,l[a],l[ind]);
                l[ind] = l[a];
            }
            it = st[newval].lower_bound(a);
            int beg = *st[newval].begin();
            if(st[newval].size()==0) {
                update(1,1,n,a,inf,l[a]);
                l[a] = inf;
            } else if(beg<a) {
                it--;
                int ind = *it;
                update(1,1,n,a,l[ind],l[a]);
                l[a] = l[ind];
                update(1,1,n,ind,a,l[ind]);
                l[ind] = a;
            } else {

                int ind = *it;
                update(1,1,n,a,ind,l[a]);
                l[a] = ind;
            }
            st[oldval].erase(a);
            st[newval].insert(a);



        }


   }


    return 0;
}
