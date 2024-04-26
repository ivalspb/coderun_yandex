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
    //<номер первого общего элемента во втором множестве, количество общих элементов>
    std::pair<size_t, size_t> cur_max_lenght = { 0,0 };

    for (size_t j = 1; j <= M; j++)
    {
        int el;

        std::cin >> el;
        m_set[j] = el;
        auto i = n_set.find(el);
        if (i != n_set.end())
        {
            if (!cur_max_lenght.second)//first el unity
            {
                cur_max_lenght.first = j;
                cur_max_lenght.second = 1;
            }
            else if (n_set[m_set[j]] - cur_max_lenght.second == n_set [m_set[cur_max_lenght.first]] )
            {
                cur_max_lenght.second++;
            }
            else
            {
                cur_max_lenght.first = j;
                cur_max_lenght.second = 1;
            }
        }
        else
            cur_max_lenght = { 0,0 };
        if (cur_max_lenght.second > max_lenght.second)
            max_lenght = cur_max_lenght;
    }
    for(size_t i=0;i<max_lenght.second;i++)
        std::cout << m_set[max_lenght.first+i] <<" ";
}

