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
bool comp(int a,int b) {
  return a>b
;}
int main()
{
 int a,b;
 cin>>a>>b;
 f(i,0,a) cin>>ar[i];
   sort(ar,ar+a,comp);
   ll sum=0,c=0;
    f(i,0,a){
        sum+=ar[i];
        c++;
        if(sum>=b) break;

    }
  cout<<c<<endl;
return 0;
}