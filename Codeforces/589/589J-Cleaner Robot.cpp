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
char ar[100][100]; int a, b; int row, clm, check[100][100], counter=1,flag; char p;

int main()
{

    take2(a, b);
    f(i, 1, a + 1)
        f(j, 1, b + 1)
    {
            cin >> ar[i][j];
            if (ar[i][j] == 'U' || ar[i][j] == 'R' || ar[i][j] == 'D' || ar[i][j] == 'L')
            {
                row = i;
                clm = j;

                p = ar[i][j];
                ar[i][j] = '.';
                check[i][j] = 1;
            }
        }


    while (1)
    {
        if (p == 'U')
        {
            if (ar[row - 1][clm] == '.')
            {
                row--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check [row][clm] = 1;
            }
            else if (ar[row][clm + 1] == '.')
            {
                clm++;
                
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'R';
                
            }
            else if (ar[row + 1][clm] == '.')
            {
                row++;
                if (check[row][clm] == 0)
                    counter++;
                else flag++;
                check[row][clm] = 1;
                p = 'D';
                continue;
            }
            else if (ar[row][clm - 1] == '.')
            {
                clm--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'L';
                
            }
            else
                break;

            

        }
        if (p == 'R') {
            if (ar[row][clm + 1] == '.')
            {
                clm++;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
            }
            else if (ar[row + 1][clm] == '.')
            {
                row++;
                if (check[row][clm] == 0)
                    counter++;
                else flag++;
                check[row][clm] = 1;
                p = 'D';
                
            }
            else if (ar[row][clm - 1] == '.')
            {
                clm--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'L';
                
            }
            else if (ar[row - 1][clm] == '.')
            {
                row--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'U';
                
            }
            else break;
            
        }
        if (p == 'D') {
            if (ar[row + 1][clm] == '.')
            {
                row++;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
            }
            else if (ar[row][clm - 1] == '.')
            {
                clm--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'L';
            
            }
            else if (ar[row - 1][clm] == '.')
            {
                row--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'U';
                
            }
            else if (ar[row][clm + 1] == '.')
            {
                clm++;

                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'R';
                
            }
            else break;

        }
        if (p == 'L') {
            if (ar[row][clm - 1] == '.')
            {
                clm--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
            }
            else if (ar[row - 1][clm] == '.')
            {
                row--;
                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'U';
                
            }
            else if (ar[row][clm + 1] == '.')
            {
                clm++;

                if (check[row][clm] == 0)
                    counter++;
                else
                    flag++;
                check[row][clm] = 1;
                p = 'R';
                
            }
            else if (ar[row + 1][clm] == '.')
            {
                row++;
                if (check[row][clm] == 0)
                    counter++;
                else flag++;
                check[row][clm] = 1;
                p = 'D';
                
            }
            else
                break;
            
        }
        if (flag > 150)
            break;

        //cout << p << " " << row<<" " << clm <<" "<<counter<< endl;
    }

    cout << counter << endl;


    return 0;
}