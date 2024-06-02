/*
К сожалению, после чемпионата потерялись записи с фамилиями участников, остались только записи о длине броска в том порядке, в котором их совершали участники.
Тракторист Василий помнит три факта:
1) Число метров, на которое он метнул лепешку, оканчивалось на 5
2) Один из победителей чемпионата метал лепешку до Василия
3) Участник, метавший лепешку сразу после Василия, метнул ее на меньшее количество метров
Будем считать, что участник соревнования занял k-е место, если ровно (k − 1) участников чемпионата метнули лепешку строго дальше, чем он.
Какое максимально высокое место мог занять Василий?
*/

#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;



int main()
{
    size_t N;
    cin >> N;
    vector<size_t>meters(N);
    multiset<size_t>rating,ending5;
    for (int i = 0; i < N; i++) 
    {
        cin >> meters[i];
        rating.insert(meters[i]);
        if ((meters[i] - 5) % 10 == 0)
            ending5.insert(meters[i]);
    }
    map<size_t, size_t>ind_rating;//метры, место
    size_t j = 1;
    for (auto i = rating.rbegin(); i != rating.rend(); ++i)
    {
        if(!ind_rating[*i])
            ind_rating[*i] = j;
        j++;
    }
    set<size_t>winners_indexes;
    for (int i = 0; i < N; i++)
        if (meters[i] == *(rating.rbegin()))
            winners_indexes.insert(i);
    set<size_t>candidats_index;
    for (size_t i = *winners_indexes.begin()+1;i<N-1;i++)
        if(meters[i] % 10 == 5)
            if(meters[i]>meters[i+1])
                candidats_index.insert(ind_rating[meters[i]]);
    if(!candidats_index.empty())
    {
        cout << *candidats_index.begin();
        return 0;
    }
    
    cout << "0";
    return 0;
}
