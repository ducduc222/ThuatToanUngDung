#include <iostream>
#define MAX 1000000
using namespace std;

int n;
int m;
int A[MAX];
int Q;
int rmq(int x, int y);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        Q += rmq(x, y);
    }

    cout << Q;
}

int rmq(int x, int y)
{
    int min = A[x];
    for (int i = x; i < y + 1; i++)
    {
        if (A[i] < min)
            min = A[i];
    }

    return min;
}