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
ll n;
int p(int a)
{
    if(a==1) return 0;
    for(int i=2;i<=sqrt(a);i++)
      if(a%i==0)
        return 0;
        return 1;
}
int main()
{
   // cout<<p(2)<<endl;
    int n,a,b,c;
    scanf("%i64d",&n);
      if(p(n))
      {
         printf("1\n%d",n);return 0;
      }
      for(int i=n-1; ;i--)
      {
          if(p(i))
          {
              a=i;
              n=n-i;
              break;

          }
      }
      if(p(n))
      {
        printf("2\n%d %d ",a,n);return 0;


      }
         b=2;
         c=n-2;
        //cout<<b<<" "<<c;
         if(p(b)&&p(c))
         {
              printf("3\n%d %d %d",a,b,c);return 0;
         }


      for(int i=3;i<=n;i+=2)
      {
          b=i;
          c=n-i;
          if(p(b)&&p(c))
         {
             printf("3\n%d %d %d",a,b,c);return 0;
         }


      }
return 0;
}