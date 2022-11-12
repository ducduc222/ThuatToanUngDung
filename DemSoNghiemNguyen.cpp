#include <bits/stdc++.h>
#define MAX 10000
int n, M;
int a[MAX];
int t[MAX];
int X[MAX];
int f;
int cott = 0;
using namespace std;

void TRY(int k)
{
    for (int v = 1; v <= (M - f) / a[k]; v++)
    {

        X[k] = v;
        f += a[k] * X[k];
        if (k == n)
        {
            if (f == M)
            {
                cott++;
            }
        }
        else
            TRY(k + 1);
        f -= a[k] * X[k];
    }
}

int main()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    TRY(1);
    cout << cott;
}