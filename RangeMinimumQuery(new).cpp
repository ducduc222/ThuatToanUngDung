#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int A[1000];
int M[1000][1000];
int Q;

void process2(int M[1000][1000], int A[1000], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
        M[i][0] = A[i];

    for (j = 1; 1 << j <= N; j++)
        for (i = 0; i + (1 << j) - 1 < N; i++)
            if (M[i][j - 1] < M[i + (1 << (j - 1))][j - 1])
                M[i][j] = M[i][j - 1];
            else
                M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

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
    process2(M, A, n);

    long long result = 0;
    int i, j, k;
    cin >> m;
    for (int t = 1; t <= m; t++)
    {
        cin >> i >> j;
        k = log2(j - i + 1);
        result += min(M[i][k], M[j - (1 << k) + 1][k]);
    }
}