
#include <iostream>
#include <map>
#include <set>
#include <vector>



using namespace std;

int main()
{
    size_t N, M;
    cin >> N >> M;
    map<size_t, set<size_t>>g;
    vector<size_t>v_color(N);
    for (size_t i = 0; i < M; i++)
    {
        size_t v1, v2;
        cin >> v1 >> v2;
        g[v1].insert(v2);
    }
    bool sortable = true;
    /*
    Изначально все вершины помечаются как белые, для каждой вершины осуществляется шаг алгоритма:

если вершина чёрная, ничего делать не надо,
если вершина серая — найден цикл, топологическая сортировка невозможна,
если вершина белая, то:
красится в серый,
применяется шаг алгоритма для всех вершин, в которые можно попасть из текущей,
красится вершину в чёрный и помещается её в начало окончательного списка.
    */
    for(size_t i=0;i<N;i++)

    std::cout << "Hello World!\n";
    return 0;
}

