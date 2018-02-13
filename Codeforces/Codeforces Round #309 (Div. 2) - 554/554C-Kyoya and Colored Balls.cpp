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
#define MOD 1000000007
using namespace std;
ll ar[1000 + 10][1000 + 10]; ll up, down; int br[100000 + 10];
int main()
{
    ar[0][0] = 1;
    f(i, 0, 1000 + 2)
    {
        ar[i][i] = 1; ar[i][0] = 1;
        f(j, 1, i)
            ar[i][j] = (ar[i - 1][j] + ar[i - 1][j - 1]) % MOD;
    }

    int n;ll sum = 1, total = 0, a;
    take1(n);
    f(i, 0, n){
        take1(a);
        sum =(sum%MOD* ar[total + a - 1][a - 1] % MOD)%MOD;
        total += a;

    }

    cout << sum%MOD << endl;


    return 0;
}