#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include<map>
#define ll long long
#define f(x,y,z) for(int x=y;x<z;x++)
#define take1(a); scanf("%d",&a);
#define take2(a,b); scanf("%d%d",&a,&b);
#define take3(a,b,c); scanf("%d%d%d",&a,&b,&c);
#define take4(a,b,c,d); scanf("%d%d%d%d",&a,&b,&c,&d);
using namespace std;
char ar[10][10];
int main()
{
    char p; int m = 0, n = 0;
    f(i, 0, 8)
        f(j, 0, 8)
    {
            cin >> ar[i][j];
        }
    int a = 0, b = 0;
    f(i, 0, 8)
        f(j, 0, 8)
    {
            int check = 0;
            if (ar[i][j] == 'W'){
                for (int k = i-1; k >= 0; k--){

                    if (ar[k][j] != '.')
                    {
                        check++;
                    }

                }
                if (check == 0)
                {
                    a = i;
                    goto poop;

                }
            }
            
        }
    poop:
    for (int i = 7; i >= 0; i--)
    for (int j = 7; j >= 0; j--)
    {
            int check = 0;
            if (ar[i][j] == 'B'){
                for (int k = i+1; k < 8; k++){
                    if (ar[k][j] != '.')
                    {
                        check++;
                    }


                }
                if (check == 0)
                {
                    b = 7 - i;
                    goto loop;

                }
            }
        }
    loop:
    //cout << a << " " << b << endl;
    if (a>b)
        puts("B");
    else
        puts("A");
}