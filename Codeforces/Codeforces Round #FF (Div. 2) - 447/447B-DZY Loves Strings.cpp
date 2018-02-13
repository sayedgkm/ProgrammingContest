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
int ar[28 + 2], k;
int main()
{
    ll sum = 0;
    string s;
    cin >> s >> k;
    f(i, 1, 27) cin >> ar[i];
    int len = s.length();
    int j = 0;
    f(i, 1, len + 1){
        sum += ar[s[j] - 96] * i;
        j++;
    }
    //cout << sum << endl;
    sort(ar + 1, ar + 27);
    f(i, len+1, len + k + 1)
        sum += ar[26] * i; cout << sum;

    return 0;
}