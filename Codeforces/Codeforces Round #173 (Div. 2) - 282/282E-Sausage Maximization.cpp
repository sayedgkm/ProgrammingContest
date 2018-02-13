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
ll in[N];
ll XOR[N];

class node{
public:
 bool endmark;
 node *ar[2];
 node(){
  for (int i = 0; i < 2; i++) ar[i] = NULL;
    }
};
node *root;
void Insert(ll n){
 node *current =root;
 for (ll i = 43;i>=0;i--){
  int ascii = ison(n,i);
         if (current->ar[ascii] == NULL)
    current->ar[ascii] = new node();
     current= current->ar[ascii];
   }
}
ll query(ll n){


 node *current =root;
 ll tot=0;
 for (ll i = 43;i>=0;i--){
  int ascii = ison(n,i);
  if(ascii==0) {
            if(current->ar[1]!=NULL) {
                  tot*=2;
                  tot+=1;
                current= current->ar[1];
            } else {

               tot*=2;
               current= current->ar[0];
            }

  } else {
      if(current->ar[0]!=NULL) {
                  tot*=2;
                  tot+=1;
                current= current->ar[0];
            } else {

               tot*=2;
               current= current->ar[1];
            }
  }

    }


    return tot;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   root = new node();
     int n=nxt();
     FOR(i,1,n+1) {
        in [i]=lxt();
        XOR[i]= XOR[i-1]^in[i];
     }
     Insert(0);
     ll ans =XOR[n];
     FOR(i,1,n+1) {
          ans = max(ans,query(XOR[n]^XOR[i-1]));
          Insert(XOR[i]);
     }
     ans = max(ans,query(0));
     cout<<ans<<endl;
return 0;
}