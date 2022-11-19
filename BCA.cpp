#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int m;           // số teachers
int n;           // số môn học
int T[MAX];      // số khóa học mà giáo viên i có thể dạy
int C[MAX][MAX]; // danh sách khóa học mà giáo viên i dạy
int l[MAX];      // số môn học đang được phân công cho giáo viên i
int k;           // số cặp môn không thể dạy cùng 1 cô
int D[MAX][MAX]; // các cặp môn trùng nhau
int s = 0;       // số môn đã được phân công
int l_min = MAX; // lưu giá trị load nhỏ nhất
int Z[MAX][MAX]; // lưu các môn học mà giáo viên Z[i] đang được phân công
int check_first = 0;
void input()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> T[i];
        int z;
        for (int j = 1; j <= T[i]; j++)
        {
            cin >> z;
            C[i][z] = 1;
        }
    }

    cin >> k;
    int u, v;
    for (int i = 1; i <= k; i++)
    {
        cin >> u >> v;
        D[u][v] = 1;
        D[v][u] = 1;
    }
}

int check(int k, int c)
{
    if (s + 1 > n)
        return 0;

    if (l[k] + 1 > T[k])
        return 0; // nếu số môn học được giao > số môn có thể dạy => 0
    if (Z[k][c] == 1)
        return 0; // nếu môn c đã được giao => 0
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        
        if (Z[k][i] == 1)
        {
            count++;
            if (D[i][c] == 1 || D[c][i] == 1)
                return 0;
        }
        if (count+1 > l[k]) {
            return 1;
        }
    }

    return 1;
}

int solution()
{
    int max = 0;
    for (int i = 1; i <= m; i++)
    {
        if (l[i] > max)
            max = l[i];
    }

    return max;
}

void TRY(int k)
{
    for (int i = 1; i <= m; i++)
    {
        if (check(i, k) == 1)
        {
            l[i] += 1;
            Z[i][k] = 1;
            s += 1;
            // cout << s << " ";
            if (k == n)
            {
                // for (int j = 1; j <= m; j++)
                // {
                //     cout << l[j] << " ";
                // }

                // cout << "  {l: " << l_min << "}"
                //      << "{s: " << solution() << "}\n";
                if (l_min > solution())
                    l_min = solution();
                check_first = 1;
            }
            else
            {
                // cout << l[i] << " ";
                if (!check_first)
                    TRY(k + 1);
                else
                {
                    if (l_min > l[i])
                        TRY(k + 1);
                }
            }
            s -= 1;
            l[i] -= 1;
            Z[i][k] = 0;
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
         << l_min << "\n";
}