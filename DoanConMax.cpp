#include <bits/stdc++.h>
using namespace std;
int A[100000000];
int n;
void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }
}
int MaxLeftMid(int i, int j)
{
    int maxLM = A[j];
    int s = 0;
    for (int k = j; k >= i; k--)
    {
        s += A[k];
        maxLM = max(maxLM, s);
    }
    return maxLM;
}
int MaxRightMid(int i, int j)
{
    int maxRM = A[i];
    int s = 0;
    for (int k = i; k <= j; k++)
    {
        s += A[k];
        maxRM = max(maxRM, s);
    }
    return maxRM;
}
int SubSeqMax(int i, int j)
{
    if (i == j)
        return A[i];
    int mid = (i + j) / 2;
    int wL = SubSeqMax(i, mid);
    int wR = SubSeqMax(mid + 1, j);
    int maxLM = MaxLeftMid(i, mid);
    int maxRM = MaxRightMid(mid + 1, j);
    int wM = maxLM + maxRM;
    return max(max(wL, wR), wM);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    int r = SubSeqMax(1, n);
    cout << r;
}