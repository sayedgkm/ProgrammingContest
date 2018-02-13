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
priority_queue<ll> pqmin;
priority_queue<pll> pqmax;
int main(){
     //freopen("out.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n=nxt();
   ll limak=lxt();
   lxt();
    int ans;
    for(int i=0;i<n-1;i++){
        ll a=lxt();
        ll b=lxt();
        if(a>limak){
            pqmin.push(a-b);
        } else {
           pqmax.push({a,b});
        }
    }
      ans=pqmin.size()+1;
      if(ans==1){
        puts("1");
        return 0;
      }
   while(1){

    ll top=-pqmin.top();
       pqmin.pop();
    if(limak>=top+1) {

        limak-=top;
        limak--;
    } else break;
    while(!pqmax.empty()&&limak<pqmax.top().ff){

        pll temp=pqmax.top();
        //cout<<"temp.ff== " <<temp.ff<<endl;
        pqmax.pop();
        pqmin.push(temp.ff-temp.ss);
    }
    int sz=pqmin.size();
    //cout<<limak<<" "<<sz<<endl;
    ans=min(ans,sz+1);
    if(pqmin.empty()) break;
}
 cout<<ans<<endl;
return 0;
}