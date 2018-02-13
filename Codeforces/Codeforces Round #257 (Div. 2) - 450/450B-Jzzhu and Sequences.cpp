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
#define mod 1000000007
using namespace std;
int main()
{
    ll f1, f2, f3, limit;
    cin >> f1 >> f2 >> limit;
    int ar[]={-f2-(-f1),f1,f2,f2-f1,-f1,-f2};
    f3=ar[(limit%6)]%mod;
    cout << (f3 + mod) % mod << endl;

    return 0;
}