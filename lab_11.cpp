#include <bits/stdc++.h>

using namespace std;

string grammar[] = {"E+E", "E-E", "E*E", "E/E", "(E)", "a", "b", "c"};

int isOperator(char ch)
{
    if (ch == '+')
        return 0;
    else if (ch == '-')
        return 1;
    else if (ch == '*')
        return 2;
    else if (ch == '/')
        return 3;
    else if (ch == '(')
        return 4;
    else
        return -1;
}

int main()
{
    string input, output;
    cout << "Enter the input string: ";
    cin >> input;

    output += 'E';
    cout<<output<<endl;

    //left most derivation
    for (int i = 0; i < input.length(); i++)
    {
        if (isOperator(input[i]) != -1)
        {
            output.erase(output.length() - 1, 1);
            output += grammar[isOperator(input[i])];
        }
        cout<<output<<endl;

    }

    for(int i=0;i<output.length();i++){
        if(output[i]=='E'){
            output[i] = input[i];
            cout<<output<<endl;
        }
    }
}