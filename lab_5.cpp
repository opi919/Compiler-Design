#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

bool checkBetween(char start, char end, char c)
{
    if (c >= start && c <= end)
        return true;
    return false;
}

int findDot(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            return i;
    }
    return -1;
}

int main()
{
    string str;
    ifstream file;
    file.open("lab5.txt");
    getline(file, str);
    file >> str;
    if (checkBetween('a', 'h', str[0]) || checkBetween('A', 'H', str[0]) || checkBetween('o', 'z', str[0]) || checkBetween('O', 'Z', str[0]))
    {
        bool flag = false;
        for (int i = 1; i < str.length(); i++)
        {
            if (checkBetween('a', 'z', str[i]) || checkBetween('A', 'Z', str[i]) || checkBetween('0', '9', str[i]))
            {
                flag = false;
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag)
            cout << "Undefined" << endl;
        else
            cout << "Float variable" << endl;
    }
    else
    {
        if (str[0] == '0' || checkBetween('1', '9', str[0]))
        {
            bool flag = false;
            int index = findDot(str);
            for (int i = 1; i < index; i++)
            {
                if (checkBetween('0', '9', str[i]))
                {
                    flag = false;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if(str[0]=='0' && str[1]!='.') flag = true;
            if (flag)
                cout << "Undefined" << endl;
            else
            {
                bool flag = false;
                int cnt = 0;
                for (int i = index + 1; i < str.length(); i++)
                {
                    if (checkBetween('0', '9', str[i]))
                    {
                        cnt++;
                    }
                    else
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    cout << "Undefined" << endl;
                else if (cnt == 2)
                    cout << "Float number" << endl;
                else
                    cout << "Double number" << endl;
            }
        }
        else
            cout << "Undefined" << endl;
    }
}