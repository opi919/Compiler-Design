#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

// id = any integer or any character

int np;
char ts[10];
string first[10], follow[10];

struct grammer
{
    string p;
    string prod; // production
} g[10];

void first_set(int i)
{
    for (int j = 1; j <= g[i].prod.length(); j++)
    {
        if (g[i].prod[j - 1] == '|')
        {

            first[i] += g[i].prod[j];
            break;
        }
    }
    if (g[i].prod[0] >= 'A' && g[i].prod[0] <= 'Z')
    {
        for (int j = 0; j < np; j++)
        {
            if (g[j].p[0] == g[i].prod[0])
            {
                if (first[j].empty())
                    first_set(j);
                else
                {
                    first[i] += first[j];
                    
                }
                break;
            }
        }
    }
    else
    {
        first[i] += g[i].prod[0];
    }
}

int main()
{
    printf("Enter the number of productions: ");
    cin >> np;
    printf("\nEnter the productions: ");
    for (int i = 0; i < np; i++)
    {
        cin >> ts;
        int flag = 1;

        for (int j = 0; j < strlen(ts); j++)
        {
            if (ts[j] == '-')
            {
                flag = 0;
                j += 2;
            }
            if (flag)
                g[i].p += ts[j];
            else
                g[i].prod += ts[j];
        }
    }
    // find first set
    for (int i = np - 1; i >= 0; i--)
    {
        first_set(i);
    }

    // print first set
    cout << "First Set: " << endl;
    for (int i = 0; i < np; i++)
    {
        cout << g[i].p << " -> {" << first[i] << "}" << endl;
    }
}
