#include <bits/stdc++.h>
using namespace std;

//Graph (BFS)
typedef vector<int> vi;

void BFS(int src, const vector<vi> &edges) 
{
    int N = edges.size();
    vector<int> visited(N, -1);
    visited[src] = 0;

    queue<int> q; // VIDE
    q.push(src); // 0

    while(!q.empty())
    {
        int node = q.front();   q.pop();
        int cost = visited[node];
        cout << node+1 << " is visited!\n"; // AFFICHAGE DE SOMMET visité
        for(int child: edges[node]) if(visited[child] == -1)
        {
            q.push(child);
            visited[child] = cost+1;
        }
    }
}

#define endl '\n'	//Faster printing

int main()
{
		
   		freopen("input.txt", "r", stdin);
   		
        int n, m;  cin >> n;
        vector<vi> edges(n);
        cin >> m;
        int u, v;
        for(int i = 0; i < m; i++)
        {
             cin >> u >> v;
             v--;
             u--;
			       edges[u].push_back(v);
             edges[v].push_back(u);
        }

        BFS(0, edges);

    return 0;
}
