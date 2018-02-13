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
int ar[N];
bool go(int a,int b){
   int sum=0;
   while(a){
    sum+=a%10;a/=10;
   }
   while(b){
    sum+=b%10;b/=10;
   }
  if(sum%3) return false;
  return true;
}
int main()
{
    int n;
    cin>>n;
    f(i,0,n) cin>>ar[i];
     int ans=0;
     f(i,0,n){
         if(ar[i]==-1) continue;
      f(j,0,n){
         if(i==j||ar[j]==-1) continue;
         if(go(ar[i],ar[j])){
            ans++;
           // cout<<ar[i]<<" "<<ar[j]<<endl;
            ar[i]=ar[j]=-1;break;

         }
      }
    }
     cout<<ans<<endl;
      return 0;
}