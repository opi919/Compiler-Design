#include<bits/stdc++.h>
#include<iostream>
#include<fstream>

using namespace std;

void operation(string str)
{
    int word=0,letter=0,digit=0,other=0;
    string letters,digits,others;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] == ' ')
        {
            word++;
        }
        if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z'))
        {
            letter++;
            letters+=str[i];
        }
        else if(str[i]>='0' && str[i]<='9')
        {
            digit++;
            digits+=str[i];
        }
        else
        {
            other++;
            others+=str[i];
        }

    }
    word++;
    cout<<"Word = "<<word<<endl;
    cout<<"Letter = "<<letter<<endl;
    cout<<"Digit = "<<digit<<endl;
    cout<<"Other =" <<other<<endl;
    cout<<"Letters = "<<letters<<endl;
    cout<<"Digits = "<<digits<<endl;
    cout<<"Others = "<<others<<endl;
}


int main()
{
    int word=0,letter=0,digit=0,other=0;
    string str,letters,digits,others;
    ifstream file;
    file.open("lab1.txt");
    getline(file,str);
    file>>str;
    operation(str);
}
