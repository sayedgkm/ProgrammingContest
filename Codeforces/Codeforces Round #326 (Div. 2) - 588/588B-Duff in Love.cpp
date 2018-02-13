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
long long ar[1000000 + 100], br[1000000 + 10];long long cr[1000000 + 100];
int main()
{
    for (ll i = 2; i <= 1000000 + 15; i++)
             cr[i] = i*i;
    //cout << cr[999983] << endl;
    ll a;
    cin >> a; int m = 2; if (a == 1){ puts("1"); return 0; }
    ll sq = sqrt(a); int p = 0, q = 0;
    for (int i = 1; i <= sq; i++)
    {
        if (a%i == 0){
            ar[p++] = i;
            //if (sq*sq != a)
            br[q++] = a / i;
        }


    }
    q--;
    
    ll xx = p - 1, yy = br[0], zz = 0;
    for (int i = 1; i<p; i++)
    {
        if (zz <= q)
        {
            if (br[zz] % cr[ar[i]] == 0)
            {
                i = 0;
                zz++;
                if (zz <= q)
                    yy = br[zz];
                else
                    yy = br[zz - 1];
            }
        }
        else
        {
            if (ar[xx] % cr[ar[i]] == 0)
            {
                i = 0;
                xx--;
                yy = ar[xx];
            }
            yy = ar[xx];

        }
    }
    cout << yy << endl;

    return 0;
}