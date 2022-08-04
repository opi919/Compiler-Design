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

int main()
{
    string str;
    ifstream file;
    file.open("lab4.txt");
    getline(file, str);
    file >> str;
    // integer
    if (checkBetween('i', 'n', str[0]) || checkBetween('I', 'N', str[0]))
    {
        bool flag = false;
        for(int i = 1; i < str.length(); i++)
        {
            if(checkBetween('a','z',str[i]) || checkBetween('A','Z',str[i]) || checkBetween('0','9',str[i])){
                flag = false;
            }
            else{ flag = true;break;}
        }
        if(flag) cout<<"Invalid Type"<<endl;
        else cout<<"Integer"<<endl;
    }
    // short int
    else if (str.length() <= 4)
    {
        if (str.length() == 1)
        {
            if (checkBetween('1', '9', str[0]))
            {
                cout << "short int" << endl;
            }
            else
                cout << "Invalid Type" << endl;
        }
        else if (str.length() == 2)
        {
            if (checkBetween('1', '9', str[0]) && checkBetween('0', '9', str[1]))
            {
                cout << "short int" << endl;
            }
            else
                cout << "Invalid Type" << endl;
        }
        else if (str.length() == 3)
        {
            if (checkBetween('1', '9', str[0]) && checkBetween('0', '9', str[1]) && checkBetween('0', '9', str[2]))
            {
                cout << "short int" << endl;
            }
            else
                cout << "Invalid Type" << endl;
        }
        else if (str.length() == 4)
        {
            if (checkBetween('1', '9', str[0]) && checkBetween('0', '9', str[1]) && checkBetween('0', '9', str[2]) && checkBetween('0', '9', str[3]))
            {
                cout << "short int" << endl;
            }
            else
                cout << "Invalid Type" << endl;
        }
    }
    // long int
    else
    {
        if(checkBetween('1','9',str[0])){
            bool flag = false;
            for(int i=1;i<str.length();i++){
                if(!checkBetween('0','9',str[i])) {flag=true;break;}
            }
            if(flag) cout<<"Invalid Type"<<endl;
            else cout<<"long int"<<endl;
        }
        else cout<<"Invalid Type"<<endl;
    }
}