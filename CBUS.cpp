#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int n, d;
int C[MAX][MAX];

int apear[MAX]; // check xem điểm v đã được đi chưa
int f;          // tổng quãng đường đã đi
int load;       // số người trên bus
int x[MAX];
int f_best = 10000;

void input()
{
    cin >> n >> d;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> C[i][j];
        }
    }
}

int check(int v)
{
    if (apear[v] == 1)
        return 0;
    if (v <= n)
    {
        if (load + 1 > d)
            return 0;
    }

    if (v > n)
    {
        if (!apear[v - n])
            return 0;
    }

    return 1;
}

void TRY(int k)
{
    int v;
    for (v = 1; v <= 2 * n; v++)
    {
        if (check(v))
        {
            x[k] = v;

            f += C[x[k - 1]][x[k]];

            if (v <= n)
                load = load + 1;
            else
                load = load - 1;

            apear[v] = 1;

            if (k == 2 * n)
            {

                f = f + C[x[k]][0];
                if (f < f_best)
                {
                    f_best = f;
                }
                f -= C[x[k]][0];
            }
            else
            {
                if (f < f_best)
                {
                    TRY(k + 1);
                }
            }
            if (v <= n)
                load = load - 1;
            else
                load = load + 1;

            f -= C[x[k - 1]][x[k]];
            apear[v] = 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    TRY(1);
    cout << "\n"
         << f_best << "\n";
    return 0;
}