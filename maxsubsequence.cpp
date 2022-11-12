#include <bits/stdc++.h>

using namespace std;

int main()
{
    /*
    int n;
    int A[1000000];
    long long max;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >>A[i];
    }

    max = A[0];

    for (int i = 0; i < n; i++)
    {
        int m = 0;
        for (int j = i; j < n; j++)
        {
            m = m+A[j];
            if (m > max)
            {
                max = m;
            }

        }

    }
    cout << max;
    */

    int n;
    int A[1000000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int max = A[0];
    int F = A[0];
    for (int i = 1; i < n; i++)
    {
        F = F + A[i];
        if (F < A[i])
        {
            F = A[i];
        }

        if (F > max)
        {
            max = F;
        }
    }

    cout << max;
}