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
int ar[22][4];
int main()
{
    take1(test);
    f(k,1,test+1){
       f(i,0,22) f(j,0,4) ar[i][j]=0;
       take1(n);
       f(i,1,n+1){
            take3(a,b,c);
            ar[i][0]=a+min(ar[i-1][1],ar[i-1][2]);
            ar[i][1]=b+min(ar[i-1][0],ar[i-1][2]);
            ar[i][2]=c+min(ar[i-1][0],ar[i-1][1]);
           // cout<<ar[i][0]<<" "<<ar[i][1]<<" "<<ar[i][2]<<endl;

       }
       printf("Case %d: %d\n",k,min(ar[n][0],min(ar[n][1],ar[n][2])));

    }
return 0;
}
