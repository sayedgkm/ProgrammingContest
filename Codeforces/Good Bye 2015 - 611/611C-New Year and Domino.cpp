// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================
#include <bits/stdc++.h>
#define        ll                    long long
#define        f(x,y,z)              for(int x=y;x<z;x++)
#define        take1(a);             int a;scanf("%d",&a);
#define        take2(a,b);           int a;int b;scanf("%d%d",&a,&b);
#define        take3(a,b,c);         int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define        take4(a,b,c,d);       int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
#define        pii                   pair<int,int>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     1000010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
int row[505][505],clm[505][505];char s[505][505];int n=504;
int main()
{
  take2(r,c);
  f(i,1,r+1){
       f(j,1,c+1)
         cin>>s[i][j];
  }

  f(i,1,r+1) f(j,1,c+1) {
      row[i][j]=row[i][j-1];
                  if(s[i][j]=='.'&&s[i][j-1]=='.'){ row[i][j]++;
                  }

  }
  f(j,1,c+1) f(i,1,r+1) {
           clm[i][j]=clm[i-1][j];
                  if(s[i][j]=='.'&&s[i-1][j]=='.') {clm[i][j]++;
                  }

  }
  ll ans=0;
  take1(q);while(q--){
     take4(r1,c1,r2,c2); ans=0;
   for(int i=r1;i<=r2;i++){
    ans+=row[i][c2]-row[i][c1];

   }
 for(int i=c1;i<=c2;i++)
      ans+=clm[r2][i]-clm[r1][i];
cout<<ans<<endl;
  }

return 0;
}