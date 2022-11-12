#include <iostream>

using namespace std;

int main()
{
    unsigned long long a, a0, a1, b, b0, b1, sum1, sum0;
    cin >> a >> b;

    a0 = a % 10;
    b0 = b % 10;

    a1 = a / 10;
    b1 = b / 10;

    sum0 = (a0 + b0) % 10;
    sum1 = a1 + b1 + (a0 + b0) / 10;

    if (sum1 > 0)
    {
        cout << sum1;
    }
    cout << sum0;
}