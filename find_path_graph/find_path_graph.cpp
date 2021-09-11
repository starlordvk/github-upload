#include <bits/stdc++.h>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
public: 

    Graph(int ver)
    {
        v = ver;
        adj = new list<int>[v];
    }

    void addEdge(int s, int t)
    {
        adj[s].push_back(t);
    }

    bool isReachable(int s, int t)
    {
        return BFS(s, t);
    }

    bool BFS(int s, int t)
    {
        bool *visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }

        queue<int> q;
        q.push(s);

        while(!q.empty())
        {   
            int x = q.front();
            visited[s] = true;
            for (auto i : adj[x])
            {   
                if (i == t) return true;
                if (!visited[i])
                {
                    q.push(i);
                }
            }
            q.pop();

        }

        return false;
    }
};

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    int u = 1, v = 3;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    u = 3, v = 1;
    if(g.isReachable(u, v))
        cout<< "\n There is a path from " << u << " to " << v;
    else
        cout<< "\n There is no path from " << u << " to " << v;
 
    return 0;
}