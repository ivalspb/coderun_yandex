
#include <iostream>
#include <map>
#include <set>
#include <vector>



using namespace std;

void step(map<size_t, set<size_t> >& g, vector<size_t>& v_color, size_t v, bool& sortable, vector<size_t>& result)
{
	if (sortable)
    {
        if (v_color[v-1] != 1)
        {
            if (v_color[v-1] == 2)
            {
                sortable = false;
                return;
            }
            else
            {
				v_color[v-1] = 2;
                for (const auto& i : g[v])
                    step(g, v_color, i, sortable, result);
				v_color[v-1] = 1;
                result.push_back(v);
            }
        }
    }
}

int main()
{
    size_t N, M;
    cin >> N >> M;
    map<size_t, set<size_t>>g;
    for (size_t i = 1; i <= N; i++)
        g[i];
    vector<size_t>v_color(N);
    for (size_t i = 0; i < M; i++)
    {
        size_t v1, v2;
        cin >> v1 >> v2;
        g[v1].insert(v2);
    }
    bool sortable = true;
	vector<size_t>result;
    /*
    * 
    * 0 = white
	* 1 = black
    * 2 = grey
    * 
    Изначально все вершины помечаются как белые, для каждой вершины осуществляется шаг алгоритма:

если вершина чёрная, ничего делать не надо,
если вершина серая — найден цикл, топологическая сортировка невозможна,
если вершина белая, то:
красится в серый,
применяется шаг алгоритма для всех вершин, в которые можно попасть из текущей,
красится вершину в чёрный и помещается её в начало окончательного списка.
    */
    for (size_t i = 1; i <= N; i++)
        step(g, v_color, i, sortable, result);
    if (sortable)
        for (const auto& i : result)
            cout << i << " ";
    else
        cout << "-1";
    
    return 0;
}

