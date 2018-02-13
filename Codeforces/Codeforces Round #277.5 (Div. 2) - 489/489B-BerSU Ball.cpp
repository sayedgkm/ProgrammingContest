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
using namespace std;
int ar[105],c1[105];
int main()
{
  take1(a);
  f(i,0,a){
    cin>>ar[i];
  }
    take1(b);
    f(i,0,b){
       take1(p);
       c1[p]++;
     }
     sort(ar,ar+a);
     int ans=0;
      f(i,0,a){
          if(c1[ar[i]-1]){
            ans++;c1[ar[i]-1]--;
          }
         else if(c1[ar[i]])
          {
              ans++;c1[ar[i]]--;
          }
          else if(c1[ar[i]+1]){
            ans++;c1[ar[i]+1]--;
          }


      }
  cout<<ans<<endl;
return 0;
}