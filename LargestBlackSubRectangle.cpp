#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define MAX 10001
using namespace std;
int m, n;
int A[MAX][MAX];
int h[MAX] = {0};
int L[MAX];
int R[MAX];


void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
        }
    }
}

int tinhS()
{
    for (int i = 1; i <= m; i++)
    {
        for (int k = i; k <= m; k++)
        {
            if (k == m)
            {
                R[i] = m+1;
                break;
            }
            if (h[k + 1] < h[i])
            {
                R[i] = k + 1;
                break;
            }
        }

        for (int s = i; s >= 1; s--)
        {
            if (s == 1)
            {
                L[i] = 0;
                break;
            }
            if (h[s - 1] < h[i])
            {
                L[i] = s - 1;
                break;
            }
        }
    }

    int maxS = 0;
    for (int i = 1; i <= m; i++)
    {
        int t0 = (R[i] - L[i] - 1) * h[i];
        if (maxS < t0)
            maxS = t0;
    }

    return maxS;
}


int result() {
    int max = 0;
    for (int i = 1; i <= n; i++)
    {
        
        for (int j = 1; j <= m; j++)
        {
            if (A[i][j] == 0) h[j] = 0;
            else h[j] = h[j]+1;

            // cout << h[j] << "\t";
        }
        int  t = tinhS();
        if (t > max) max = t;
        // cout << "\n";
    }
    return max;
    
}


int main() {
    input();
    int t = result();
    cout << t;
}