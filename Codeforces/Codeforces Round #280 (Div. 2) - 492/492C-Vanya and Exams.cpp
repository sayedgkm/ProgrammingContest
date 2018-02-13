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
#define        pii                   pair<ll,ll>
#define        mem(a,x)              memset(a,x,sizeof(a))
#define        N                     100010
#define        M                     1000000007
using namespace std;
pii ar[N];
int main()
{
 ll n,r,avg;
  cin>>n>>r>>avg;
  ll avggrade=n*avg,grade=0,need; ll es=0;
  //cout<<avggrade<<endl;
  f(i,0,n){
        cin>>ar[i].second>>ar[i].first;
        grade+=ar[i].second;
  }
  sort(ar,ar+n);
  f(i,0,n){
         need=avggrade-grade;
         if(need<=0){
            cout<<es<<endl;return 0;
         }
         if(ar[i].second+need>=r){
              grade+=r-ar[i].second;
              es+=ar[i].first*(r-ar[i].second);
         }
         else
         { es+=ar[i].first*need;
              cout<<es<<endl;return 0;
         }
   }
   cout<<es<<endl;
return 0;
}