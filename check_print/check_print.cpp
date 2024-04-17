
#include <iostream>
#include <string>
//#include <stack>

int main()
{
    std::string a, b,c;
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    auto res_it = c.begin();

    for (auto i = b.begin(); i != b.end(); i++)
    {
        if (*i == '<')
        {
            std::string s;
            auto j = i+1;
            while (*j != '>'&&j!=b.end())
            {
                s += *j;
                j++;
            }
            if (s == "delete")
            {
                if (res_it != c.end()) res_it = c.erase(res_it);
                i = b.erase(i, i + 8);
                i--;
            }
            else if (s == "bspace")
            {
                if(res_it!=c.begin()) res_it= c.erase(res_it-1);
                i = b.erase(i, i + 8);
                i--;
            }
            else if (s == "left")
            {
                i = b.erase(i, i + 6);
                if(res_it!=c.begin()) res_it--;
                i--;
            }
            else if (s == "right")
            {
                i = b.erase(i, i + 7);
                if (res_it != c.end()) res_it++;
                i--;
            }
            else
            {
                b += '<' + s;
                c += '<' + s;
                i = j;
            }

        }
        else
        {
            if (res_it == c.end())
            {
                c += *i;
                res_it++;
            }
            else
            {
                res_it = c.insert(res_it, *i);
                res_it++;
            }
            
        }
    }

    if(c==a)
        std::cout << "Yes";
    else
        std::cout << "No";
 }

