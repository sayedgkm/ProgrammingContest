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

vector<int>exeven,exodd;
priority_queue<pii> odd,even;

map<int,int>mp;
map<int,int> ::  iterator it;
int ar[N];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
  int n=nxt();
  int m=nxt();
  int od=0;
    int ev=0;
  FOR(i,0,n) {
     ar[i]=nxt();
     if(ar[i]%2==0)ev++;
        else od++;
     mp[ar[i]]++;
  }
  for(it=mp.begin();it!=mp.end();it++){
        int val=it->ff;
        int oc=it->ss;
        if(val%2==0) even.push(pii(oc,val));
        else odd.push(pii(oc,val));
   }
  FOR(i,1,min(2*N,m+1)) {
      if(mp.find(i)!=mp.end()) continue;
      if(i%2==1) exodd.pb(i);
      else exeven.pb(i);
  }
  int c=0;

   while(ev!=od){

       if(ev>od){
           pii top=even.top();
           even.pop();
           top.ff--;
           if(top.ff) even.push(top);
           ev--;
            if(!exodd.size()) {
                puts("-1");
                return 0;
            }
           odd.push(pii(1,exodd.back()));
           exodd.pop_back();
           od++;
       } else if(ev<od){
           pii top =odd.top();
             odd.pop();
             top.ff--;
             if(top.ff) {
                    odd.push(top);
             }
             od--;
             ev++;
             if(exeven.empty()) {
                puts("-1");
                return 0;
             }
          even.push(pii(1,exeven.back()));
          exeven.pop_back();
       }
       c++;
    }
    while(1){
        pii top=odd.top();
        if(top.ff==1) break;
          odd.pop();
        top.ff--;
        c++;
         if(!exodd.size()) {
                puts("-1");
                return 0;
            }
        odd.push(pii(1,exodd.back()));
        odd.push(top);
         exodd.pop_back();

    }
     while(1){
        pii top=even.top();
        if(top.ff==1) break;
          even.pop();
        top.ff--;
        c++;
         if(!exeven.size()) {
                puts("-1");
                return 0;
            }
        even.push(pii(1,exeven.back()));
        even.push(top);
         exeven.pop_back();
     }
    mp.clear();
    set<int> res;
    while(odd.size()){
         int x=odd.top().ss;
         mp[x]++;
         res.insert(x);
         odd.pop();
    }
    while(even.size()){
         int x=even.top().ss;
         mp[x]++;
         res.insert(x);
         even.pop();
    }
    printf("%d\n",c);
   for(int i=0;i<n;i++){
      if(mp[ar[i]]) {
          mp[ar[i]]--;
          res.erase(ar[i]);
      } else ar[i]=0;
   }
    for(int i=0;i<n;i++){
      if(ar[i]) printf("%d ",ar[i]);
      else{
           int x=*res.rbegin();
              res.erase(x);
           printf("%d ",x);
      }
   }
return 0;
}