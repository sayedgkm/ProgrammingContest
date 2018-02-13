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
#define        N                               100010
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
inline ll lxt(){ll aaa;scanf("%I64d",&aaa);return aaa;}
inline double dxt(){double aaa;scanf("%lf",&aaa);return aaa;}
template <class T> inline T bigmod(T p,T e,T m){T ret = 1;
for(; e > 0; e >>= 1){
    if(e & 1) ret = (ret * p) % m;p = (p * p) % m;
} return (T)ret;}
///******************************************START******************************************
int n;
vector<pair<pii,int> > v;
ll dp[(1<<15)+100][17][4];

ll go(int mask,int last,int top){
   // cout<<mask<<" "<<last<<" "<<top<<endl;
    if(__builtin_popcount(mask)==n) return 0;
    if(dp[mask][last][top]!=-1) return dp[mask][last][top];

   ll res=0;
    FOR(i,0,n){
      if(ison(mask,i)) continue;
      if(mask==0){
         res=max(res,go(biton(mask,i),i,0)+v[i].ff.ff);
         res=max(res,go(biton(mask,i),i,1)+v[i].ff.ss);
         res=max(res,go(biton(mask,i),i,2)+v[i].ss);
      } else {

           if(top==0){
               int mxlast=max(v[last].ff.ss,v[last].ss);
               int mnlast=min(v[last].ff.ss,v[last].ss);
               int mxi=max(v[i].ff.ss,v[i].ss);
               int mni=min(v[i].ff.ss,v[i].ss);
               if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,0)+v[i].ff.ff);

                  mxi=max(v[i].ff.ff,v[i].ss);
                  mni=min(v[i].ff.ff,v[i].ss);
                if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,1)+v[i].ff.ss);

                 mxi=max(v[i].ff.ff,v[i].ff.ss);
                  mni=min(v[i].ff.ff,v[i].ff.ss);
                if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,2)+v[i].ss);

           } else if(top==1){

               int mxlast=max(v[last].ff.ff,v[last].ss);
               int mnlast=min(v[last].ff.ff,v[last].ss);
               int mxi=max(v[i].ff.ss,v[i].ss);
               int mni=min(v[i].ff.ss,v[i].ss);
               if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,0)+v[i].ff.ff);
                  mxi=max(v[i].ff.ff,v[i].ss);
                  mni=min(v[i].ff.ff,v[i].ss);
                if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,1)+v[i].ff.ss);

                 mxi=max(v[i].ff.ff,v[i].ff.ss);
                  mni=min(v[i].ff.ff,v[i].ff.ss);
                if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,2)+v[i].ss);



           } else if(top==2){

             int mxlast=max(v[last].ff.ff,v[last].ff.ss);
               int mnlast=min(v[last].ff.ff,v[last].ff.ss);
               int mxi=max(v[i].ff.ss,v[i].ss);
               int mni=min(v[i].ff.ss,v[i].ss);
               if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,0)+v[i].ff.ff);
                  mxi=max(v[i].ff.ff,v[i].ss);
                  mni=min(v[i].ff.ff,v[i].ss);
                if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,1)+v[i].ff.ss);

                 mxi=max(v[i].ff.ff,v[i].ff.ss);
                  mni=min(v[i].ff.ff,v[i].ff.ss);
                if(mxlast>=mxi&&mnlast>=mni)
                  res=max(res,go(biton(mask,i),i,2)+v[i].ss);


           }

      }
    }

    return dp[mask][last][top]=res;
}
int main(){
    #ifdef sayed
     // freopen("in.txt","r",stdin);
     //freopen("out.txt","w",stdout);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
      SET(dp);

  n=nxt();
  FOR(i,0,n){
    pair<pii,int> a;
    a.ff.ff=nxt();
    a.ff.ss=nxt();
    a.ss=nxt();
    v.pb(a);
  }

  cout<<go(0,0,0)<<endl;

return 0;
}