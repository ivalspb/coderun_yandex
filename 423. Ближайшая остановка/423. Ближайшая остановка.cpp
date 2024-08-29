#include <iostream>
#include <vector>
#include <map>

using namespace std;

size_t get_stop(map<int,pair<size_t,size_t>>& s, int req)
{
    auto s_ind = s.find(req);
    
    if (s_ind != s.end())
        return s_ind->second.first;//минимальная среди остановок совпадающих с запросом
    
    auto s_upper = s.upper_bound(req);
    auto s_lower = s_upper;
    if (s_lower != s.begin())
        --s_lower;
    auto s_min = s_upper!=s.end()?(s_upper->first - req < s_lower->first - req ? s_upper : s_lower):s_lower;
    
    if ((s_min->second.first != s_min->second.second) or ((s_upper->first - req == s_lower->first - req)&&(s_upper!=s_lower)))//несколько остановок с одинаковым расстоянием
    {
        if (s_min != --s.end() && s_min!= s.begin())//остановки и слева и справа
            return (--s.lower_bound(req))->second.second;
        else if (s.lower_bound(req) == s.end())//остановки только слева
            return (--s.lower_bound(req))->second.second;
        else//остановки только справа
            return s.begin()->second.first;
    }
    else
        return s_min->second.first;
}

int main()
{
    size_t stop_count, req_count;
    cin >> stop_count >> req_count;
    vector<int>stops(stop_count),reqs(req_count);
    for (auto& i : stops)
        cin >> i;
    map<int, pair<size_t, size_t>>s;//coord,min_index,max_index
    for (size_t i = 1; i <= stop_count; i++)
    {
        if (!s[stops[i-1]].first)
            s[stops[i-1]] = { i,i };
        else
            s[stops[i-1]].second = i;
    }

    for (auto& i : reqs)
    {
        cin >> i;
        cout <</*"stop "<<i<<" "<<*/ get_stop(s, i) << endl;
    }


    //std::cout << "Hello World!\n";
}

