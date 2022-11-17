#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

string reverse(string s)
{
    string rev = "";
    for (int i = s.length() - 1; i >= 0; i--)
    {
        rev += s[i];
    }
    return rev;
}

bool palindrome(string s)
{
    string rev = reverse(s);
    if (s == rev)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string str,str2, vowel, consonant, palindrome, temp;
    int count=1;
    ifstream file;
    file.open("inputs/test.txt");
    // getline(file, str,EOF);
    while (getline(file, str2))
    {
        str+=str2;
    }
    // cout << str << endl;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    // find vowel consonant and palindrome
    for (int i = 0; i < str.length(); i++)
    {
        if(str[i]=='.') count++;
        if (str[i] == ' ' || str[i] == ',' || str[i] == '.')
        {
            // cout<<temp<<endl;
            if (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u')
            {
                vowel += temp + " ";
            }
            else
            {
                consonant += temp + " ";
            }
            // palindrome
            if (temp == reverse(temp))
            {
                palindrome += temp + " ";
            }
            temp = "";
        }
        else
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                temp += str[i];
            }
        }
    }
    // }
    cout << "Vowel: " << vowel << endl;
    cout << "Palindrome: " << palindrome << endl;
}