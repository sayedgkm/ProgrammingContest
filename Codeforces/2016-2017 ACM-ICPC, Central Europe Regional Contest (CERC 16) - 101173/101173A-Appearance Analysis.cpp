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
char s[115][115];
char ans[111*111+5][115][115];
 int r;
    int c;
    void print(char tt[115][115],int nr,int nc) {
       cout<<"****"<<endl;
       FOR(i,0,nr) {
         FOR(j,0,nc) {
           cout<<tt[i][j];
         }
         cout<<endl;
       }

    }
bool ok(char tt[115][115],int x,int rn,int cn ) {
        FOR(k,0,x) {
             bool f=0;
          FOR(i,0,rn) {
            FOR(j,0,cn) {
              if(tt[i][j]!=ans[k][i][j]) f=1;
            }
          }
         if(f==0) return true;
        }
   return false;
    }
bool go(int x,int nr,int nc) {


  char temp[115][115];
  char temp1[115][115];
  FOR(i,0,nr) {
    FOR(j,0,nc) {
      temp[i][j]= ans[x][i][j];
    }
  }
  bool f=0;
   for(int tt=0;tt<4;tt++) {
   int a=0;
   int b=0;
   for(int i =nc-1;i>=0;i--) {
       b=0;
    for(int j =0;j<nr;j++) {

        temp1[a][b]=temp[j][i];
      b++;
    }
    a++;
   }
   swap(nr,nc);
   if(ok(temp1,x,nr,nc)) return false;
   FOR(i,0,nr) {
     FOR(j,0,nc) {
       temp[i][j]=temp1[i][j];
     }
   }
 }
 return true;
}
int main(){
    #ifdef sayed
     //freopen("out.txt","w",stdout);
    // freopen("in.txt","r",stdin);
    #endif
    //ios_base::sync_with_stdio(false);
   //cin.tie (0);
    int n=nxt();
    int m=nxt();
    FOR(i,0,n) scanf("%s",s[i]);

    int x=1;
    int y=1;
    while(s[x][y]!='#'&&x<n) x++;
    r= x-1;
     x=1;
    while(s[x][y]!='#'&&y<m) y++;
    c = y-1;
    if(r==0||c==0) {
         cout<<0<<endl;
         return 0;

    }
   // cout<<r<<" "<<c<<endl;
   int koita=0;
     for(int i = 1;i<n;i+=(r+1)){
        for(int j =1 ;j<m; j+= (c+1)) {
//            debug(i);
//            debug(j);
              for(int x= i;x<=i+r-1;x++) {
                  for(int y =j;y<=j+c-1;y++) {
                     ans[koita][x-i][y-j]=s[x][y];
                  }

              }
            koita++;

        }
    }
      int res=0;
     // cout<<go(5,r,c)<<endl;
//     debug(r);
//     debug(c);
//debug(koita);
    FOR(i,0,koita) {
        res+=go(i,r,c);
    }
    cout<<res<<endl;
return 0;
}