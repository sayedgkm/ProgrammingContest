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
int ar[1000 + 50];
int main()
{
    int n, info = 0, counter = 0, turn = 0;
    cin >> n;
    f(i, 0, n) cin >> ar[i];
    for (int i = 0; ;i++)
    {
        if (i % 2== 0)
            f(j, 0, n)
        {
                if (info >= ar[j])
                {
                    info++;
                    ar[j] = 1e5; counter++;
                }

            }
        else
        for (int j = n - 1; j >= 0; j--)
        if (info >= ar[j])
        {
            info++;
            ar[j] = 1e5; counter++;
        }
        if (counter >= n) {
            cout << turn << endl; return 0;
        }
        turn++;


    }
    return 0;
}