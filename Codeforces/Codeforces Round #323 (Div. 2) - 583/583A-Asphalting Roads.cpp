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
int ar[1000], br[10000], m[1000];
int main()
{
    int n, a, b, j = 0;
    cin >> n;
    f(i, 1, n *n+1)
    {
        cin >> a >> b;
        if (ar[a] == 0 && br[b] == 0)
        {
            ar[a] = 1;
            br[b] = 1;
            m[j++] = i; 
            
        }
    }
    f(i, 0, j) cout << m[i] << " ";
    return 0;
}