// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                              long long
#define        f(x,y,z)                        for(int x=y;x<z;x++)
#define        take1(a);                       scanf("%d",&a);
#define        take2(a,b);                     scanf("%d%d",&a,&b);
#define        take3(a,b,c);                   scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);                 scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                             pair<int,int>
#define        mem(a,x)                        memset(a,x,sizeof(a))
#define        N                               1000010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
int ar[15][15];
int in(){
   int a;
   scanf("%d",&a);return a;
}
int go(int x,int y,int a,int b){
     int c=0;
  f(i,a,x+1) f(j,b,y+1) if(ar[i][j]) c++;
  return c;
}
int main()
{
    int r,c,n,k;
      r=in();
      c=in();
      n=in();
      k=in();
      while(n--){
        int a,b;
        a=in();b=in();
        ar[a][b]=1;
      }
      int ans=0;
      f(i,1,r+1)f(j,1,c+1) f(m,1,r+1) f(l,1,c+1){
         int c=go(m,l,i,j);
         if(c>=k) ans++;
         //cout<<c<<endl;
      } cout<<ans<<endl;
      return 0;
}