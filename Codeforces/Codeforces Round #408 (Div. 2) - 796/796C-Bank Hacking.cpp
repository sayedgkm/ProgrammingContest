//==========================================================================
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
#define        N                               300010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             9e9+100
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
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
///******************************************START******************************************
int ar[N];
vector<int> adj[N];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     int n=nxt();
     FOR(i,1,n+1) ar[i]=nxt();
     FOR(i,0,n-1) {
       int a=nxt();
       int b=nxt();
       adj[a].pb(b);
       adj[b].pb(a);
     }
     int ans=INT_MAX;
     multiset<int> st;
      FOR(i,1,n+1)
        st.insert(ar[i]);


      bool f=1;
      int mx=0;
      FOR(i,1,n+1) {
          mx=ar[i];

           auto it=st.find(ar[i]);
            st.erase(it);
           FOR(j,0,adj[i].size()) {
              int v=adj[i][j];
              mx=max(ar[v]+1,mx);
              auto it=st.find(ar[v]);
              st.erase(it);
           }

        if(st.size())
           mx=max(mx,*--st.end()+2);
          // puts("b");
           ans=min(ans,mx);
           st.insert(ar[i]);
           FOR(j,0,adj[i].size()) {
              int v=adj[i][j];
               st.insert(ar[v]);
           }
           //puts("b");
      }
     cout<<ans<<endl;
return 0;
}