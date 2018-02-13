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
#define        N                     100010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
ll ar[12],value[N],temp[12];
int main()
{
   ll a;
   cin>>a; ll in=0,mini=1e9;
   for(int i=1;i<10;i++){
        cin>>ar[i];
        value[ar[i]]=i;
        if(mini>=ar[i]){
            mini=ar[i];
            in=i;
        }
    }
    if(a<mini){
        puts("-1"); return 0;
    }
    ll ans=a/mini;
    //cout<<ans<<endl;
  for(int i=ans;i>=1;i--){
         for(int j=9;j>=1;j--){
             if((a-ar[j])/mini==i-1&&a>=ar[j]){
                printf("%d",j);a-=ar[j]; break;
             }
         }
    }

return 0;
}