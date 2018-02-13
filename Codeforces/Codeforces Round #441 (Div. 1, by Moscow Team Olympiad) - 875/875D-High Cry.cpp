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
int ar[N];
int pref[30][N];
int suf[30][N];
int l[N];
int r[N];
ll go(ll i,ll bam,ll dan,ll bambit,ll danbit) {
    ll ans = 0;
    bool f = 0 ;
    if(bambit>=bam) {
            f = 1;
         ans+=(bambit-bam+1) * (dan-i+1);
    }
    if(danbit<=dan) {
          if(f) {
            ans+=(i-bambit)*(dan-danbit+1);

          } else {
           ans+=(dan-danbit+1)* (i-bam+1);
          }
    }
  return ans;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int n = nxt();
   FOR(i,0,n) {
    ar[i] = nxt();
   }
   FOR(i,0,30) {
       int last = - 1;
     FOR(j,0,n) {
        pref[i][j]= last;
        if(ison(ar[j],i)) last = j;
     }

   }
   FOR(i,0,30) {
      int last =inf;
     for(int j = n-1;j>=0;j--) {
          suf[i][j] = last;
          if(ison(ar[j],i)) last = j;
     }
   }
   stack<int> st;
      l[0] = 0;
    FOR(i,0,n) {
         if(st.empty()||ar[st.top()]>=ar[i]) {
              st.push(i);
              l[i] = i;
         } else {
            while(st.size()&&ar[st.top()]<ar[i]) st.pop();
             if(st.empty()) l[i] = 0;
             else l[i]= st.top()+1;
             st.push(i);
         }
    }
    while(st.size()) st.pop();
    for(int i  = n-1;i>=0;i--) {
         if(st.empty()||ar[st.top()]>ar[i]) {
              st.push(i);
              r[i] = i;
         } else {
            while(st.size()&&ar[st.top()]<=ar[i]) st.pop();
             if(st.empty()) r[i] = n-1;
             else r[i]= st.top()-1;
             st.push(i);
         }
    }
    ll ans = 0;
    FOR(i,0,n) {
        int bam = l[i];
        int dan = r[i];
          int bambit=-1;
          int danbit=inf;
          FOR(j,0,30) {
              if(ison(ar[i],j)==0) {
                bambit= max(pref[j][i],bambit);
                danbit = min(danbit,suf[j][i]);
              }
          }
//           debug(i);
//           debug(bam);
//           debug(dan);
//           debug(bambit);
//           debug(danbit);
          ans+=go(i,bam,dan,bambit,danbit);
          //debug(ans);
    }
cout<<ans<<endl;
return 0;
}