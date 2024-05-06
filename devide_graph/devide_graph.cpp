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

using namespace std;

//void divide

int main()
{
    size_t N, M;
    cin >> N >> M;
    set<size_t>gr1,gr2;
    bool res = true;
    for (size_t i = 0; i < M; i++)
    {
        size_t st1, st2;
        cin >> st1 >> st2;
        //or 1st_group, or 2nd_group, or new
        if (gr1.find(st1)!=gr1.end())
        {
            if (gr1.find(st2) != gr1.end())
            {
                res = false;
                break;
            }
            else if (gr2.find(st2) == gr2.end())
                gr2.insert(st2);
        }
        else if (gr1.find(st2) != gr1.end())
        {
            if (gr1.find(st1) != gr1.end())
            {
                res = false;
                break;
            }
            else if (gr2.find(st1) == gr2.end())
                gr2.insert(st1);
        }
        else if (gr2.find(st1) != gr2.end())
        {
            if (gr2.find(st1) != gr2.end())
            {
                res = false;
                break;
            }
            else if (gr1.find(st2) == gr1.end())
                gr1.insert(st2);
        }
        else if (gr2.find(st2) != gr2.end())
        {
            if (gr2.find(st1) != gr2.end())
            {
                res = false;
                break;
            }
            else if (gr1.find(st1) == gr1.end())
                gr1.insert(st1);
        }
        else
        {
            gr1.insert(st1);
            gr2.insert(st2);
        }

        /*graph[st1].insert(st2);
        graph[st2].insert(st1);*/
    }

    //map<size_t, bool>visited;
    //set<size_t>source, destination;

    if (res) cout << "YES";
    else cout << "NO";
}
