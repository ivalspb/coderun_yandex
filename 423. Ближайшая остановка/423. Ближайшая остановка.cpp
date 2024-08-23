#include <iostream>
#include <vector>
#include <map>

using namespace std;

int get_stop(map<int,pair<size_t,size_t>>& s, int req)
{
    auto s_ind = find(s.begin(), s.end(), req);
    if (s_ind != s.end())
        return s_ind->second.first;
    else
    {
        if ((*s.upper_bound(req)).second.first && (*s.lower_bound(req)).second.first)
        {

        }
    }
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
        if (!s[stops[i]].first)
            s[stops[i]] = { i,i };
        else
            s[stops[i]].second = i;
    }

    for (auto& i : reqs)
        cin >> i;

    std::cout << "Hello World!\n";
}

