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
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
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
const long long MOD[] = {1000000007LL, 2117566807LL,1000000007LL,1000000037LL};
const long long BASE[] = {1572872831LL, 1971536491LL,1000003LL,31};
ll P[2][N];
void calc(){

   P[0][0]=P[1][0]=1;
   FOR(i,0,2) {
    FOR(j,1,N) P[i][j]=(P[i][j-1]*BASE[i])%MOD[i];
   }

}
class stringhash{
    public:
    ll base,mod,len;vector<ll>v;
     void GenerateFH(vector<int>s,ll b,ll m){
          base=b;
          mod=m;  len=s.size();
           v.resize(len);
          long long h=0;
          for(int i=0;i<len;i++){
              h=(h*base)+s[i];
              h%=mod;
              v[i]=h;
          }
   }
   int Fhash(int x,int y,int t){
        if(x>y) return 0;
        ll h=v[y];
       if(x>0){
         h=(h-(ll)P[t][y-x+1]*(ll)v[x-1])%mod;
         if(h<0) h+=mod;
       }
       return h;
   }

};
stringhash s[2][N];
vector<int> adj[N];
bool go(int i,int j,int t){
         //cout<<i<<" "<<j<<endl;
     int v=adj[i][j];
   if(adj[i].size()!=adj[v].size()) return 0;
   int low=lower_bound(ALL(adj[v]),i)-adj[v].begin();
   ll hs=s[t][i].Fhash(0,j-1,t)*P[t][adj[i].size()-j-1]+s[t][i].Fhash(j+1,adj[i].size()-1,t);
   ll hs1=s[t][v].Fhash(0,low-1,t)*P[t][adj[v].size()-low-1]+s[t][v].Fhash(low+1,adj[v].size()-1,t);
   hs%=MOD[t];
   hs1%=MOD[t];
  // cout<<hs<<" xx "<<hs1<<endl;
  return hs==hs1;
}
int main()
{
#ifdef sayed
    // freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    calc();
   int n=nxt();
   int m=nxt();

   FOR(i,0,m){
     int a=nxt();
     int b=nxt();
     adj[a].pb(b);
     adj[b].pb(a);
   }
   FOR(i,1,n+1) sort(ALL(adj[i]));
    ll zero=0; ll ans=0;int x=-1;
   FOR(i,1,n+1){
       if(adj[i].size()==0) zero++;
       else{
        s[0][i].GenerateFH(adj[i],BASE[0],MOD[0]);
        s[1][i].GenerateFH(adj[i],BASE[1],MOD[1]);
       }
   }
    ans+=(zero*(zero-1))/2LL;
    map<pair<ll,ll> ,ll>mp;
    FOR(i,1,n+1){
      if(adj[i].size()==0) continue;
         int len=adj[i].size();
       ll hs=s[0][i].Fhash(0,len-1,0);
       ll hs1=s[1][i].Fhash(0,len-1,1);
       ans+=mp[{hs,hs1}];
      mp[{hs,hs1}]++;
       FOR(j,0,len){
           if(adj[i][j]>i) break;
           ans+=go(i,j,0)&go(i,j,1);
       }
   }

    cout<<ans<<endl;
    return 0;
}