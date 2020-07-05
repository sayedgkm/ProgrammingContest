using System;
using System.Text;
using System.Diagnostics;
using System.Numerics;
using System.Collections.Generic;
using System.Linq;
using System.IO;

class Program {

    void Solve(Scanner cin) {
        LinkedList<int> list = new LinkedList<int>();
        list.AddLast(5);
        list.AddFirst(10);
        Console.WriteLine(list.First());
        Console.WriteLine(list.Last());
        list.RemoveLast();
        list.RemoveFirst();
        list.AddLast(3);
        Console.WriteLine(list.First());
        Console.WriteLine(list.Last());

        HashSet


    }
    public static int Main() {
      //  Console.SetOut(new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false });
        Scanner sc = new Scanner();
        Program program = new Program();
        int test = 1;
        for (int i = 1; i <= test; i++) {
            program.Solve(sc);
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