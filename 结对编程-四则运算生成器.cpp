#include <iostream>
#include <ctime>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#define random(l, h) (rand() % (h - l + 1) + l)
using namespace std;

int flag = 1;
fstream outfile;
int getRandomInt(int down, int up)
{
    int RadowmLow = down, RadowmHigh = up;
    if (flag)
    {
        flag = 0;
        srand((unsigned)time(NULL));
    }
    int result = random(down, up);
    return result;
}
int max(int a, int b)
{
    int max = a >= b ? a : b;
    return max;
}

int min(int a, int b)
{
    int min = a <= b ? a : b;
    return min;
}
string fraction(int d, int u)
{
    int temp1 = getRandomInt(d, u);
    int temp2 = getRandomInt(d, u);
    int RadowmHigh = min(temp1, temp2);
    int RadowmLow = max(temp1, temp2);
    stringstream tra, stream1;
    string up, down;
    tra << RadowmHigh;
    tra >> up;
    stream1 << RadowmLow;
    stream1 >> down;
    string fra;
    RadowmHigh != RadowmLow ? fra = up + "\\" + down : fra = "1";
    return fra;
}
bool is_unique(string str, vector<string> s)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (str != s[i])
        {
            count++;
        }
        else
            break;
    }
    bool flag0 = count == s.size() ? true : false;
    return flag0;
}
void operation(int time, int RadowmLow, int RadowmHigh, int flags1, int flags2, int flags3, int flags4, int flags5, int wc)
{
    int integer1, integer2;
    int ch1, ch2, ch3, ch4;
    char sign;
    int times = time;
    vector<string> str;
    for (int i = 1; i <= times;)
    {
        int flag4 = 1;
        string first, second, Terminal;
        int number = getRandomInt(1, 9);
        for (int j = 1; j <= number;)
        {

            if (flags1 == 1)
            {
                ch1 = getRandomInt(1, 4);
                switch (ch1)
                {
                case 1:
                    sign = '+';
                    break;
                case 2:
                    sign = '-';
                    break;
                case 3:
                    sign = '*';
                    break;
                case 4:
                    sign = '/';
                    break;
                }
            }
            else
            {
                ch1 = getRandomInt(1, 2);
                switch (ch1)
                {
                case 1:
                    sign = '+';
                    break;
                case 2:
                    sign = '-';
                    break;
                }
            }
            if (flags4 == 1)
            {
                ch2 = getRandomInt(1, 3);
                switch (ch2)
                {
                case 1:
                {
                    stringstream stream1, stream2;
                    integer1 = getRandomInt(RadowmLow, RadowmHigh);
                    stream1 << integer1;
                    stream1 >> first;
                    integer2 = getRandomInt(RadowmLow, RadowmHigh);
                    stream2 << integer2;
                    stream2 >> second;
                }
                break;
                case 2:
                {
                    stringstream kk;
                    integer1 = getRandomInt(RadowmLow, RadowmHigh);
                    kk << integer1;
                    kk >> first;
                    second = fraction(RadowmLow, RadowmHigh);
                }
                break;
                case 3:
                {
                    first = fraction(RadowmLow, RadowmHigh);
                    second = fraction(RadowmLow, RadowmHigh);
                }
                break;
                }
            }
            else
            {
                stringstream stream1, stream2;
                integer1 = getRandomInt(RadowmLow, RadowmHigh);
                stream1 << integer1;
                stream1 >> first;
                integer2 = getRandomInt(RadowmLow, RadowmHigh);
                stream2 << integer2;
                stream2 >> second;
            }

            if (flags2 == 1)
            {
                ch3 = getRandomInt(1, 3);
                switch (ch3)
                {
                case 1:
                    first = "(" + first + ")";
                    second = "(" + second + ")";
                    break;
                case 2:
                    first = "(-" + first + ")";
                    second = "(" + second + ")";
                    break;
                case 3:
                    first = "(-" + first + ")";
                    second = "(-" + second + ")";
                    break;
                }
            }
            else
            {
                first = "(" + first + ")";
                second = "(" + second + ")";
            }
            if (flags3 == 1)
            {
                ch4 = getRandomInt(1, 4);
                switch (ch4)
                {
                case 1:
                {
                    if (flag4 == 1)
                    {
                        Terminal = first + sign + second;
                        flag4 = 0;
                    }
                    else
                    {
                        Terminal = Terminal + sign + first;
                    }
                }
                break;
                case 2:
                {
                    if (flag4 == 1)
                    {
                        Terminal = second + sign + first;
                        flag4 = 0;
                    }
                    else
                    {
                        Terminal = second + sign + Terminal;
                    }
                }
                break;
                case 3:
                {
                    if (flag4 == 1)
                    {
                        Terminal = "[" + first + sign + second + "]";
                        flag4 = 0;
                    }
                    else
                    {
                        Terminal = "[" + Terminal + sign + first + "]";
                    }
                }
                break;
                case 4:
                {
                    if (flag4 == 1)
                    {
                        Terminal = "[" + second + sign + first + "]";
                        flag4 = 0;
                    }
                    else
                    {
                        Terminal = "[" + second + sign + Terminal + "]";
                    }
                }
                break;
                }
            }
            else
            {
                ch4 = getRandomInt(1, 2);
                switch (ch4)
                {
                case 1:
                {
                    if (flag4 == 1)
                    {
                        Terminal = first + sign + second;
                        flag4 = 0;
                    }
                    else
                    {
                        Terminal = Terminal + sign + first;
                    }
                }
                break;
                case 2:
                {
                    if (flag4 == 1)
                    {
                        Terminal = second + sign + first;
                        flag4 = 0;
                    }
                    else
                    {
                        Terminal = second + sign + Terminal;
                    }
                }
                break;
                }
            }
            j++;
        }
        if (wc == 1)
        {
            if (str.empty())
            {
                str.push_back(Terminal);
                cout << Terminal << "=" << endl;
                i++;
            }
            if (is_unique(Terminal, str))
            {
                str.push_back(Terminal);
                cout << Terminal << "=" << endl;
                i++;
            }
        }
        if (wc == 2)
        {

            cout << "Writing to the file successfully" << endl;
            if (str.empty())
            {
                str.push_back(Terminal);
                outfile << Terminal << "=" << endl;
                i++;
            }
            if (is_unique(Terminal, str))
            {
                str.push_back(Terminal);
                outfile << Terminal << "=" << endl;
                i++;
            }
        }
    }
}
int main()
{
    cout << "请输入题目数(1~100)：";
    int times, down, up, flag1, flag2, flag3, flag4, flag5 = 1;
    cin >> times;
    cout << "请输入数值范围:";
    cin >> down >> up;
    cout << "是否加入乘除法（y/n）:";
    char judement1;
    cin >> judement1;
    judement1 == 'y' || judement1 == 'Y' ? flag1 = 1 : flag1 = 0;
    cout << "是否加入负数（y/n）:";
    char judement;
    cin >> judement;
    judement == 'y' || judement == 'Y' ? flag2 = 1 : flag2 = 0;
    cout << "是否含有括号（y/n）:";
    char judement2;
    cin >> judement2;
    judement2 == 'y' || judement2 == 'Y' ? flag3 = 1 : flag3 = 0;
    cout << "是否有小数运算（y/n）：";
    char judement3;
    cin >> judement3;
    judement3 == '1' || judement3 == '0' ? flag4 = 1 : flag4 = 0;
    cout << "1屏幕输出，2文件输出，3打印机输出：";
    int wc;
    cin >> wc;
    if (wc == 2)
    {
        cout << "需要修改绝对路径";
        outfile.open("//Users//zh//Downloads//四则运算.txt");
        operation(times, down, up, flag1, flag2, flag3, flag4, flag5, wc);
        outfile.close();
        return 0;
    }
    operation(times, down, up, flag1, flag2, flag3, flag4, flag5, wc);
    return 0;
}
