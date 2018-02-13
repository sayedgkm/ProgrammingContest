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
int ar[100005];
int main()
{
    long long a,n;
    cin>>n;int count=1,mexi=0;
    for(int i=0;i<n;i++)
    cin>>ar[i];
    int maxi=1;
    for(int i=1;i<n;i++)
    {
       if(ar[i]<ar[i-1]) count=1;
       else count++;
       maxi=max(count,maxi);

    }
    cout<<maxi<<endl;

return 0;
}