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
int main()
{
int n,result,first,second;
cin>>n;
cin>>first;
result=n*2-1+first;
n--;
while(n--)
{
    cin>>second;
     result+=abs(second-first);first=second;
}
cout<<result;
return 0;
}