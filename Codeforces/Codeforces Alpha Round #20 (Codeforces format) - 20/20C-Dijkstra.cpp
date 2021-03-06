#include<bits/stdc++.h>
#define loop(i, n) for(;i<n;i++)

using namespace std;

const int MAX= 100001;

vector<int> edgeList[MAX];
vector<int> edgeCost[MAX];
long long totaldistance[MAX];
int path[MAX];

#define pii pair<int,int>

struct compare {
 bool operator()(const pii &a, const pii &b)
  const
 {
  return a.second > b.second;

 }

};



int dijkstra(int source, int destination)
{


 memset(totaldistance, 1, sizeof totaldistance);

 priority_queue<pii, vector<pii>, compare> pq;

 pq.push(pii(source, 0));
 totaldistance[source] = 0;

 while (!pq.empty())
 {
  pii top = pq.top();

  pq.pop();

  int u = top.first;

  if (u == destination)
  {
   return 1;
  }

  int size = edgeList[u].size();

  int i = 0;

  for ( i = 0; i < size; i++)
  {
   long long tcst = totaldistance[u] + edgeCost[u][i];
   int v = edgeList[u][i];

   if (tcst < totaldistance[v])
   {
    totaldistance[v] = tcst;

    pq.push(pii(v, tcst));

    path[v] = u;
   }
  }
 }


 return -1;
}




int main()
{

 int numberOfNode, numberOfEdge;
 int i = 0;
 cin >> numberOfNode;
 cin >> numberOfEdge;


 loop(i, numberOfEdge)
 {
  int node1, node2, cost;

  cin >> node1;
  cin >> node2;
  cin >> cost;

  edgeList[node1].push_back(node2);
  edgeList[node2].push_back(node1);


  edgeCost[node1].push_back(cost);
  edgeCost[node2].push_back(cost);


 }

 int result = dijkstra(1,numberOfNode);

 if (result == -1)
 {
  cout << "-1" ;
 }
 else
 {
  vector<int> nodes;

  nodes.push_back(numberOfNode);

  int dn = 0;
  do
  {
   dn = path[numberOfNode];
   nodes.push_back(dn);
   numberOfNode = dn;

  } while (dn!=1);


  int s = nodes.size();
  int i = 0;
  for ( i = s-1; i>= 0; i--)
  {
   if (i == 0)
   {
    cout << nodes[i];
   }
   else
   {
    cout << nodes[i]<< " ";
   }
  }
 }

 cout << endl;

 //cin.clear();
 //cin.ignore();
 //cin.get();

 return 0;
}