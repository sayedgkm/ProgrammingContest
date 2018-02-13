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
ll ar[N];string s;ll a,b;ll ans=0;
int main()
{
    int n;
    cin>>n;
    f(i,0,n) scanf("%I64d",ar+i);
    cin>>s;
    f(i,0,n){
      if(s[i]=='A') a+=ar[i];
      else b+=ar[i];
    }
    ll tema=a;
    ll temb=b;
    ans=b;
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            a-=ar[i];
            b+=ar[i];
        }
        else {
            b-=ar[i];
            a+=ar[i];
        }
        ans=max(b,ans);
    }
    a=tema;
    b=temb;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='A'){
            a-=ar[i];
            b+=ar[i];
        }
        else {
            b-=ar[i];
            a+=ar[i];
        }
        ans=max(b,ans);

    }
    cout<<ans<<endl;

      return 0;
}