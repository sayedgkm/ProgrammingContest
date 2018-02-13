// ==========================================================================
//
//                   Bismillahir-Rahmanir-Rahim
//
// ==========================================================================

#include <bits/stdc++.h>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); int a;scanf("%d",&a);
#define take2(a,b); int a;int b;scanf("%d%d",&a,&b);
#define take3(a,b,c); int a;int b;int c;scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); int a;int b;int c;int d;scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
multiset<ll> ar;
int main()
   {
     take1(n);
     f(i,0,n*n){
       take1(a);
       ar.insert(a);
       }
       vector<ll> p;
       multiset<ll>:: iterator it;

      while(!ar.empty()){
             it=ar.end(); it--;
             ll res=*it;

              cout<<res<<" ";
             f(i,0,p.size()){
                  ll r=__gcd(p[i],res);
                  ar.erase(ar.find(r));
                  ar.erase(ar.find(r));
              }
              ar.erase(ar.find(res));
        p.push_back(res);
      }

}