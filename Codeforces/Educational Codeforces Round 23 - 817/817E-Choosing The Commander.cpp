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
#define        inf                             9e9+100
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
class node{
public:
 node *ar[2];
 int tot[2];
    node() {
      ar[0]=ar[1]=NULL;
      tot[0]=tot[1]=0;
    }
};
node *root;
void Insert(int n){
     node *current =root;
  for(int i = 30; i >=0; i--){
     int ascii= ison(n,i);
     if(current->ar[ascii] == NULL)
    current->ar[ascii] = new node();
             current->tot[ascii]++;
             current= current->ar[ascii];
   }
}
void Remove(int n){
    node *current =root;
 for (int i = 30; i >=0; i--){
  int ascii= ison(n,i);
    current->tot[ascii]--;
          current= current->ar[ascii];
   }
}
int query(int p,int l) {
    node *current =root; int ans=0;
 for (int i = 30; i >=0; i--){
  int x=ison(p,i);
  int y=ison(l,i);
   int nxt=-1;
  if(current->ar[0]!=NULL) {
             if((x^0)<y) ans+=current->tot[0];
             if((x^0)==y) nxt=0;
         }
        if(current->ar[1]!=NULL) {
             if((x^1)<y) ans+=current->tot[1];
             if((x^1)==y) nxt=1;
         }
         if(nxt==-1) break;
//         if(i<3) {
//            debug(nxt);
//            debug(x);
//            debug(ans);
//         }
         current=current->ar[nxt];
   }
   return ans;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   root=new node();
   int q=nxt();
   while(q--) {
       int t=nxt();
       if(t==1) {
           int n=nxt();
           Insert(n);
       } else if(t==2) {
         int n=nxt();
         Remove(n);
       } else {
          int p=nxt();
          int q=nxt();
          int ans=query(p,q);
          printf("%d\n",ans);
       }


   }
return 0;
}