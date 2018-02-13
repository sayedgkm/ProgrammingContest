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
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
int main()
{
   int a,b,c,d,e,f,ta,tb;ll temp,result,result1;
   cin>>a>>b>>c>>d>>e>>f;
   ta=a+b+c;
   tb=a+e+f;
   temp=max(ta,tb);
  // cout<<temp<<endl;
   temp*=temp;

   temp-=(a*a+c*c+e*e);
     cout<<temp<<endl;
return 0;
}