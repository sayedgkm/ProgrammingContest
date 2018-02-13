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
struct point{
  ll x,y,z,xx,yy;
}P[N];
struct vec{
  double x,y,z,xx,yy;
};
double dotproduct(vec a,vec b){
   return (a.x*b.x+a.y*b.y+a.z*b.z+a.xx*b.xx+a.yy*b.yy);
}
double norm_sq(vec a){
  return (a.x*a.x+a.y*a.y+a.z*a.z+a.xx*a.xx+a.yy*a.yy);
}
double angle(point A,point B,point C){ ///will return angle between ABC

   vec BA,BC;
   BA.x=A.x-B.x;
   BA.y=A.y-B.y;
   BA.z= A.z-B.z;
   BA.xx=A.xx-B.xx;
   BA.yy= A.yy-B.yy;
   BC.x=C.x-B.x;
   BC.y=C.y-B.y;
   BC.z=C.z-B.z;
   BC.xx=C.xx-B.xx;
   BC.yy=C.yy-B.yy;
   return dotproduct(BA,BC)/sqrt(norm_sq(BA)*norm_sq(BC));
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    int  n = nxt();
    FOR(i,0,n) {
       P[i].x= lxt();
       P[i].y= lxt();
       P[i].z= lxt();
       P[i].xx= lxt();
       P[i].yy= lxt();
    }
    if(n>=100) {
        printf("0\n");
        return 0;

    }
    vector<int> ans;
    for(int i = 0;i<n;i++){
            bool good = 1;
            FOR(j,0,n) {
             if(i==j) continue;
                FOR(k,j+1,n) {
                 if(j==k) continue;
                 if(k==i) continue;
                double ang = angle(P[j],P[i],P[k]);
               // cout<<ang<<endl;
                  if(ang>0.000000) good = 0;
                if(!good)  break;

            }
            if(!good) break;
      }
       if(good) ans.pb(i+1);
}
cout<<ans.size()<<endl;
FOR(i,0,ans.size()) cout<<ans[i]<<endl;
return 0;
}