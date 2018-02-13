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
using namespace std;
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
#define lltake1(a); scanf("%lld",&a);
#define lltake2(a,b); scanf("%lld%lld",&a,&b);
#define lltake3(a,b,c); scanf("%lld%lld%lld",&a,&b,&c);

struct p{

  int num;
  int dif;


}ar[100000+10];
bool comp(p a,p b)
{

    return a.dif<b.dif;

}
int main()
   {
       int n,k;
       take2(n,k);
       f(i,0,n)
       {
           take1(ar[i].num);
           if(ar[i].num%10==0)
            ar[i].dif= 0;
            else
               ar[i].dif=10-ar[i].num%10;

       }
    sort(ar,ar+n,comp);
        int result=0;
    f(i,0,n)
    {
        if(ar[i].dif!=0)
        {
            if(k>=ar[i].dif)
            {

                k-=ar[i].dif;
                ar[i].num+=ar[i].dif;
            }


        }

        result+=ar[i].num/10;
    }
   cout<<min(result+k/10,10*n)<<endl;

return 0;
}