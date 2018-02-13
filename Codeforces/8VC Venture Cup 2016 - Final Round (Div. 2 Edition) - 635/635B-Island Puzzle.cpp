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
int ar[N];int br[N];
int main()
{
    int n;
    cin>>n;int p=0;
    f(i,0,n){
        int x;
        scanf("%d",&x);
        if(x)
        ar[p++]=x;
    }
    p=0;
    f(i,0,n){
        int x;
        scanf("%d",&x);
        if(x) br[x]=p++;
    }
    f(i,1,n-1){
       int pos=br[ar[i-1]];
         if(pos==n-2){
            if(br[ar[i]]!=0){
                puts("NO");return 0;
            }
         }
         else {
            if(br[ar[i]]!=pos+1){
                puts("NO");return 0;
            }
         }
    }
    puts("YES");
      return 0;
}