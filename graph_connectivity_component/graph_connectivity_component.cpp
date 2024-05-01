/*
Дан неориентированный граф, возможно, с петлями и кратными ребрами. Необходимо построить компоненту связности, содержащую вершину с номером 1.
Напомним:
Петля в графе - это ребро, которое соединяет вершину с самой собой.
Кратные рёбра в графе - это ребра, которые соединяют одну и ту же пару вершин.
Компонента связности в неориентированном графе - это подмножество вершин, таких что все вершины достижимы друг из друга.
Формат ввода
В первой строке записаны два целых числа N (1≤N≤10^3 ) и 𝑀(0≤M≤5∗10^5) — количество вершин и ребер в графе. 
В последующих M строках перечислены ребра — пары чисел, определяющие номера вершин, которые соединяют ребра. Далее может идти произвольное количество пустых строк.
Формат вывода
В первую строку выходного файла выведите число K — количество вершин в компоненте связности. 
Во вторую строку выведите K целых чисел — вершины компоненты связности, перечисленные в порядке возрастания номеров.
*/
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

void find_connectivity(map<const size_t, set<size_t>>& v, const size_t& v1, map<size_t,bool>& v_c)
{
        v_c[v1]=true;
        for (auto& i : v[v1])
        {
            if(!v_c[i])
            {
                v_c[i]=true;
                find_connectivity(v, i, v_c);
            }
        }
}

int main()
{
    
    size_t N, M;
    cin >> N >> M;
    map<const size_t, set<size_t>>vertexes;
    for (size_t i = 0; i < M; i++)
    {
        size_t vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        vertexes[vertex1].insert(vertex2);
        vertexes[vertex2].insert(vertex1);
    }
    map<size_t,bool>v_connectivity;
    find_connectivity(vertexes, 1,v_connectivity);

    cout << v_connectivity.size()<<endl;
    for(const auto& i:v_connectivity)
        cout <<i.first <<" ";
}
