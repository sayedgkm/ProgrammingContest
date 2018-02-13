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
///******************************************STbrT******************************************
int ar[N];
int br[N];
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    string a;
    string b;
    cin>>a>>b;
     int c=0;

    FOR(i,0,a.length()) {
      if(a[i]=='?') c++;
        else ar[a[i]]++;
    }
    FOR(j,0,b.length()){
      br[b[j]]++;
    }
    int mn=inf;
     for(int i='a';i<='z';i++) {
            if(br[i]) {
                mn=min(mn,ar[i]/br[i]);
            }
        }
    for(int i='a';i<='z';i++) {
         if(br[i]) {
             ar[i]-=(mn*br[i]);
         }
    }
    vector<char> v;
    while(c>0){
        for(int i='a';i<='z';i++) {
           if(br[i]>ar[i]) {
               int t=br[i]-ar[i];
               ar[i]=br[i];
               t=min(t,c);
                c-=t;
                while(t) {
                    t--;
                    v.pb((char)i);
                }
           }
       }

  int mn=inf;
     for(int i='a';i<='z';i++) {
            if(br[i]) {
                mn=min(mn,ar[i]/br[i]);
            }
        }
    for(int i='a';i<='z';i++) {
         if(br[i]) {
             ar[i]-=(mn*br[i]);
         }
    }
 }
    FOR(i,0,a.length()){
      if(a[i]=='?'){
        a[i]=v.back();
        v.pop_back();
      }
    }
    cout<<a<<endl;
return 0;
}