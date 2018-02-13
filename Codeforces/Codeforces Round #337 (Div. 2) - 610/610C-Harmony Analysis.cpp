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
int ar[600][600];
int temp[600][600];
int main()
{
   temp[1][1]=1;
   temp[1][2]=1;
   temp[2][1]=1;
   temp[2][2]=-1;
   f(m,2,10){
       int n=pow(2,m);int p=0,q=0;
       f(i,1,n+1){
           if(p==n/2)p=0;
              p++;
           f(j,1,n+1){
               if(q==n/2) q=0;
               q++;
            if(i>n/2&&j>n/2)
            ar[i][j]=temp[p][q]*-1;
            else
                ar[i][j]=temp[p][q];

           }
    }
    f(i,1,n+1)
       f(j,1,n+1)
           temp[i][j]=ar[i][j];
}
   take1(n);
f(i,1,pow(2,n)+1){
       f(j,1,pow(2,n)+1)
           if(ar[i][j]==1) printf("+");else printf("*");printf("\n");
       }

return 0;
}