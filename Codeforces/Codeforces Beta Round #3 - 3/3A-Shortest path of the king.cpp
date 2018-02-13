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
int main()
{
ios_base::sync_with_stdio(0); cin.tie(0);
string a,b;
cin>>a>>b;
      string c,d;
      c=a,d=b;
      int ans=0;
      while(1){
      if(a==b) break;
       if(b[0]>a[0]){
       a[0]++;

       }
        if(b[0]<a[0]) {
            a[0]--;

        }
      if(b[1]>a[1])
      {
          a[1]++;
      }
      if(b[1]<a[1]){
          a[1]--;

      }
      ans++;

   }
   cout<<ans<<endl;
   a=c;
   b=d;
   while(1){
      if(a==b) break;
       if(b[0]>a[0]){
        printf("R");a[0]++;

       }
        if(b[0]<a[0]) {
            printf("L");
            a[0]--;

        }
      if(b[1]>a[1])
      {

          printf("U");
          a[1]++;
      }
      if(b[1]<a[1]){
          printf("D");
          a[1]--;

      }
      printf("\n");
   }


return 0;
}