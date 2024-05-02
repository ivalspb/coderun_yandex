
#include <iostream>
#include <map>
#include <set>
#include <stack>

using namespace std;

//find one connectivity part of graph and mark it visited and push to stack and count++ it
void mark_connetivity(map<size_t, set<size_t>>& verteces, const size_t& vertex, map<size_t, bool>& visited, set<size_t>& connecitivty_set)
{
    if (!visited[vertex])
    {
        visited[vertex] = true;
        connecitivty_set.insert(vertex);
        for (const auto& i : verteces[vertex])
            mark_connetivity(verteces, i, visited, connecitivty_set);
    }
}

int main()
{
    size_t N_verteces, M_edges;
    cin >> N_verteces >> M_edges;
    map<size_t, set<size_t>>verteces;
    for (size_t i = 0; i < M_edges; i++)
    {
        size_t vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        verteces[vertex1].insert(vertex2);
        verteces[vertex2].insert(vertex1);
    }
    map<size_t, bool>v_visited;
    stack<set<size_t>> connecivity_stack;
    size_t connectivity_count = 0;
    for (size_t i = 1; i <= N_verteces; i++)
    {
        set<size_t> connectivity_set;
        mark_connetivity(verteces, i, v_visited, connectivity_set);
        if (!connectivity_set.empty())
        {
            connecivity_stack.push(connectivity_set);
            connectivity_count++;
        }
    }

    cout << connectivity_count;
    while (!connecivity_stack.empty())
    {
        set<size_t> connectivity_set=connecivity_stack.top();
        connecivity_stack.pop();
        cout << "\n"<<connectivity_set.size() << endl;
        for (const auto& i : connectivity_set)
            cout << i << " ";
    }
}
