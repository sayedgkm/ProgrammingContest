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
        List<int> A = new List<int>();
        List<int> B = new List<int>();
        List<int> C = new List<int>();
        for(int i = 0;i<n;i++) {
            int t = cin.nextInt();
            int a = cin.nextInt();
            int b = cin.nextInt();
            if(a==1 && b==1) {
                C.Add(t);
            } else if(a==1) {
                A.Add(t);
            } else if(b==1) {
                B.Add(t);
            }
        }
       
        A = A.OrderBy(x=> x).ToList();
        B.Sort();
        C.Sort();
        long res = 0;
        int x = 0;
        int y = 0;
        int z = 0;
        int f = 0;
        int s = 0;
        if(A.Count+C.Count < k  || B.Count + C.Count < k) {
            Console.WriteLine(-1);
        } else {
            while(f<k || s<k) {
                long first = x < A.Count ? A[x] : int.MaxValue;
                long second = y < B.Count ? B[y] : int.MaxValue;
                long both = z < C.Count ? C[z] : int.MaxValue;
                if (f < k && s < k) {
                    if(first+second < both) {
                        f++;
                        s++;
                        x++;y++;
                        res += first + second;
                    } else {
                        f++;
                        s++;
                        z++;
                        res += both;
                    }
                } else if(f<k) {
                    if(first < both) {
                        res += first;
                        f++;
                        x++;
                    } else {
                        res += both;
                        f++;
                        z++;
                    }
                }  else if(s<k) {
                    if(second < both) {
                        s++;
                        res += second;
                        y++;
                    } else {
                        s++;
                        res += both;
                        z++;
                    }
                }
            }
            Console.WriteLine(res);
        }
    }
    public static int Main() {
        Scanner cin = new Scanner();
        Program program = new Program();
        int test = 1;
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