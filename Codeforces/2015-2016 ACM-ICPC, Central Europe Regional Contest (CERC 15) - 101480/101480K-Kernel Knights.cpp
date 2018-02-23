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
#define        N                               200010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                              1e9
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
bool mark[N];
queue<int> q[N];
int attack[N];

void Try(int x) {
   if(mark[x]==1) return;
     mark[x]=1;
    while(q[x].size()) {
        int t = q[x].front();
        q[x].pop();
     if(mark[t]) {
         mark[t]=0;
         attack[ar[t]]--;
         if(attack[ar[t]]==0) {
            Try(ar[t]);
         }
      }
    }
    attack[ar[x]]++;
    q[ar[x]].push(x);
     if(mark[ar[x]]) {
        mark[ar[x]]=0;
        attack[ar[ar[x]]]--;
        if(attack[ar[ar[x]]]==0) Try(ar[ar[x]]);
     }

}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n=nxt();
    FOR(i,1,2*n+1) {
       ar[i]=nxt();
    }
    for(int i=1;i<=2*n;i++) {
        if(attack[i]==0&&mark[i]==0) Try(i);
    }
    FOR(i,1,2*n+1) {
      if(mark[i]) printf("%d ",i);
    }

return 0;
}