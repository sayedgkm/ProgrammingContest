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
int ar[N];
char s[15][15];
int mark[15][15];

bool check(int i,int j) {
   int nx=i;
   int ny=j;
    int c=0;
   while(s[nx][ny]=='X'&&nx<10) {
      c++;
      nx++;
    }
    nx=i-1;
    while(s[nx][ny]=='X'&&nx>=0) {
      c++;
      nx--;
    }
    if(c>=5) return true;
    nx=i;
    ny=j;
    c=0;
    while(s[nx][ny]=='X'&&ny<10) {
      c++;
      ny++;
    }
    ny=j-1;
    while(s[nx][ny]=='X'&&ny>=0) {
      c++;
      ny--;
    }
    if(c>=5) return true;

    nx=i;
    ny=j;
    c=0;
    while(s[nx][ny]=='X'&&nx<10&&ny<10) {
      c++;
      ny++;
      nx++;
    }
    nx=i-1;
    ny=j-1;
    while(s[nx][ny]=='X'&&ny>=0&&nx>=0) {
      c++;
      ny--;
      nx--;
    }
    if(c>=5) return true;


    nx=i;
    ny=j;
    c=0;
    while(s[nx][ny]=='X'&&nx>=0&&ny<10) {
      c++;
      ny++;
      nx--;
    }
    nx=i+1;
    ny=j-1;
    while(s[nx][ny]=='X'&&ny>=0&&nx<10) {
      c++;
      ny--;
      nx++;
    }
    if(c>=5) return true;
   return false;
} 
int main(){
     //freopen("out.txt","w",stdout);
     //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(false);
   //cin.tie(0);
     int n=10;int m=10;
     bool f=0;
     FOR(i,0,n) cin>>s[i];
     FOR(i,0,n){ FOR(j,0,m) {
        if(s[i][j]=='.') {
              s[i][j]='X';
              f= check(i,j);
             if(f)
                break;
            s[i][j]='.';
        }
        }
         if(f) break;
     }
     puts(f?"YES":"NO");
return 0;
}