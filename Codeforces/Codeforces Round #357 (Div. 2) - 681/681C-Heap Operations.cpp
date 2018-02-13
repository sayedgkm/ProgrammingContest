//==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        pii                             pair<string,int>
#define        pll                             pair<ll,ll>
#define        CLR(a)                          memset(a,0,sizeof(a))
#define        SET(a)                          memset(a,-1,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)(1e9)+100
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
template < class T> inline T biton(T n,T pos){return n |((T)1<<pos);}
template < class T> inline T bitoff(T n,T pos){return n & ~((T)1<<pos);}
template < class T> inline T on(T n,T pos){return (bool)(n & ((T)1<<pos));}
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
template <typename T> string NumberToString ( T Number ) { ostringstream ss; ss << Number; return ss.str(); }
inline int nxt(){int aaa;scanf("%d",&aaa);return aaa;}
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
vector<pii>v;
priority_queue<int,vector<int>,greater<int> >pq;
int main(){
     // freopen("out.txt","w",stdout);
     ios_base::sync_with_stdio(false);
    cin.tie(0);

     int n;
     cin>>n;
     f(i,0,n){
       string s;
       int x;
       cin>>s;
       if(s=="insert"){
            cin>>x;
            pq.push(x);
        v.pb(pii(s,x));
       } else if(s=="removeMin"){
          if(pq.empty()){
            v.pb(pii("insert",4));
            v.pb(pii(s,inf));
          } else {
             v.pb(pii(s,inf));
             pq.pop();
          }

       }
       else if(s=="getMin"){
          cin>>x;
          if(pq.empty()){
            v.pb(pii("insert",x));
              pq.push(x);
             v.pb(pii(s,x));
            } else {
               while(pq.top()<x&&!pq.empty()){
                    pq.pop();
                   v.pb(pii("removeMin",inf));
               }
               if(pq.empty()){
                v.pb(pii("insert",x));
                 pq.push(x);
                 v.pb(pii(s,x));

               } else if(pq.top()==x){
                  v.pb(pii(s,x));
               } else {
                   v.pb(pii("insert",x));
                 pq.push(x);
                 v.pb(pii(s,x));

               }

            }

        }
     }
     cout<<v.size()<<endl;
     f(i,0,v.size()){
        if(v[i].ss==inf){
           cout<<v[i].ff<<endl;
        } else cout<<v[i].ff<<" "<<v[i].ss<<endl;
     }

return 0;
}