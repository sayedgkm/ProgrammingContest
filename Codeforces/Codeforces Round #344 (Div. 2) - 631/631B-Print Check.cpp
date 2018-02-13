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
int row[3][5005],clm[3][5005];
int main()
{
    int r,c,n;
    take3(r,c,n);
    f(i,1,n+1){
       int x,y,z;
       take3(x,y,z);
       if(x==1){
        row[0][y]=i;
        row[1][y]=z;

       }
       else{
        clm[0][y]=i;
        clm[1][y]=z;

      }
    }
      for(int i=1;i<=r;i++){
          for(int j=1;j<=c;j++)
              printf("%d ",row[0][i]>clm[0][j]?row[1][i]:clm[1][j]);printf("\n");
         }


      return 0;
}