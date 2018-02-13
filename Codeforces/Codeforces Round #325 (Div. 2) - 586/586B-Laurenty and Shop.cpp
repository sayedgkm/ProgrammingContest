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
int ar[150], br[150], cross[150], cross1, dis[150];
int main()
{
    int n, a, b, mini, m;
    scanf("%d", &n);
    f(i, 0, n-1)
       cin >> ar[i];
    f(i, 0, n - 1)
        cin >> br[i];
    f(i, 0, n)
        cin >> cross[i];
    
    m = n-1;
    dis[0] = cross[n-1];
    for (int i = 0; i<n-1; i++)
        dis[0] += ar[i]; int list = 1;
    for (int j = n-2; j >= 0; j--)
    {
          dis[list] = dis[list - 1] + br[j] + cross[j] - ar[j] - cross[m];
            m--;
           list++;

    }
    sort(dis, dis + n );
    cout << dis[0] + dis[1] << endl;
    return 0;
}