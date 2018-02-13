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
using namespace std;
int ar[55][55];int ans[55];
int main()
{
    int n;
    cin>>n;
    f(i,0,n) f(j,0,n) cin>>ar[i][j];
    f(i,1,n){
      int mx=0,row;
        f(j,0,n) {
            int c=0;
            f(k,0,n){

           if(ar[j][k]==i){
            c++;
           }

        }
        if(c>mx){

            mx=c;
            row=j;
        }
       }
      ans[row]=i;
    }
     f(i,0,n){
      printf("%d ",ans[i]==0?n:ans[i]);
    }
      return 0;
}