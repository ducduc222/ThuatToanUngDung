#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
vector<std::vector<string>> call;
map<string, int> nCallfromNumber, tCallfromNumber;

int check_phone_number();
int number_calls_from(string phoneNum);
int number_total_calls();
int count_time_calls_from(string phoneNum);

int timegiay(string stringTime);

int main()
{
    string s;
    fflush(stdin);
    cin >> s;
    while (s == "call")
    {

        vector<string> tCall;
        cin >> s;
        tCall.push_back(s);
        string fCall = s;
        nCallfromNumber[fCall]++;

        cin >> s;
        tCall.push_back(s);

        cin >> s;
        tCall.push_back(s);

        cin >> s;
        tCall.push_back(s);
        int fTime = timegiay(s);

        cin >> s;
        tCall.push_back(s);
        int eTime = timegiay(s);

        int sTime = eTime - fTime;
        tCallfromNumber[fCall] += sTime;

        call.push_back(tCall);
        cin >> s;
    }
    vector<int> result;
    while (1)
    {
        cin >> s;
        if (s == "?check_phone_number")
        {
            result.push_back(check_phone_number());
        }
        if (s == "?number_calls_from")
        {
            string phoneNum;
            cin >> phoneNum;
            result.push_back(number_calls_from(phoneNum));
        }
        if (s == "?number_total_calls")
        {
            result.push_back(number_total_calls());
        }

        if (s == "?count_time_calls_from")
        {
            string phoneNum;
            cin >> phoneNum;
            result.push_back(count_time_calls_from(phoneNum));
        }
        if (s == "#")
            break;
    }
    for (auto x : result)
    {
        cout << x << "\n";
    }
}

int check_phone_number()
{
    int check_phone_number;
    for (int i = 0; i < call.size(); i++)
    {
        if (call[i][0].size() == 10 && call[i][1].size() == 10)
        {
            for (int j = 0; j < 10; j++)
            {
                if (call[i][0][j] < '0' || call[i][0][j] > '9' || call[i][1][j] < '0' || call[i][1][j] > '9')
                {
                    return 0;
                }
            }
        }
        check_phone_number = 1;
    }
    return check_phone_number;
};

int number_calls_from(string phoneNum)
{
    return nCallfromNumber[phoneNum];
};

int number_total_calls()
{
    return call.size();
};

int count_time_calls_from(string phoneNum)
{
    return tCallfromNumber[phoneNum];
};

int timegiay(string stringTime)
{
    int h;
    int p;
    int s;
    string num;
    num = stringTime.substr(0, 2);
    h = stoi(num) * 3600;
    num = stringTime.substr(3, 2);
    p = stoi(num) * 60;
    num = stringTime.substr(6, 2);
    s = stoi(num);

    return h + p + s;
}