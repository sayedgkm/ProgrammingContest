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
int ar[1005][1005];
int main()
{
    int n;
    take1(n);int x,y;
     f(i,0,n){
       take2(x,y);
       ar[x][y]=1;
    }
    int r,c,counter=0;
    vector<ll> v;
   for(int i=1;i<=1000;i++){
        r=1;c=i;counter=0;
         for(;r<=1000&&c<=1000;r++,c++){
              if(ar[r][c]) counter++;
            }
            if(counter) v.pb(counter);
    }
   for(int i=1;i<=1000;i++){
                  r=1;c=i;counter=0;
         for(;r<=1000&&c>=0;r++,c--){
              if(ar[r][c]) counter++;
            }
            if(counter) v.pb(counter);
    }
    for(int i=2;i<=1000;i++){
                  r=i;c=1;counter=0;
         for(;r<=1000&&c<=1000;r++,c++){
              if(ar[r][c]) counter++;
            }
            if(counter) v.pb(counter);
    }
    for(int i=2;i<=1000;i++){
                  r=i;c=1000;counter=0;
         for(;r<=1000&&c>=0;r++,c--){
              if(ar[r][c]) counter++;
            }
            if(counter) v.pb(counter);
    }
    ll sum=0;
    f(i,0,v.size()){
      v[i]--;
      sum+=(v[i]*(v[i]+1))/2;
    }
    cout<<sum<<endl;
      return 0;
}