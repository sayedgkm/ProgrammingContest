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
vector<int> v;
int ar[10];
int div(int n){

  int sq=sqrt(n);
    f(i,1,sq+1){
       if(n%i==0){
          v.pb(i);
          v.pb(n/i);

       }
    }
    if(sq*sq==n) v.pop_back();

}
int main()
{
    int n;
    cin>>n;
    int p=n;
    while(p){
        ar[p%10]=1;
        p/=10;
    }
    int c=0;
    div(n);
    f(i,0,v.size()){
       p=v[i];
      while(p){
         if(ar[p%10]==1){
            c++;break;
         }
        p/=10;
      }
    }
    cout<<c<<endl;
      return 0;
}