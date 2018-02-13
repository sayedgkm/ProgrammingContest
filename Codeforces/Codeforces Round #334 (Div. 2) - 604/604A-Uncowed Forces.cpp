// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); int a;scanf("%d",&a);
#define take2(a,b); int a;int b;scanf("%d%d",&a,&b);
#define take3(a,b,c); int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
double ar[]={500.00,1000.00,1500.00,2000.00,2500.00};
double m[100],w[100];
int main()
   {
     f(i,0,5) cin>>m[i]; double result=0;
     f(i,0,5) cin>>w[i];
     f(i,0,5){
     result+=max(0.3*ar[i],((1-m[i]/250.0)*ar[i])-(50.0*w[i]));
     }
    take2(a,b);
    result+=100*a;
    result-=50*b;
    cout<<result<<endl;
}