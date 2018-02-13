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
template < class T> inline T gcd(T a, T b){return a%b ? gcd(b,a%b) : b;}
using namespace std;
int ar[N];
int main()
{
    int n;
    cin>>n;
    if(n%2){
         int p=1,i;
        for(i=1;i<=n/2+1;i++){
            ar[i]=p;p+=2;
        }
        p=n-2;
        for(;i<=n;i++) ar[i]=p,p-=2;
        p=2;
        for(;i<=n+n/2;i++) ar[i]=p,p+=2;
        p=n-1;
        for(;i<n*2;i++) ar[i]=p,p-=2;
        ar[2*n]=n;
    }
    else {
         int p=1,i;
        for(i=1;i<=n/2;i++){
            ar[i]=p;p+=2;
        }
        p=n-1;
        for(;i<=n;i++) ar[i]=p,p-=2;
        p=2;
        for(;i<=n+n/2;i++) ar[i]=p,p+=2;
        p=n-2;
        for(;i<n*2;i++) ar[i]=p,p-=2;
        ar[2*n]=n;
    }
    for(int i=1;i<=n*2;i++) cout<<ar[i]<<" ";

    puts("");
      return 0;
}