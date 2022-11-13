// có m kẹo và n em bé. viết các cách chia để em nào cũng có kẹo
// đưa về bài toán tìm nghiệm nguyên dương của x1+x2 +...+ xn=m

#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int m, n;
int x[MAX]; // ứng viên :số kẹo của mỗi em bé
int f;      // tổng số kẹo đã được chia

void input()
{
    cin >> m >> n;
}

void TRY(int k)
{

    for (int v = 1; v <= (m - f); v++)
    {
        x[k] = v;
        f += x[k];
        if (k == n)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << x[i] << " ";
            }
            cout << "\n";
        }
        else
            TRY(k + 1);
        f -= x[k];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);
    input();
    cout<< "\n";
    TRY(1);
}