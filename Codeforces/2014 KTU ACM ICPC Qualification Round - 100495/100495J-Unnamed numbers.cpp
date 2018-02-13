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
int coprime[103][103];
bool prime[103]; string s;
bool isprime(int n){
   for(int i=2;i*i<=n;i++) if(n%i==0) return false;
   return true;
}
void cal(){
     coprime[0][1]=coprime[1][0]=1;
   FOR(i,1,101) FOR(j,1,101){
       if(gcd(i,j)==1) coprime[i][j]=1;
   }
   FOR(i,2,101) prime[i]=isprime(i);
}
ll dp[13][11][11][2][2][3];
ll go(int pos,int prev,int prevofprev,bool isstart,bool issmall,int cnt){
        if(pos>=12){

          if(cnt>=2)
              return 1;
            return 0;
        }
    if(dp[pos][prev][prevofprev][isstart][issmall][cnt]!=-1){
            //cout<<dp[pos][prev][prevofprev][isstart][issmall]<<endl;
        return dp[pos][prev][prevofprev][isstart][issmall][cnt];
    }
       ll res=0;
 int limit=issmall?9:s[pos]-'0';
   FOR(i,0,limit+1){
       if(isstart&&cnt>=2){
             int x=prevofprev*10+prev;
             int y=prev*10+i;
         if(prime[x]==1||prime[y]==1) continue;
         if(coprime[x][y]!=1) continue;
           res=res+go(pos+1,i,prev,isstart,issmall|i<(s[pos]-'0'),cnt);
       } else {
           int temp=0;
             if(isstart) temp=cnt+1;
            else if(i) temp=cnt+1;
          int x=prev*10+i;
           if(isstart) if(prime[x]==1) continue;
            res=res+go(pos+1,i,prev,isstart|i!=0,issmall|i<(s[pos]-'0'),temp);
       }

   }
   return dp[pos][prev][prevofprev][isstart][issmall][cnt]=res;
}
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
    cal();

    int test=nxt();
    int cs=1;
    while(test--){
       SET(dp);
           ll a=lxt();
           ll b=lxt();
             a--;
        s=NumberToString(b);
        while(s.size()!=12){
            s='0'+s;
        }
        ll ans=go(0,0,0,0,0,0);
        s=NumberToString(a);
        while(s.size()!=12){
           s='0'+s;
        }
        SET(dp);
        ans-=go(0,0,0,0,0,0);
        printf("Case #%d: %lld\n",cs++,ans);
    }


return 0;
}