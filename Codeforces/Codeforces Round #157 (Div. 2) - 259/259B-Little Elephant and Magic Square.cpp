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
    int ar[5][5]; int maxi = 0, temp, a, b, c;
    for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
    {
        cin >> ar[i][j];
        
    }

    ar[1][1] = (ar[3][2] + ar[2][3]) / 2;
    ar[2][2] = (ar[2][1] + ar[2][3]) / 2;
    ar[3][3] = (ar[2][1] + ar[1][2]) / 2;
    
    for (int i = 1; i <= 3; i++){
        for (int j = 1; j <= 3; j++)
            cout << ar[i][j] << " "; cout << endl;
    }


    return 0;
}