using System;
using System.Text;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;
using System.Linq;

class Program {
    void Solve(Scanner cin) {
        int n = cin.nextInt();
        int k = cin.nextInt();
        List<long> ar = new List<long>();
        for(int i = 0;i<n;i++) {
            int a = cin.nextInt();
            a %= k;
            int left = k - a;
           // Console.WriteLine(left);
            if (left != k) {
                ar.Add((long)left);
            }
        }

        ar.Sort();
        Queue<long> q = new Queue<long>();
        long prev = -1;
        long mul = 0;
        for(int i = 0;i<ar.Count; i++) {
            if(ar[i]==prev) {
                ar[i] = ar[i] + k * mul;
                mul++;
            } else {
               mul = 1;
            }

            prev = ar[i];
        }
        ar.Sort();
        foreach(var item in ar) {
            q.Enqueue(item);
        };

        long res = 0; long x = 0;
        while(q.Count > 0) {
            long top = q.Peek();
            q.Dequeue();
          //  Console.WriteLine(top + " " + x);
            if(x <= top) {
                res += (top - x) + 1;
                x = top + 1;
            } else {
               
                q.Enqueue(top + k);
            }
        }

        Console.WriteLine(res);
    }
    public static int Main() {
        Scanner cin = new Scanner();
        Program program = new Program();
        int test = cin.nextInt();
        for (int i = 1; i <= test; i++) {
            program.Solve(cin);
        }
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