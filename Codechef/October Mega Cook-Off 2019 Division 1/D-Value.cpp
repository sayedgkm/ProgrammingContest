///Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               3002
#define        M                               987654319
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
int n;
ll dp[N][N][6];
int condition[8] = {0,0,1,0,0,1,0,0};
int cnt[N][N];
ll go(int pos,int last,int item) {
    //debug(pos,last,item);
    if(item<0) return 0;
    if(pos>n) {
        return item==0;
    }

    ll &res = dp[pos][last][item];
    if(res!=-1) return res;
    res = 0;
    if(item==5) {
        res+=go(pos+1,pos,item-1);
    } else if(item==4) {
        if(ar[pos]<ar[last]&&cnt[last][pos]>0)
            res+=go(pos+1,pos,item-1)*cnt[last][pos];
    } else if(item==3) {
        if(ar[pos]<ar[last]) {
             res+=go(pos+1,pos,item-1);
        }
    } else if(item==2) {
        if(ar[pos]<ar[last]&&cnt[last][pos]>0)
            res+=go(pos+1,pos,item-1)*cnt[last][pos];
    } else if(item==1) {
        if(ar[pos]<ar[last]) {
             res+=go(pos+1,pos,item-1);
        }
    }
    res+=go(pos+1,last,item);
    res%=M;

    return res;
}
map<int,int> mp;
int tree[N];
void update(int idx,int n,int x)
{
    while(idx<=n)
    {
        tree[idx]+=x;
        idx+= idx&(-idx);
    }
}
int query(int idx){
     int sum=0;
     while(idx>0)
     {
         sum+=tree[idx];idx-=idx&(-idx);
     }
     return sum;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    n = nxt();
    for(int i = 1;i<=n;i++) ar[i] = nxt(),mp[ar[i]] = 0;
    int Rank = 1;
    for(auto it : mp) mp[it.ff]  = Rank++;

    for(int i = 1;i<=n;i++) {
        CLR(tree);
        int lId = mp[ar[i]];
        for(int j = i+1;j<=n;j++) {
            int rId = mp[ar[j]];
            if(ar[j]<ar[i]){
                cnt[i][j] = max(0,query(rId-1));
            }
            update(rId,Rank,1);
        }
    }

    SET(dp);
    cout<<go(1,0,5)<<endl;

    return 0;
}
