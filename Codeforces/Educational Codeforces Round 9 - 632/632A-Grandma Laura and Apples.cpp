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
string s[100];
int main()
{
    int n,p;
    cin>>n>>p;
    f(i,0,n)
      cin>>s[i];
      double ans=0,temp=0;
    for(int i=n-1;i>=0;i--){
        if(s[i][s[i].size()-1]=='s'){
            temp+=0.5;
            temp=temp*2;
            ans+=temp/2;
        }
        else{
            temp*=2;
            ans+=temp/2;
        }
      }
      ans=ans*p;
      ll bb=(ll)ans;
      cout<<bb<<endl;
      return 0;
}