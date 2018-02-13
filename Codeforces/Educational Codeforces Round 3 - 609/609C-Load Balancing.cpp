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
int ar[N];
int main()
{
  take1(n); ll sum=0;
  f(i,0,n) {cin>>ar[i];
     sum+=ar[i];
  }
  int m=sum/n;
  int rem=sum%n;
   int c=0,d=0;
   sort(ar,ar+n);
  for(int i=0;i<n;i++){
      if(ar[i]<m)
         c+=m-ar[i];
         else if(m<ar[i])
             rem--;

  }
  if(rem>0) c+=rem;
 cout<<c<<endl;
return 0;
}