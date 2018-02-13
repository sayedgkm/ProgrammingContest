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
int ar[100005], counter, temp;
int main()
{
    int fst, scnd;
    int n; cin >> n >> fst; int f = fst;
    f(i, 1, n)
    {
        cin >> scnd;
      if (scnd <fst)
        {
            counter++;
            temp = i;
        }
      fst = scnd;
    }
    
    if (counter == 0)puts("0");
    else if (counter == 1 && scnd <= f)
        cout << n - temp << endl;
    else
        puts("-1");

    return 0;
}