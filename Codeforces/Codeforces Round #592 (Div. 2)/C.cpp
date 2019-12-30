///Bismillahir-Rahmanir-Rahim
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
#define        inf                              (1e9)+1000
#define        eps                             1e-9
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
#ifdef sayed
     #define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template < typename Arg1 >
    void __f(const char* name, Arg1&& arg1){
        cerr << name << " is " << arg1 << std::endl;
    }
    template < typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names+1, ',');
        cerr.write(names, comma - names) << " is " << arg1 <<" | ";
        __f(comma+1, args...);
    }
#else
    #define debug(...)
#endif
///******************************************START******************************************
ll x, y;
void extendedEuclid(ll a,ll b ){
     if(b==0){
        x=1;y=0;return;
     }
     extendedEuclid(b,a%b);//as a normal gcd
     ll x1=y;
     ll y1=x-(a/b)*y;
     x=x1;
     y=y1;
}
bool linearDiophantine(ll a,ll b,ll c){
      ll g=gcd(a,b);
      if(c%g!=0) return false;///no solution
      if(g<0){
        g*=-1;
      }
      a/=g;
      b/=g;
      c/=g;
      extendedEuclid(a,b);
     x=x*c;
     y=y*c;
     return true;

}
void bruteforce(ll n, ll p, ll w, ll d) {
    for(int i = 0;i<=n;i++) {
        ll l = p-w*i;
        if(l<0|| l%d) continue;
        if(i+ l/d<=n) {
            cout<<i<<" " << l/d<< ' ' << n- (i+l/d)<<endl;
            return;
        }
    }

    cout<<-1<<endl;
}
int main(){
    #ifdef sayed
    //freopen("out.txt","w",stdout);
  //  freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
//    int t = nxt();
//    while(t--) {
//        debug(t);
        ll n = lxt();
        ll point = lxt();
        ll w = lxt();
        ll d = lxt();

        ll g = gcd(w,d);
       // bruteforce(n,point,w,d);
        if(linearDiophantine(w,d,point)==0) {
            cout<<-1<<endl;
        } else {

            ll lo = -(ll)1e17;
            ll hi = (ll)1e17;
            ll tempX = x;
            ll tempY = y;
            debug(x,y);
            while(lo<=hi){
                ll k = (lo+hi)/2;
                tempX = (x+(d/g)*k);
                tempY = (y-(w/g)*k);
                if(tempX<0) {
                    lo = k+1;
                } else {
                    if(tempX<tempY) lo = k+1;
                    else hi = k-1;
                }
                if(tempX>=0&&tempY>=0&&tempX+tempY<=n){
                    lo = k;
                    break;
                }
            }
           // debug(lo);
            bool f = 0;
            for(long long i = lo-10000;i<=lo+10000;i++){
                tempX = (x+(d/g)*i);
                tempY = (y-(w/g)*i);
                if(tempX>n||tempY>n) continue;
                 if(tempX>=0&&tempY>=0&&tempX+tempY<=n) {
                    cout<<tempX<<" " <<tempY<<" " <<n-tempX-tempY<<endl;
                    f = 1;
                    break;
                 }
            }
            if(!f)
            cout<<-1<<endl;

        }
   // }
    return 0;
}
