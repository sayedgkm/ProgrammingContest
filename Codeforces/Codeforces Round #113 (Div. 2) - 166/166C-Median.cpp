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
#define        N                               10010
#define        M                               1000000007
#define        pi                              acos(-1.0)
#define        ff                              first
#define        ss                              second
#define        pb                              push_back
using namespace std;
int ar[N];
int main()
{
    int n,x;
    take2(n,x);int a=0,b=0;
    int flag=0;
    f(i,1,n+1){
       cin>>ar[i];
       if(ar[i]==x)
          flag=1;
    }
    int ans=0;
    sort(ar+1,ar+n+1);
      while(1){

        int p=(n+1)/2;
        if(ar[p]==x) break;
        n++;
        ar[n]=x;
        ans++;
        sort(ar+1,ar+n+1);
        // cout<<p<<" "<<ar[p]<<" "<<n<<endl;
    }
    cout<<ans<<endl;
      return 0;
}