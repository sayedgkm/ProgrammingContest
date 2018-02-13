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
#define        N                     200010
#define        M                     1000000007
#define        pi                    acos(-1.0)
using namespace std;
ll ar[N];ll sum[N];
int main()
{
int n,a;
  cin>>n>>a;
  for(int i=0;i<n;i++) {cin>>ar[i];
           if(i==0)
                 sum[0]=ar[i];
          else sum[i]+=sum[i-1]+ar[i];
  }
  //cout<<sum[4]-sum[1]<<endl;
  ll mini=1e15,index=0;
  f(i,0,n){
      if(i==a-1)
      {
          index=0;
          mini=sum[i];
      }
    else if(i>=a){

        if(sum[i]-sum[i-a]<mini){
            index=i-a+1;
            mini=sum[i]-sum[i-a];
        }

    }
  //cout<<mini<<endl;
  }
  cout<<index+1<<endl;
return 0;
}