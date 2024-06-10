/*
Дан неориентированный граф. Требуется определить, есть ли в нем цикл, и, если есть, вывести его.
Формат ввода
В первой строке дано одно число n — количество вершин в графе (1≤n≤ 500 ). Далее в n строках задан сам граф матрицей смежности.
Формат вывода
Если в иcходном графе нет цикла, то выведите «NO».
Иначе, в первой строке выведите «YES», во второй строке выведите число k — количество вершин в цикле, 
а в третьей строке выведите k различных чисел — номера вершин, которые принадлежат циклу в порядке обхода (обход можно начинать с любой вершины цикла).
Если циклов несколько, то выведите любой.
*/
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

void dfs(map<size_t, set<size_t>>& g, vector<size_t>& v_color, stack<size_t>&res, size_t v, bool& cicle)
/*
    *
    * 0 = white
    * 1 = black
    * 2 = grey
    *
    Изначально все вершины помечаются как белые, для каждой вершины осуществляется шаг алгоритма:

если вершина чёрная, ничего делать не надо,
если вершина серая — найден цикл, 
если вершина белая, то:
красится в серый,
применяется шаг алгоритма для всех вершин, в которые можно попасть из текущей,
красится вершину в чёрный и помещается её в начало окончательного списка.
    */
{
    if (!cicle)
    {
        if(v_color[v-1]!=1)
        {
            if (v_color[v - 1] == 2)
            {
                cicle = true;
                return;
            }
            else
            {
                v_color[v - 1] = 2;
                for (const auto& i : g[v])
                    dfs(g, v_color, res, i, cicle);
                v_color[v - 1] = 1;
                res.push(v);
            }
        }

    }
}

int main()
{
    size_t n;
    cin >> n;
    vector<vector<size_t>>smg(n, vector<size_t>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> smg[i][j];
    map<size_t, set<size_t>>g;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n / (n-i); j++)
            if (smg[i][j])
            {
                g[i+1].insert(j+1);
                //g[j+1].insert(i+1);
            }
    vector<size_t>v_color(n);
    bool cicle = false;
    stack<size_t>res;
    for (int i = 1; i <= n; i++)
        if(!cicle)
            dfs(g, v_color, res, i, cicle);
    if (cicle)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}

