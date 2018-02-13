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
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
#define        eps                             1e-9
#define        debug(x)                        cerr << #x << " is " << x << endl;
#define        All(x)                          x.begin(),x.end()
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
 string a,b;
 int suf[N],pref[N];
int main(){
   cin>>a>>b;
   int lena=a.length();
   int lenb=b.length();
   int i=0;
   int j=0;
   int cnt=0;
   while(i<lena&&j<lenb){
       if(a[i]==b[j]){
           cnt++;
           pref[i]=cnt;
           j++;i++;
        } else {
          i++;
        }
    }
    i=lena-1;
    j=lenb-1;
    cnt=0;
    while(i>=0&&j>=0){
        if(a[i]==b[j]){
            cnt++;
            suf[i]=cnt;
            j--,i--;

        } else {
           i--;
        }

    }

    for(int i=0;i<lena;i++) if(pref[i]==0) pref[i]=pref[i-1];
    for(int i=lena-1;i>=0;i--) if(suf[i]==0) suf[i]=suf[i+1];
    int mx=0;
    int l=0;
    int r=0;
    for(int i=0;i<lena;i++){
        if(i==0) {
         if(suf[i]>mx){
             mx=suf[i];
             l=0;
             r=suf[i];
          }
        }
        if(pref[i]+suf[i+1]>mx){
             mx=suf[i+1]+pref[i];
             l=pref[i];
             r=suf[i+1];
        }
    }
    //cout<<l<<" "<<r<<endl;
    if(mx==0){
        puts("-");
    } else {
     string ans;
     if(l+r>=lenb) ans=b;
     else {
     ans=b.substr(0,l);
     ans+=b.substr(lenb-r,r); }
     cout<<ans<<endl;
    }
return 0;
}