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
int mark[1005];
int bad[1005];
string t[1006];
int ache[1005][1005];
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
   // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n ;
    cin>>n;
    string s;
    cin>> s;
    FOR(i,0,s.size()) if(s[i]!='*') mark[s[i]]=1;
    int q ;
    cin>>q;
    vector<int> v;
    FOR(j,0,q) {
      cin>>t[j];
      bool f= 0;
       FOR(i,0,t[j].size()) {
         if(s[i]!='*'){
            if(t[j][i]!=s[i]){
                bad[j] = 1;
               break;
            }
         }
       }
       if(!bad[j]){
           // debug(t[j])
           FOR(i,0,t[j].size()){
           //    debug(t[j][i])
            //   debug(mark['a'])
              if(s[i]=='*'&& mark[t[j][i]]){
                bad[j]=1;
              break;
              }
            }
       }
    //   debug(bad[j])
    if(!bad[j])
        v.pb(j);
    }
    FOR(i,0,v.size()) {
       FOR(j,0,t[v[i]].size()){
          if(s[j]=='*') {
             ache[i][t[v[i]][j]-'a']=1;
          }
       }
    }
     CLR(mark);
     int ans = 0;
     FOR(i,0,v.size()) {
         string sp=t[v[i]];
       //  debug(sp)
         int cnt=0;
         CLR(mark);
         for(int j=0;j<n;j++){
            if(s[j]=='*'){
            int id=sp[j]-'a',flag=0;
            for(int k=0;k<v.size();k++){
                if(!ache[k][id]){
                    flag=1;
                }
            }
            //debug(flag)
            if(mark[id])continue;
            mark[id]=1;
            if(!flag)cnt++;
            }
         }
         ans=max(ans,cnt);
     }
     cout<<ans<<endl;
return 0;
}