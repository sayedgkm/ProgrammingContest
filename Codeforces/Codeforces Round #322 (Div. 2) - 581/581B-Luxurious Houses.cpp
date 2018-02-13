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
bool comp(long long a, long long b) { return a>b; }
long long ar[100005] = { 0 }, br[100005], n, maxi, m = 0;
int main()
{

    cin >> n;
    for (int i = 0; i<n; i++)cin >> ar[i];
    maxi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (maxi < ar[i])
        {
            maxi = ar[i];
            br[i] = 0;
        }
            
        else if (ar[i] == maxi) 
            br[i] = 1;
        else
            br[i] = (maxi - ar[i] + 1);

    }
    for (int i = 0; i<n; i++)
    {
        cout << br[i] << " ";

    }
    return 0;
}