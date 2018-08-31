 /// Bismillahir-Rahmanir-Rahim
#include <bits/stdc++.h>
#define        ll                              long long int
#define        FOR(x,y,z)                      for(int x=y;x<z;x++)
#define        pii                             pair<int,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1005
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
int tree[2][N][N];
int up(int r,int id,int x,int val) {
   tree[r][id][x]+=val;
}
int update(int r,int id,int x,int y , int val) {
    up(r,id,x,val);
    up(r,id,y+1,-val);
}
int query(int r,int id,int x) {
    return tree[r][id][x];
}
char s[1005][1005];
vector<int> ok[N][N];
int r[N][N],c[N][N];
vector<pair<pii,int> >v;
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    int m;
    cin>>n>>m;
    FOR(i,1,n+1) FOR(j,1,m+1) cin>>s[i][j],r[i][j]= c[j][i]=s[i][j]=='*';
    for(int i = 1;i<=n;i++) {
        for(int j = 1;j<=m;j++)r[i][j] +=r[i][j-1],c[j][i]+=c[j][i-1];
    }
    for(int i =2;i<n;i++){
        for(int j = 2 ;j<m;j++) {
            if(s[i][j]=='*') {

                int len = min(j-1,m-j);
                len = min(len,min(i-1,n-i));
                int lo= 0;
                int hi = len;
                while(lo<=hi) {
                    int mid =(lo+hi)/2;
                    if(r[i][j+mid]-r[i][j]==mid) lo = mid+1;
                    else hi = mid-1;
                }
                ok[i][j].pb(lo-1);

                lo= 0;
                 hi = len;
                while(lo<=hi) {
                    int mid =(lo+hi)/2;
                    if(abs(r[i][j-mid-1]-r[i][j-1])==mid) lo = mid+1;
                    else hi = mid-1;
                   // if(i==2&&j==4) debug(lo);
                }
                ok[i][j].pb(lo-1);

               lo= 0;
                hi = len;
                while(lo<=hi) {
                    int mid =(lo+hi)/2;
                    if(c[j][i+mid]-c[j][i]==mid) lo = mid+1;
                    else hi = mid-1;
                }
                ok[i][j].pb(lo-1);

                 lo= 0;
                hi = len;
                while(lo<=hi) {
                    int mid =(lo+hi)/2;
                    if(abs(c[j][i-mid-1]-c[j][i-1])==mid) lo = mid+1;
                    else hi = mid-1;
                }
                ok[i][j].pb(lo-1);

            }
        }
    }
    for(int i = 2;i<n;i++) {
        for(int j =2;j<m;j++) {
            if(s[i][j]=='*') {
                int mn = min({ok[i][j][0],ok[i][j][1],ok[i][j][2],ok[i][j][3]});
                int l = j-mn;
                int r = j+mn;
                int u= i-mn;
                int d = i+mn;
                if(mn){
                    update(0,i,l,r,1);
                    update(1,j,u,d,1);
                    v.pb(make_pair(make_pair(i,j),mn));
                }
            }
        }
    }
    FOR(i,1,n+1)FOR(j,1,m+1) tree[0][i][j]+=tree[0][i][j-1];
    FOR(i,1,n+1)FOR(j,1,m+1) tree[1][j][i]+=tree[1][j][i-1];
    for(int i = 1;i<=n;i++) {
        for(int j =1;j<=m;j++) {
            if(s[i][j]=='*'&&query(0,i,j)+query(1,j,i)==0) {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<v.size()<<endl;
    for(auto it : v) {
        cout<<it.ff.ff<<" "<<it.ff.ss<<" "<<it.ss<<endl;
    }

    return 0;
}
