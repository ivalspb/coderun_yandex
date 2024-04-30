//Даны две последовательности, требуется найти и вывести их наибольшую общую подпоследовательность.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    size_t N, M;
    std::cin >> N;
    std::vector<int>n_set(N);//<value,index>
    
    for (size_t i = 0; i < N; i++)
        std::cin >> n_set[i];
    std::cin >> M;
    std::vector<int>m_set(M);
    std::pair<size_t, size_t> max_lenght = { 0,0 };
    //<номер первого общего элемента в первом множестве, количество общих элементов>
    std::pair<size_t, size_t> cur_max_lenght = { 0,0 };

    for (size_t j = 0; j < M; j++)
    {
        std::cin >> m_set[j];
        auto i = std::find(n_set.begin()+cur_max_lenght.first+ cur_max_lenght.second,n_set.end(), m_set[j]);//нужно учесть повторы!
        if (i == n_set.end()&&(cur_max_lenght.first + cur_max_lenght.second))
        {
            i= std::find(n_set.begin() + cur_max_lenght.first + cur_max_lenght.second-1, n_set.end(), m_set[j]);
        }
        if (i != n_set.end())
        {
            if (!cur_max_lenght.second)//first el unity
            {
                cur_max_lenght.first = std::distance(n_set.begin(),i);
                cur_max_lenght.second = 1;
            }
            else if(std::distance(n_set.begin(),i)-cur_max_lenght.second== cur_max_lenght.first)
            {
                cur_max_lenght.second++;
            }
            else if (cur_max_lenght.first<N && n_set[cur_max_lenght.first]== n_set[cur_max_lenght.first+1])
            {
                cur_max_lenght.first++;
                cur_max_lenght.second++;
            }
            else
            {
                cur_max_lenght.first = std::distance(n_set.begin(),i);
                cur_max_lenght.second = 1;
            }
        }
        else
            cur_max_lenght = { 0,0 };
        if (cur_max_lenght.second > max_lenght.second)
            max_lenght = cur_max_lenght;
    }
    for(size_t i=0;i<max_lenght.second;i++)
        std::cout << n_set[max_lenght.first+i] <<" ";
}

