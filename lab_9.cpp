#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string pn[] = {"Sagor", "Selim", "Salma", "Nipu"};
    string p[] = {"he", "she", "we", "they", "you", "I"};
    string v[] = {"read", "eat", "run", "take", "write"};
    string n[] = {"book", "cow", "dog", "home", "grass", "rice", "mango"};

    string str;
    ifstream file;
    file.open("lab9.txt");
    getline(file, str);
    file >> str;

    string temp;
    int cn = 1;
    bool flag = false;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ' || str[i] == '.' || str[i] == '?' || str[i] == '!' || str[i] == '\n')
        {

            if (cn == 1)
            {
                cn++;
                for (int j = 0; j < 6; j++)
                {
                    if (temp == pn[j])
                    {
                        flag = true;
                        break;
                    }

                    else if (temp == p[j])
                    {
                        flag = true;
                        break;
                    }
                    else
                    {
                        flag = false;
                    }
                }
                if (!flag)
                {
                    flag = false;
                    break;
                }
                temp.clear();
            }
            else if (cn == 2)
            {
                cn++;
                // check if v contains temp
                for (int j = 0; j < 5; j++)
                {
                    if (temp == v[j])
                    {
                        flag = true;
                        break;
                    }
                    else
                        flag = false;
                }
                if (!flag)
                {
                    flag = false;
                    break;
                }
                temp.clear();
            }
            else if (cn == 3)
            {
                cn++;
                // check if n contains temp
                for (int j = 0; j < 7; j++)
                {
                    if (temp == n[j])
                    {
                        flag = true;
                        break;
                    }
                    else
                        flag = false;
                }
                if (flag)
                    continue;
                else
                {
                    flag = false;
                    break;
                }
                temp.clear();
            }
            else
            {
                flag = false;
            }
            cout << temp << endl;
            temp.clear();
        }
        else
        {
            temp += str[i];
        }
    }
    if (flag)
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }
    return 0;
}
