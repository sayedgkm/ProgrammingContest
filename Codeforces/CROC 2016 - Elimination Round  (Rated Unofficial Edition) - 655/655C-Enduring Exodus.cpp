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
template < class T> inline T gcd(T a, T b){while(b){a%=b;swap(a,b);}return a;}
vector<int>v;
int ar[N];
inline int nxt(){
  int a;
  scanf("%d",&a);
  return a;
}
int main()
{
    int n=nxt();
    int k=nxt();
    string s;
    cin>>s;
    int x,y,mn=(int)1e9; int j=0; int cnt=0;int p=0,mid;
    for(int i=0;i<n;i++){
         if(s[i]=='0')
              ar[p++]=i;
         }
         int q=0;
    for(int i=k;i<p;i++,q++){
         mid=(ar[i]+ar[q])>>1;
         int low=lower_bound(ar,ar+p,mid)-ar;
         if(ar[low]!=mid)
               low--;
        mn=min(mn,max(abs(ar[i]-ar[low]),abs(ar[q]-ar[low])));
        mn=min(mn,max(abs(ar[i]-ar[low+1]),abs(ar[q]-ar[low+1])));

    }


cout<<mn<<endl;
      return 0;
}