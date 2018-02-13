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
int ar[100000 + 5], br[100000 + 5];
int main()
{
    int n, sum, mini, result;
    cin >> n;
    f(i, 0, n)
    {
        cin >> ar[i] >> br[i];
    }
    mini = br[0];
    result = ar[0] * br[0];
    sum = 0;
    f(i, 1, n)
    {
        mini = min(br[i], mini);
        while (br[i]>mini)
        {
            mini = min(br[i], mini);
            result += ar[i] * mini;
            i++;
        }
    
        result += ar[i] * br[i];
        mini = min(br[i], mini);
    }
    cout << result << endl;


    return 0;
}