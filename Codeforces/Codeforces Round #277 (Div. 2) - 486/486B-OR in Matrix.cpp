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
int main()
{
    int ar[105][105], andd[105][105], orr[105][105], temp;
    f(i, 0, 103)
        f(j, 0, 103) andd[i][j] = 1;
    int m, n;
    cin >> m >> n;
    f(i, 0, m)
        f(j, 0, n)cin >> ar[i][j];
    f(i, 0, m)
    {
        f(j, 0, n){
            if (ar[i][j] == 0)
            {
                f(k,0, n)
                    andd[i][k] = 0;
                f(k, 0, m)
                    andd[k][j] = 0;
                
            }


        }
    }
    int check = 0;
    f(i, 0, m)
    {
        f(j, 0, n)
        {
            check = 0;
            f(k, 0, n)
            if (andd[i][k] == 1)
                check = 1;
            f(k, 0, m)
            if (andd[k][j] == 1)
                check = 1;
            if (ar[i][j] != check)
            {
                cout << "NO" << endl; return 0;
            }
        }
    }
    cout << "YES" << endl;
    f(i, 0, m){
        f(j, 0, n)cout << andd[i][j] << " "; cout << endl;
    }
    return 0;
}