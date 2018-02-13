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
#define        N                               100010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
#define        inf                             (int)1e9
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
int ar[N];
int table[22][N];
int table2[22][N];
int Log[N];
void RMQ_init(int n) {
    for(int i=0; i<n; i++)
        table[0][i] =table2[0][i]= ar[i];
    for(int i=2; i<=n; i++) Log[i]=1+Log[i/2];
    for(int i =1; i<20; i++)
        for(int j=0; j+(1<<(i-1))<n; j++){
            table[i][j]=max(table[i-1][j],table[i-1][j+(1<<(i-1))]);  /// j+1<<(i-1) means shifting index
            table2[i][j]=min(table2[i-1][j],table2[i-1][j+(1<<(i-1))]);  /// j+1<<(i-1) means shifting index
        }                                                              /// at j+2^(i-1)
}

int getmax(int i,int j) {
    int k = Log[j-i+1];
    return max(table[k][i],table[k][j-(1<<k)+1]);

}
int getmin(int i,int j) {
    int k = Log[j-i+1];
    return min(table2[k][i],table2[k][j-(1<<k)+1]);

}
int go(int s,int t,ll a){

      int b=s;
      int e=t;
      while(b<=e){
        int mid=(b+e)/2;
        ll mx=getmax(s,mid);
        ll mn=getmin(s,mid);
       // cout<<mx<<" "<<mn<<endl;
        mn=(ll)2*a*mn+mn*mn+a*a;
        if(mx*mx<=mn) b=mid+1;
        else e=mid-1;
      }
   return b-1;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
   int test=nxt(); int cs=1;
   while(test--){
       int n=nxt();
       int a=nxt();
       FOR(i,0,n) ar[i]=nxt();
       int ans=0;
       RMQ_init(n);
       FOR(i,0,n){
         int x=go(i,n-1,a);
        // cout<<x<<endl;
         ans=max(ans,x-i+1);
       }
       printf("Case #%d: %d\n",cs++,ans);


   }


return 0;
}