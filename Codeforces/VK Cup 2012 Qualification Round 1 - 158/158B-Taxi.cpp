#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
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
using namespace std;
int main()
{
    int n, group1 = 0, group2 = 0, group3 = 0, result = 0, s, temp;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == 4) result++;
        if (s == 3) group3++;
        if (s == 2) group2++;
        if(s==1) group1++;

    }
    group1=max(group1-group3,0);
    result+=group3;
    group2=group2*2+group1;
    if(group2%4==0) result+=group2/4;
    else result+=1+group2/4;

   cout << result << endl;
    return 0;
}