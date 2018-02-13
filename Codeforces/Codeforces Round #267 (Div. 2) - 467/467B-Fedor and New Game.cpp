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
int result;
int main()
{
   long long n,m,k;long long ar[10000];
   cin>>n>>m>>k;
   for(int i=0;i<=m;i++)cin>>ar[i];
   for(int i=0;i<m;i++) if(__builtin_popcount(ar[i]^ar[m])<=k)result++; cout<<result<<endl;

return 0;
}