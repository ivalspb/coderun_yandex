//Даны две последовательности, требуется найти и вывести их наибольшую общую подпоследовательность.
//

#include <iostream>
#include <vector>
#include <map>

int main()
{
    size_t N, M;
    std::cin >> N;
    std::map<int, size_t>n_set;//<value,index>
    std::map<size_t,int> m_set;//<<index,value>
    for (size_t i = 1; i <= N; i++)
    {
        int el;
        std::cin >> el;
        n_set[el] = i;
    }
    std::cin >> M;
    std::pair<size_t, size_t> max_lenght = { 0,0 };
    //<номер первого общего элемента в первом множестве, количество общих элементов>
    for (size_t j = 1; j <= M; j++)
    {
        int el;
        std::cin >> el;
        m_set[j] = el;
        auto i = n_set.find(el);
        if (i != n_set.end())
        {
            if (!max_lenght.second)
            {
                max_lenght.first = i->second;
                max_lenght.second = 1;
            }
            else if (i->second - max_lenght.second == max_lenght.first)
            {
                max_lenght.second++;
            }
            else
            {
                max_lenght.first = i->second;
                max_lenght.second = 1;
            }
        }
        else
            max_lenght = { 0,0 };
    }
    std::cout << "Hello World!\n";
}

