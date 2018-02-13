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

struct info{
  int l,r,cost;
}ar[N];
bool cmp(info x,info y){
  return x.l<y.l;
}
vector<int> diff[N];
vector<int> ind[N];
vector<int> mn[N];
int n;
int go(int val){
   int b=0;
   int e=n-1;
   while(b<=e){
      int mid=(b+e)/2;
      if(ar[mid].l<=val) b=mid+1;
      else e=mid-1;
   }
    return b;
}
bool mark[N];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);

      n=nxt();
    int x=nxt();
     FOR(i,0,n){
       ar[i].l=nxt();
       ar[i].r=nxt();
       ar[i].cost=nxt();
     }
     sort(ar,ar+n,cmp);
//     FOR(i,0,n){
//       cout<<ar[i].l<<" "<<ar[i].r<<endl;
//     }
      FOR(i,0,n){
          diff[ar[i].r-ar[i].l+1].pb(ar[i].cost);
          ind[ar[i].r-ar[i].l+1].pb(i);
      }
      FOR(i,0,n){
        int t=ar[i].r-ar[i].l+1;
          if(mark[t] ) continue;
          mark[t]=1;
         for(int j=diff[t].size()-2;j>=0;j--)  diff[t][j]=min(diff[t][j],diff[t][j+1]);
      }
      int ans=INT_MAX;
      FOR(i,0,n){
        int r=ar[i].r;
        int start=go(r);
        int tok=ar[i].r-ar[i].l+1;
        tok=x-tok;

        if(tok>=1&&diff[tok].size()){
            int l=lower_bound(ALL(ind[tok]),start)-ind[tok].begin();

            if(l!=diff[tok].size()){
                 ans=min(ans,diff[tok][l]+ar[i].cost);
            }

        }
      }
      if(ans==INT_MAX) ans=-1;
      printf("%d\n",ans);

return 0;
}