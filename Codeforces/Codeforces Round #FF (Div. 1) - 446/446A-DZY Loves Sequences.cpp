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
ll ar[N],in[N],de[N];
int main()
{
  take1(n);
  f(i,0,n) cin>>ar[i];
  in[0]=1;
  f(i,1,n)
       if(ar[i]>ar[i-1]) in[i]=in[i-1]+1;
       else in[i]=1;
       de[n-1]=1;
       for(int i=n-2;i>=0;i--)
            if(ar[i]<ar[i+1]) de[i]=de[i+1]+1;
       else de[i]=1;
       int x=0,y=0,m=0;
     f(i,0,n){   //cout<<i<<endl;
           if(i==0)x=0;
              else x=in[i-1];
              if(i==n-1) y=0;
                  else y=de[i+1];
                  if(!(i==0||i==n-1)){
                    if(ar[i+1]-ar[i-1]<=1)
                           x>y?y=0:x=0;

                  }
                  //cout<<x<<" "<<y<<endl;
                m=max(m,x+y+1);
       }
     cout<<m<<endl;
return 0;
}