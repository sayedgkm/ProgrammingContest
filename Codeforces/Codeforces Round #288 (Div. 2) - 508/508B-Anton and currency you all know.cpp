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
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define long long ll
using namespace std;
int ar[100005];
int main()
{
    string s; int m, j = 0, check = 0;
    cin >> s;
    int last = s[s.length() - 1] - '0';
    for (int i = 0; i<s.length() - 1; i++)
    {
        int p = s[i] - '0';
        if (p % 2 == 0)
        {
            ar[j++] = i;
        }

    }
    if (j == 0)
        puts("-1");
    else
    {
        for (int i = 0; i<j; i++)
        {
            int p = s[ar[i]] - '0';
            if (last>p)
            {
                s[s.length() - 1] = p + '0';
                s[ar[i]] = last + '0';
                cout << s << endl; return 0;

            }
        }
        s[s.length() - 1] = s[ar[j - 1]];
        s[ar[j - 1]] = last + '0';
        cout << s << endl;
    }

    return 0;
}