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

pair<int ,pii > ar[N];

struct info
{
    pii sum;
    pii lazy;

} tree[N*4];

void propagate(int node,int low,int hi)
{
    int left=2*node;
    int right=left+1;
    int mid =(low+hi)/2;
    if(tree[node].lazy.ff>tree[node].sum.ff)
        tree[node].sum = tree[node].lazy;
    if(hi!=low)
    {   if(tree[node].lazy.ff>tree[left].lazy.ff)
            tree[left].lazy=tree[node].lazy;
        if(tree[node].lazy.ff>tree[right].lazy.ff)
            tree[right].lazy=tree[node].lazy;
    }
    tree[node].lazy=make_pair(0,0);
    tree[node].lazy=make_pair(0,0);
}
void update(int node,int low,int hi,int i,int j,int value,int ind)
{
    int left=2*node;
    int right=left+1;
    if(tree[node].lazy.ff)propagate(node,low,hi);
    if(hi<i||j<low) return;
    if(low>=i&&hi<=j)
    {
        if(value>=tree[node].sum.ff) {
            tree[node].sum = make_pair(value,ind);
        }
        if(hi!=low)
        {   if(value>tree[left].lazy.ff)
            tree[left].lazy=make_pair(value,ind);
            if(value>tree[right].lazy.ff);
            tree[right].lazy=make_pair(value,ind);
        }
        tree[node].lazy=make_pair(0,0);
        return ;
    }
    int mid=(low+hi)/2;
    update(left,low,mid,i,j,value,ind);
    update(right,mid+1,hi,i,j,value,ind);
}
pii query(int node,int low,int hi,int i)
{
    int left=2*node;
    int right=left+1;
    if(tree[node].lazy.ff)propagate(node,low,hi);

    if(low>=i&&hi<=i)
        return tree[node].sum;
    int mid=(low+hi)/2;
    if(i<=mid) return query(left,low,mid,i);
    else return query(right,mid+1,hi,i);
}
ll dp[N][2];

int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
     freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

     update(1,1,N,1,N,0,0);
   // cout<<x.ff<<" "<<x.ss<<endl;
    for(int  i = 0;i<N;i++) dp[0][0]= dp[0][1] = i;
    int n  = nxt();
    int m = nxt();
    for(int i= 1;i<=n;i++) {
        ar[i].ss.ff = nxt();
        ar[i].ss.ss = nxt();
        ar[i].ff = nxt();
    }
    sort(ar+1,ar+n+1);
    for(int i = 1;i<=n;i++){
        int l = ar[i].ss.ff;
        int r= ar[i].ss.ss;
        int y = ar[i].ff;
        pii tmp = query(1,1,N,r);

        if(tmp.ss==0) dp[i][1] = r;
        else {
            int tmpl = ar[tmp.ss].ss.ff;
            int tmpr = ar[tmp.ss].ss.ss;
            if(r<=(tmpl+tmpr)/2)
                dp[i][1] =dp[tmp.ss][0];
            else dp[i][1] =dp[tmp.ss][1];
        }
        tmp = query(1,1,N,l);


        if(tmp.ss==0) dp[i][0] = l;
        else{
            int tmpl = ar[tmp.ss].ss.ff;
            int tmpr = ar[tmp.ss].ss.ss;
            if(i==3){
                debug(l,tmpl,tmpr);
                debug(dp[tmp.ss][1]);
            }
            if(l<=(tmpl+tmpr)/2)
                dp[i][0] =dp[tmp.ss][0];
            else{
            dp[i][0]=dp[tmp.ss][1];

            }
        }
        //debug(dp[i][0],dp[i][1],i);
        update(1,1,N,l,r,y,i);
    }
    debug(dp[3][0]);
    while(m--){
        int x =nxt();
        pii tmp = query(1,1,N,x);
        int i = tmp.ss;
        debug(i);
        int l = ar[i].ss.ff;
        int r= ar[i].ss.ss;
        if(tmp.ff==0){
            printf("%d\n",x);
        } else {
            debug(l,r,tmp.ss);
            if(x<=(l+r)/2) printf("%d\n",dp[tmp.ss][0]);
            else printf("%d\n",dp[tmp.ss][1]);
        }
    }





    return 0;
}
