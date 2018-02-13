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
ll ar[N];
int main()
{
    ll n;
    cin>>n;ll sum=0;
    f(i,0,n){
     cin>>ar[i];
     sum+=ar[i];
    }
    if(sum%2==0){

        cout<<sum<<endl;
        return 0;
    }
    sort(ar,ar+n);
    f(i,0,n){
        if(ar[i]%2){
            sum-=ar[i];
            cout<<sum<<endl;
            return 0;
        }
    }

      return 0;
}