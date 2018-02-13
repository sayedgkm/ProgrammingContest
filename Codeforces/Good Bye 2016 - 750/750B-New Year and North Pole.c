using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A
{

    public class Helper
    {
        public List<Helper> Helpers { get; set; }
        public string From { get; set; }
        public List<string> To { get; set; }


        public void Load()
        {
            Helpers = new List<Helper>();

            Helper North = new Helper();
            North.From = "North";
            North.To = new List<string>();
            North.To.Add("South_x_+");
            North.To.Add("North_x_-");

            North.To.Add("West_y_+");
            North.To.Add("East_y_-");

            Helpers.Add(North);

            Helper South = new Helper();
            South.From = "South";
            South.To = new List<string>();

            South.To.Add("North_x_-");
            South.To.Add("South_x_+");

            South.To.Add("East_y_-");
            South.To.Add("West_y_+");

            Helpers.Add(South);


            Helper West = new Helper();
            West.From = "West";
            West.To = new List<string>();
            West.To.Add("South_x_+");
            West.To.Add("North_x_-");

            West.To.Add("East_y_-");
            West.To.Add("West_y_+");

            Helpers.Add(West);

            Helper East = new Helper();
            East.From = "East";
            East.To = new List<string>();
            East.To.Add("South_x_+");
            East.To.Add("North_x_-");


            East.To.Add("West_y_+");
            East.To.Add("East_y_-");

            Helpers.Add(East);

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var input = GetIntegerInputFromLine();

            List<object> lines = new List<object>();

            for (int i = 0; i < input; i++)
            {
                var inputs = GetStringInputsFromLine();

                lines.Add(inputs);


            }

            Helper helper = new Helper();
            helper.Load();

            long x = 0;
            long y = 0;

            var CurrentPosition = "North";

            var satisfy = true;

            foreach (var item in lines)
            {
                var inputs = (string[])item;
                var km = Convert.ToInt64(inputs[0]);
                var dir = inputs[1];

                var anyDirection = helper.Helpers.FirstOrDefault(f => f.From == CurrentPosition);

                var toDirection = anyDirection.To.FirstOrDefault(z => z.Split('_')[0] == dir);

                var toDI = toDirection.Split('_');

                if (x == 0)
                {

                    if (toDI[0] != "South")
                    {
                        satisfy = false;
                        break;
                    }

                }

                if (x == 20000)
                {
                    if (toDI[0] != "North")
                    {
                        satisfy = false;
                        break;
                    }
                }
                
              

                if (toDirection == null)
                {

                    satisfy = false;
                    break;
                }
                else
                {


                    if (toDI[1] == "x")
                    {
                        if (toDI[2] == "+")
                        {
                            x += km;
                        }
                        else
                        {
                            x -= km;
                        }
                    }
                    else
                    {
                        if (toDI[2] == "+")
                        {
                            y += km;
                        }
                        else
                        {
                            y -= km;
                        }
                    }
                }
                  if(x>20000||x<0){
                 satisfy=false;
                 break;
                 
                  } 

                CurrentPosition = dir;
            }


            if (satisfy && CurrentPosition == "North" && x <= 0)
            {
                Console.WriteLine("YES");
            }
            else
            {
                Console.WriteLine("NO");
            }

        }

        public static bool Bfs(Dictionary<string, List<string>> graph, string from, string to)
        {
            Dictionary<string, int> level = new Dictionary<string, int>();
            Dictionary<string, int> visited = new Dictionary<string, int>();

            Queue<string> queue = new Queue<string>();

            queue.Enqueue(from);
            level[from] = 1;
            visited[from] = 1;
            while (queue.Count() > 0)
            {
                string front = queue.Peek();

                if (front == to)
                {
                    return true;
                }

                List<string> values;

                if (graph.TryGetValue(front, out values))
                {

                    foreach (var item in values)
                    {
                        if (!visited.ContainsKey(item))
                        {
                            level[item] = level[front] + 1;
                            visited[item] = 1;
                            queue.Enqueue(item);
                        }
                    }
                }


                queue.Dequeue();

            }

            return false;
        }
        public void InputBfs()
        {
            var input = GetIntegerInputFromLine();

            Dictionary<string, List<string>> graph = new Dictionary<string, List<string>>();

            for (int i = 0; i < input; i++)
            {
                var inputs = GetStringInputsFromLine();
                AddOrUpdate(graph, inputs[0], inputs[1]);
                AddOrUpdate(graph, inputs[1], inputs[0]);
            }

            var ins = GetStringInputsFromLine();

            var isRoute = Bfs(graph, ins[0], ins[1]);

            if (!isRoute)
            {
                Console.WriteLine("No route");
            }
            else
            {
                Console.WriteLine("route");
            }
        }

        public static IDictionary<TKey, List<TValue>> AddOrUpdate<TKey, TValue>(IDictionary<TKey, List<TValue>> dictionary, TKey key, TValue value)
        {
            List<TValue> values;

            if (dictionary.TryGetValue(key, out values))
            {
                values.Add(value);

                dictionary[key] = values;
            }
            else
            {
                values = new List<TValue>();
                values.Add(value);
                dictionary[key] = values;
            }

            return dictionary;
        }


        static int GetIntegerInputFromLine()
        {
            var input = Convert.ToInt32(Console.ReadLine().Trim());
            return input;
        }

        static int[] GetIntegerInputsFromLine()
        {
            var inputs = Console.ReadLine().Split(' ').Select(x => Convert.ToInt32(x.Trim())).ToArray();
            return inputs;
        }

        static long GetLongInputFromLine()
        {
            var input = Convert.ToInt64(Console.ReadLine().Trim());
            return input;
        }

        static long[] GetLongInputsFromLine()
        {
            var inputs = Console.ReadLine().Split(' ').Select(x => Convert.ToInt64(x.Trim())).ToArray();
            return inputs;
        }

        static double GetDoubleInputFromLine()
        {
            var input = Convert.ToDouble(Console.ReadLine().Trim());
            return input;
        }

        static double[] GetDoubleInputsFromLine()
        {
            var inputs = Console.ReadLine().Split(' ').Select(x => Convert.ToDouble(x.Trim())).ToArray();
            return inputs;
        }

        static string GetStringInputFromLine()
        {
            var input = Console.ReadLine();
            return input;
        }

        static string[] GetStringInputsFromLine()
        {
            var inputs = Console.ReadLine().Split(' ');
            return inputs;
        }
    }
}