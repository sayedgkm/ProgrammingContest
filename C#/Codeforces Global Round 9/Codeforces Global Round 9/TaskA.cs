using System;
using System.Text;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;
using System.Linq;
using System.IO;
using System.Security.Cryptography;

class Program {
    void Solve(int testCase, Scanner sc) {
        int n = sc.nextInt();
        int[] ar = new int[n];
        int[] dif = new int[n];
        int neg = 0;
        int pos = 0;
        for(int i = 0;i<n;i++) {
            ar[i] = sc.nextInt();
            if(i>0) {
                dif[i-1] = ar[i] - ar[i - 1];
                if (dif[i-1] < 0) neg++;
                if (dif[i-1] > 0) pos++;
            }
        }
        if(neg>pos) {
            for(int i = 1;i<n-1;i++) {
                if (neg > pos) {
                    if (dif[i - 1] < 0 && dif[i] < 0) {
                        ar[i] = ar[i] * -1;
                        neg--;
                    }
                }
            }
        } else {
            for (int i = 1; i < n - 1; i++) {
                if (neg < pos) {
                    if (dif[i - 1] > 0 && dif[i] > 0) {
                        ar[i] = ar[i] * -1;
                        pos--;
                    }
                }
            }
        }

        Console.WriteLine(string.Join(" ", ar));

    }
    public static int Main() {
        //  Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        Scanner sc = new Scanner();
        Program program = new Program();
        int test = sc.nextInt();
        for (int i = 1; i <= test; i++) {
            program.Solve(i, sc);
        }
        //   Console.Out.Flush();
        return 0;
    }
}


class Scanner {
    string[] s;
    int i;

    char[] cs = new char[] { ' ' };

    public Scanner() {
        s = new string[0];
        i = 0;
    }

    public string next() {
        if (i < s.Length) return s[i++];
        string st = Console.ReadLine();
        while (st == "") st = Console.ReadLine();
        s = st.Split(cs, StringSplitOptions.RemoveEmptyEntries);
        if (s.Length == 0) return next();
        i = 0;
        return s[i++];
    }

    public int nextInt() {
        return int.Parse(next());
    }
    public int[] ArrayInt(int N, int add = 0) {
        int[] Array = new int[N];
        for (int i = 0; i < N; i++) {
            Array[i] = nextInt() + add;
        }
        return Array;
    }

    public long nextLong() {
        return long.Parse(next());
    }

    public long[] ArrayLong(int N, long add = 0) {
        long[] Array = new long[N];
        for (int i = 0; i < N; i++) {
            Array[i] = nextLong() + add;
        }
        return Array;
    }

    public double nextDouble() {
        return double.Parse(next());
    }

    public double[] ArrayDouble(int N, double add = 0) {
        double[] Array = new double[N];
        for (int i = 0; i < N; i++) {
            Array[i] = nextDouble() + add;
        }
        return Array;
    }
}