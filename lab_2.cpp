#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        return true;
    else
        return false;
}

void vc(string str)
{
    string vowels;
    int vowel = 0, consonant = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowel++;
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            consonant++;
        }
    }
    cout << "Vowels = " << vowel << endl;
    cout << "Consonants = " << consonant << endl;
}

void exist(string str)
{
    int va = 0, ve = 0, vi = 0, vo = 0, vu = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a' || str[i] == 'A')
            va = 1;
        else if (str[i] == 'e' || str[i] == 'E')
            ve = 1;
        else if (str[i] == 'i' || str[i] == 'I')
            vi = 1;
        else if (str[i] == 'o' || str[i] == 'O')
            vo = 1;
        else if (str[i] == 'u' || str[i] == 'U')
            vu = 1;
    }
    cout << ((va == 1) ? "a exist" : "a not exist") << endl;
    cout << ((ve == 1) ? "e exist" : "e not exist") << endl;
    cout << ((vi == 1) ? "i exist" : "i not exist") << endl;
    cout << ((vo == 1) ? "o exist" : "o not exist") << endl;
    cout << ((vu == 1) ? "u exist" : "u not exist") << endl;
}

void divide(string str)
{
    string vowel, consonant;
    // separate words started with vowel
    for (int i = 0; i < str.length();i++)
    {
        if (isVowel(str[i]))
        {
            for (int j = i; ;j++)
            {
                vowel += str[j];
                if (str[j] == ' ' || str[j] == '.' || str[j] == ',' || str[j] == '\n')
                {
                    vowel += ' ';
                    i = j;
                    break;
                }
            }
        }
        else
        {
            for (int j = i;; j++)
            {
                consonant += str[j];
                if (str[j] == ' ' || str[j] == '.' || str[j] == ',' || str[j] == '\n')
                {
                    consonant += ' ';
                    i = j;
                    break;
                }
            }
        }
    }
    cout << "Vowels = " << vowel << endl;
    cout << "Consonants = " << consonant << endl;
}

int main()
{
    string str, vowels;
    int vowel = 0, consonant = 0;
    ifstream file;
    file.open("lab2.txt");
    getline(file, str);
    file >> str;
    vc(str);
    exist(str);
    divide(str);
}
