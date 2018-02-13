//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long int
#define        f(x,y,z)                        for(int x=y;x<z;x++)
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
#define        eps                              1e-9
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
#define sayed
#ifdef sayed
     #define debug(args...) {cerr<<"Debug: "; dbg,args; cerr<<endl;}
#else
    #define debug(args...)  // Just strip off all debug tokens
#endif
struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;
///******************************************START******************************************
vector<pair<int,char> > r;
vector<pair<int,char> > u;
vector<pair<int,char> > d1;
vector<pair<int,char> > d2;

bool check(vector<pair<int,char> > &v,string s){
     int kingi;
  for(int i=0;i<v.size();i++)
      if(v[i].ss=='k') {
        kingi=i;
        break;
      }
  if(kingi<v.size()-1) {
     if(v[kingi+1].ss==s[0]||v[kingi+1].ss==s[1]) return true;
  }
  if(kingi>0&&v.size()>1){
      if(v[kingi-1].ss==s[0]||v[kingi-1].ss==s[1]) return true;
  }
  return false;
}
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   int x=nxt(),y=nxt();
   r.pb({x,'k'});
   u.pb({y,'k'});
   d1.pb({x,'k'});
   d2.pb({x,'k'});
   for(int i=0;i<n;i++){
     char c;int nx,ny; char s[3];
    scanf("%s%d%d",s,&nx,&ny);
    c=s[0];
     if(nx==x){
        u.pb({ny,c});
     } else if(ny==y){
       r.pb({nx,c});
     } else if(abs(nx-x)==abs(ny-y)){
          if((nx>x&&ny>y)||(nx<x&&ny<y)) d1.pb({nx,c});
          else d2.pb({nx,c});
     }
   }
   sort(r.begin(),r.end());
   sort(u.begin(),u.end());
  sort(d1.begin(),d1.end());
   sort(d2.begin(),d2.end());
  /* cout<<r.size()<<endl;
    cout<<u.size()<<endl;
     cout<<d1.size()<<endl;
      cout<<d2.size()<<endl;*/
 // for(int i=0;i<d2.size();i++) cout<<d2[i].ff<<" "<<d2[i].ss<<endl;
   int ans=0;
   ans|=check(r,"QR");
   ans|=check(u,"QR");
   ans|=check(d1,"QB");
   ans|=check(d2,"QB");
   if(ans) puts("YES");
   else puts("NO");

return 0;
}