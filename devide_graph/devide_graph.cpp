/*
У профессора записаны все пары студентов, обменявшихся записками. Требуется определить, сможет ли он разделить студентов на две группы так, 
чтобы любой обмен записками осуществлялся от студента одной группы студенту другой группы.

Формат ввода
В первой строке находятся два числа N и M — количество студентов и количество пар студентов, обменивающихся записками (1≤𝑁≤10^2,0≤𝑀≤𝑁(𝑁−1)/2
Далее в M строках расположены описания пар студентов: два числа, соответствующие номерам студентов, обменивающихся записками (нумерация студентов идёт с 1). 
Каждая пара студентов перечислена не более одного раза.

Формат вывода
Необходимо вывести ответ на задачу профессора Флойда. Если возможно разделить студентов на две группы - выведите YES; иначе выведите NO.
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void dfs(map<size_t, set<size_t>>& g, vector<size_t>& v_color, size_t v, size_t color, bool& res)
{
    if (!res) return;
    else
    {
        if(!v_color[v - 1]) v_color[v - 1] = color;
        for (const auto& i : g[v])
        {
            if (!v_color[i-1])
                dfs(g, v_color, i, 3 - color, res);
            else
                if (v_color[i-1] == v_color[v-1]) 
                    res = 0;
        }
    }
}

int main()
{
    size_t N, M;
    cin >> N >> M;
    map<size_t, set<size_t>>g;
    for (size_t i = 0; i < M; i++)
    {
        size_t s1, s2;
        cin >> s1 >> s2;
        g[s1].insert(s2);
        g[s2].insert(s1);
    }
    vector<size_t>v_color(N);//0 not visited, 1 or 2 visited
    bool res = true;
    for (size_t i = 1; i <= N; i++)
        dfs(g, v_color, i, 1, res);
    if (res) cout << "YES";
    else cout << "NO";
}
