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
int ar[1005],res[1005];
map<int,int> mp;
int main()
{
    int n;
    cin>>n;int zero=0;
    f(i,0,n){
        scanf("%d",ar+i);mp[ar[i]]++;

    }
    sort(ar,ar+n);
   int ans=2;
   ans=max(ans,mp[0]);
   f(i,0,n) f(j,0,n){
      if(i==j) continue;
      res[0]=ar[i];
      res[1]=ar[j];
        if(res[0]==0&&res[1]==0){
            continue;
        }
        if(i&&ar[i]==ar[i-1]) continue;
        map<int,int> ck;
        ck[res[0]]++;
        ck[res[1]]++;
        int c=2,k;
      for(k=2;;k++){
          res[k]=res[k-1]+res[k-2];
         // cout<<res[k]<<endl;
          if(ck[res[k]]<mp[res[k]]){
                c++;
              ck[res[k]]++;
            }
            else break;
        }
    ans=max(c,ans);
    if(ans==n) goto poo;
   }
   poo:;
  cout<<ans<<endl;
      return 0;
}