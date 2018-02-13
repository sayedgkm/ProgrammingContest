#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
using namespace std;
int v[4000+10],d[4000+10],p[4000+10];int result[4000+10],check[1000000+10];
int main()
{
    int n,a,b;
    scanf("%d",&n);
    f(i,0,n)
    {
       cin>>v[i]>>d[i]>>p[i];

 }
 int lost=0;
 f(i,0,n)
 {
     if(p[i]>=0)
     {
          result[lost++]=i+1;
         ll q=v[i];ll k=0;
         for(int j=i+1;j<n;j++)
         {
             if(p[j]<0) continue;
             p[j]-=q;
             p[j]-=k;
             if(q)
             q--;
             if(p[j]<0&&k<1e7)
                k+=d[j];
            }

     }


    }
    printf("%d\n",lost);

    for(int i=0;i<lost;i++)
    {
        printf("%d ",result[i]);

    }



return 0;
}