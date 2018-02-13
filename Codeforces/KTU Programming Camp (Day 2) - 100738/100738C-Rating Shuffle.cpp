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
#define        inf     (ll)1e18
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
ll ar[N];
ll d;
bool possible(int n,ll mid) {

   ll last = (ll)inf;
    for(int i = 0;i<n;i++){

        ll cur = ar[i];
        ll ache = mid;
        if(last<=cur) {
            ll mx = last - 1;
            ll baki = cur- mx;
            ll need = (baki+d-1)/d;
             ache-=need;
             cur-=d*need;
             if(ache<0) return 0;
             if(ache%2==1) cur-=d;
        } else {
           ll mx = last -1;
           ll baki = mx - cur;
           ll need = (baki)/d;
           need = min(need,ache);
            ache-=need;
            cur+=d*need;
            if(ache%2==1) cur-=d;


        }
        //debug(cur);
        last = cur;
    }
    return true;

}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int n = nxt();
    d = lxt();
    FOR(i,0,n) {
      ar[i] = lxt();
    }
  // cout<<possible(n,2)<<endl;
    ll b = 0;
    ll e = (ll)1e15;
    while(b<=e) {

        ll mid = (b+e)/2;
        if(possible(n,mid))  e =mid-1;
        else b = mid+1;
    }
    cout<<b<<endl;
return 0;
}