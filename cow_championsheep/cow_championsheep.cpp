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
    set<size_t>winners_index;
    for (int i = 0; i < N; i++)
        if (meters[i] == *(rating.rbegin()))
            winners_index.insert(i);
    for(size_t i:winners_index)
        if(i>0&&i<N-1&&)
    /*for(int i=0;i<N;i++)
        if(meters[i]==)*/
    /*for (auto i = ending5.rbegin(); i != ending5.rend(); ++i)
    {
        for (int j = 0; j < N; j++)
        {
            if (meters[j] == *i && j > 0 &&j<N-1 && ind_rating[meters[j - 1]] < 2 && meters[j+1]<meters[j])
            {
                cout << ind_rating[*i];
                return 0;
            }
        }
        
    }*/
    cout << "0";
    return 0;
}
