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
    int low = down, high = up;
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
    int high = min(temp1, temp2);
    int low = max(temp1, temp2);
    stringstream tra, stream1;
    string up, down;
    tra << high;
    tra >> up;
    stream1 << low;
    stream1 >> down;
    string fra;
    high != low ? fra = up + "\\" + down : fra = "1";
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
void operation(int time, int low, int high, int fl1, int fl2, int fl3, int fl4, int fl5, int wc)
{
    int integer1, integer2;
    int ch1, ch2, ch3, ch4;
    char sign;
    int times = time;
    vector<string> str;
    for (int i = 1; i <= times;)
    {
        int flag4 = 1;
        string first, second, cal;
        int number = getRandomInt(1, 9);
        for (int j = 1; j <= number;)
        {

            if (fl1 == 1)
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
            if (fl4 == 1)
            {
                ch2 = getRandomInt(1, 3);
                switch (ch2)
                {
                case 1:
                {
                    stringstream stream1, stream2;
                    integer1 = getRandomInt(low, high);
                    stream1 << integer1;
                    stream1 >> first;
                    integer2 = getRandomInt(low, high);
                    stream2 << integer2;
                    stream2 >> second;
                }
                break;
                case 2:
                {
                    stringstream kk;
                    integer1 = getRandomInt(low, high);
                    kk << integer1;
                    kk >> first;
                    second = fraction(low, high);
                }
                break;
                case 3:
                {
                    first = fraction(low, high);
                    second = fraction(low, high);
                }
                break;
                }
            }
            else
            {
                stringstream stream1, stream2;
                integer1 = getRandomInt(low, high);
                stream1 << integer1;
                stream1 >> first;
                integer2 = getRandomInt(low, high);
                stream2 << integer2;
                stream2 >> second;
            }

            if (fl2 == 1)
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
            if (fl3 == 1)
            {
                ch4 = getRandomInt(1, 4);
                switch (ch4)
                {
                case 1:
                {
                    if (flag4 == 1)
                    {
                        cal = first + sign + second;
                        flag4 = 0;
                    }
                    else
                    {
                        cal = cal + sign + first;
                    }
                }
                break;
                case 2:
                {
                    if (flag4 == 1)
                    {
                        cal = second + sign + first;
                        flag4 = 0;
                    }
                    else
                    {
                        cal = second + sign + cal;
                    }
                }
                break;
                case 3:
                {
                    if (flag4 == 1)
                    {
                        cal = "[" + first + sign + second + "]";
                        flag4 = 0;
                    }
                    else
                    {
                        cal = "[" + cal + sign + first + "]";
                    }
                }
                break;
                case 4:
                {
                    if (flag4 == 1)
                    {
                        cal = "[" + second + sign + first + "]";
                        flag4 = 0;
                    }
                    else
                    {
                        cal = "[" + second + sign + cal + "]";
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
                        cal = first + sign + second;
                        flag4 = 0;
                    }
                    else
                    {
                        cal = cal + sign + first;
                    }
                }
                break;
                case 2:
                {
                    if (flag4 == 1)
                    {
                        cal = second + sign + first;
                        flag4 = 0;
                    }
                    else
                    {
                        cal = second + sign + cal;
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
                str.push_back(cal);
                cout << cal << "=" << endl;
                i++;
            }
            if (is_unique(cal, str))
            {
                str.push_back(cal); 
                cout << cal << "=" << endl;
                i++;
            }
        }
        if (wc == 2)
        {

            cout << "Writing to the file successfully" << endl;
            if (str.empty()) 
            {
                str.push_back(cal);
                outfile << cal << "=" << endl;
                i++;
            }
            if (is_unique(cal, str)) 
            {
                str.push_back(cal); 
                outfile << cal << "=" << endl;
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
    cout << "请输入数值绝对值范围:";
    cin >> down >> up;
    cout << "是否允许乘除法参与运算（y/n）:";
    char yn1;
    cin >> yn1;
    yn1 == 'y' || yn1 == 'Y' ? flag1 = 1 : flag1 = 0;
    cout << "是否允许负数参与运算（y/n）:"; 
    char yn;
    cin >> yn;
    yn == 'y' || yn == 'Y' ? flag2 = 1 : flag2 = 0; 
    cout << "是否允许括号（）参与运算（y/n）:";
    char yn2;
    cin >> yn2;
    yn2 == 'y' || yn2 == 'Y' ? flag3 = 1 : flag3 = 0; 
    cout << "是否有小数运算（y/n）：";
    char yn3;
    cin >> yn3;
    yn3 == '1' || yn3 == '0' ? flag4 = 1 : flag4 = 0;
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
