#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
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
using namespace std;
long long ar[100005];
int main()
{
    long long h,n,result,a;
    cin>>h>>n;
    for(int i=0;i<n;i++)cin>>ar[i];
    result=ar[0]-1;
    for(int i=1;i<n;i++)
      {
          if(ar[i]>ar[i-1]) result+=ar[i]-ar[i-1];
          if(ar[i]<ar[i-1]) result+=h-ar[i-1]+ar[i];
        }
        cout<<result<<endl;
return 0;
}