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
int ar[500];
int main()
{
    int n;
    cin>>n;
      int p=2*n-1;int mx=1e9,neg=0;
      ll sum=0;
      f(i,0,p){
        cin>>ar[i];
        if(ar[i]<0)
           neg++;
        sum+=abs(ar[i]);
        mx=min(mx,abs(ar[i]));
    }
  if(n%2==1) cout<<sum<<endl;
     else  {
        if(neg%2==0)
            cout<<sum<<endl;
        else{
            sum-=abs(mx)*2;
            cout<<sum<<endl;
        }

     }

      return 0;
}