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
multiset<int> p;
int ar[100000+10];
int main()
   {
       take1(n);
       f(i,0,n) cin>>ar[i];
       int range=1,index=0,counter=0,j=0;
          f(i,0,n){
          p.insert(ar[i]);
          while(abs(*p.rbegin()-*p.begin())>1)
               p.erase(p.find(ar[index++]));
               counter=p.size();
          range=max(range,counter);
          //cout<<counter<<endl;

    }

     cout<<range<<endl;

}