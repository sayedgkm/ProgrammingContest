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
vector<int> g[N]; int ar[N];
int main()
{
  take2(node,edges);
  while(edges--){
      take2(a,b);
      g[a].push_back(b);g[b].push_back(a);
    }
  for(int i=1;i<=node;i++){
          for(int j=0;j<g[i].size();j++){
                int res=g[i][j];
                 if(res>i){
                    ar[res]=max(ar[res],ar[i]+1);
                 }

          }
  }
  //cout<<ar[5]<<endl;
  ll ans=0;
  f(i,1,node+1){
      ll p=(ll)(ar[i]+1)*(ll)g[i].size();
    ans=max(ans,p);
  }
  cout<<ans<<endl;
return 0;
}