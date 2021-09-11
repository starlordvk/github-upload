#include <bits/stdc++.h>

using namespace std;

class Graph
{
    map<int, bool> visited;
    map<int, list<int>> adj;
public: 
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void BFS(int v)
    {
        queue<int> q;
        q.push(v);

        while(!q.empty())
        {
            int x = q.front();
            cout<<x<<" ";
            visited[x] = true;
            for (auto i : adj[x])
            {
                if (!visited[i])
                {
                    q.push(i);
                }
            }
            q.pop();

        }
    }
};

int main ()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;

}