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
int ar[100000 + 10];
int main()
{
    int n, a, b;
    scanf("%d", &n);
    f(i, 1, n+1)
        cin >> ar[i];
    int counter = 0;
    f(i, 1, n+1)
    {
        
        if (ar[i] == 1)
            counter++;
        else if (ar[i] == 0 && ar[i + 1] == 1&&ar[i-1]==1)
            counter++;
            
        

    }
    printf("%d", counter);
    return 0;
}