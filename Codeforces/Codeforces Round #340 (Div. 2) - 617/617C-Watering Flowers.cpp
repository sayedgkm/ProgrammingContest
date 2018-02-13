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
pii ar[20005];
double dis(double x1,double y1,double x2,double y2){
     double p=x1-x2;
     double q=y1-y2;
  return (p*p)+(q*q);
}
int main()
{
    int n,x1,x2,y1,y2;
    take1(n);
    take4(x1,y1,x2,y2);
    f(i,0,n) cin>>ar[i].ff>>ar[i].ss;
    double res1=0,res2=0,result=1e15;
    f(i,-1,n){
        if(i==-1)
             res1=0;
        else
          res1=dis(x1,y1,ar[i].ff,ar[i].ss);
          //cout<<" res1  "<<(ll)res1<<endl;
          res2=0;
       f(j,0,n){
            if(dis(x1,y1,ar[j].ff,ar[j].ss)>res1){
               res2=max(dis(x2,y2,ar[j].ff,ar[j].ss),res2);
               //cout<<" res2  "<<(ll)res2<<" "<<j<<endl;
          }

       }
       result=min(result,res2+res1);
    }
    cout<<(ll)result<<endl;
          return 0;
}