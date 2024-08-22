
#include <iostream>

using namespace std;

int main()
{
    size_t A, B, N, A_max, B_min;
    cin >> A >> B >> N;
    A_max = A;
    B_min = B / N;
    if (B % N) 
        B_min++;
    if (A_max > B_min) cout << "Yes";
    else cout << "No";
}

