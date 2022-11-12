// Tìm đường ngắn nhất thoát ra khỏi mê cung
// Mê cung n x n được biểu diễn bới 0 và 1 : 0 là đường đi, 1 là tường
// Input:
// 4 số n m r c: n m là số hàng số cột
//               r c: chỉ số hàng cột xuất phát
//  ma trận n x m
// Output: số bước cần di chuyển để thoát ra khỏi mê cung

#include <iostream>
#include <queue>
using namespace std;

int n, m, r, c;
int A[1000][1000];
int d[1000][1000];

queue<pair<int, int>> stepMaze;

int result();

int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> A[i][j];
        }
    }

    if (1 <= n && n <= 999 && 1 <= m && m <= 999)
    {
        if (1 <= r && r <= n && 1 <= m && m <= m)
        {
            cout << "\n\n"
                 << result() << "\n";
        }
        else
            cout << -1;
    }
}

int result()
{
    if (A[r][c] == 0)
    {
        pair<int, int> start_point(r, c);
        stepMaze.push(start_point);
        d[r][c] = 0;
    }

    while (!stepMaze.empty())
    {
        pair<int, int> u;
        u = stepMaze.front();
        stepMaze.pop();

        int x, y;
        // trái
        x = u.first;
        y = u.second - 1;

        if (y == 0)
            return d[u.first][u.second] + 1;
        if (A[x][y] == 0)
        {
            d[x][y] = d[u.first][u.second] + 1;
            stepMaze.push(pair<int, int>(x, y));
            A[x][y] = 1;
        }
        // trên
        x = u.first - 1;
        y = u.second;

        if (x == 0)
            return d[u.first][u.second] + 1;
        if (A[x][y] == 0)
        {
            d[x][y] = d[u.first][u.second] + 1;
            stepMaze.push(pair<int, int>(x, y));
            A[x][y] = 1;
        }
        // phải
        x = u.first;
        y = u.second + 1;

        if (y == m + 1)
            return d[u.first][u.second] + 1;
        if (A[x][y] == 0)
        {
            d[x][y] = d[u.first][u.second] + 1;
            stepMaze.push(pair<int, int>(x, y));
            A[x][y] = 1;
        }

        // duới
        x = u.first + 1;
        y = u.second;

        if (x == n + 1)
            return d[u.first][u.second] + 1;
        if (A[x][y] == 0)
        {
            d[x][y] = d[u.first][u.second] + 1;
            stepMaze.push(pair<int, int>(x, y));
            A[x][y] = 1;
        }
    }

    return -1;
}
