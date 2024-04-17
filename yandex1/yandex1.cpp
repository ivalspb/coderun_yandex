
#include <iostream>
#include <string>

bool nik_approved(const std::string& s)
{
    if (s.empty())
        return false;
    else
    {
        bool len_8 = s.length() > 7, dig = false, small_let = false, cap_letter = false;
        for (auto i : s)
            if (i >= '0' && i <= '9')
            {
                dig = true;
                break;
            }
        for (auto i : s)
            if (i >= 'a' && i <= 'z')
            {
                small_let = true;
                break;
            }
        for (auto i : s)
            if (i >= 'A' && i <= 'Z')
            {
                cap_letter = true;
                break;
            }
        return len_8 && small_let && cap_letter;
    }
}

int main()
{
    std::string s;
    std::cin >> s;
    if(nik_approved(s))
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}
