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
#define        inf                             (ll)1e18
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
int n,m,k,s;
pii doller[N];
pii pound[N];
vector<pii> p,d;
vector<pii> ans;
bool go(int x){
  ans.clear();
   ll mnd=(ll)inf;
   ll mnp=(ll)inf;
   int day1;
   int day2;
   ll temp=s;
   FOR(i,0,x) {
      if(doller[i].ff<mnd) {
           mnd=doller[i].ff;
           day1=doller[i].ss;
      }
      if(pound[i].ff<mnp) {
           mnp=pound[i].ff;
           day2=pound[i].ss;
      }
   }

   int i=0;
   int j=0;
  while(1){
      ll totalp,totald;
  totald=totalp=inf;
     if(i<d.size()){
         totald=d[i].ff;
         totald*=mnd;
      }
      if(j<p.size()){
         totalp=p[j].ff;
         totalp*=mnp;
      }
      if(totald==inf&&totalp==inf) return false;
     // debug(totald);
     // debug(totalp);
      if(totald<=totalp){
            temp-=totald;
            ans.pb(pii(day1,d[i].ss));
             i++;
      } else {
          temp-=totalp;
          ans.pb(pii(day2,p[j].ss));
          j++;
      }
      if(temp<0) return false;

      if(ans.size()==k) break;
  }
  return true;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   n=nxt();
   m=nxt();
   k=nxt();
   s=nxt();
    FOR(i,0,n){
      doller[i].ff=nxt();
      doller[i].ss=i;
   }
    FOR(i,0,n){
      pound[i].ff=nxt();
      pound[i].ss=i;
   }
   FOR(i,0,m) {
        int t=nxt();
        int temp=nxt();
        if(t==1){
            d.pb(make_pair(temp,i));
        } else p.pb(make_pair(temp,i));
   }
   sort(ALL(d));
   sort(ALL(p));
   //cout<<go(1)<<endl;
   int b=1;
   int e=n;
   int res=-1;
   while(b<=e){

        int mid=(b+e)/2;
        if(!go(mid)){
                b=mid+1;
                res=mid+1;
        }
        else e=mid-1;
    }

   if(res>n){
     puts("-1");
   } else {
      go(b);
      cout<<b<<endl;
      sort(ALL(ans));
      FOR(i,0,ans.size()) {
        printf("%d %d\n",ans[i].ss+1,ans[i].ff+1);
      }
   }
return 0;
}