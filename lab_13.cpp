#include <bits/stdc++.h>
#include <iostream>
#include<string.h>

using namespace std;

// id = any integer or any character

int np;
char ts[10];
string first[10], follow[10];

struct grammer
{
    string p;
    string prod;
} g[10];

void first_set(int i)
{
    // if g[i].prod contains |
    int k = 1;

    for (int j = 1; j <= g[i].prod.length(); j++)
    {
        if (g[i].prod[j - k] == '|')
        {
            
            first[i] += g[i].prod[j];
            cout<<first[i]<<" | "<<endl;
            k++;
        }
    }
    if (g[i].prod[0] >= 'A' && g[i].prod[0] <= 'Z')
    {
        for (int j = 0; j < np; j++)
        {
            if (g[j].p[0] == g[i].prod[0])
            {
                if (first[j][0] == '\0')
                    first_set(j);
                else
                {

                    first[i] += first[j];
                    cout<<first[i]<<" \0 "<<endl;
                    return;
                }
            }
        }
    }
    else
    {
        first[i] += g[i].prod[0];
        cout<<first[i]<<" else "<<endl;
        return;
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
            if(ts[j]=='-'){
                flag =0; 
                j+=2;
            }
            if(flag) g[i].p+=ts[j];
            else g[i].prod+=ts[j];
        }
    }
    // find first set
    for (int i = 0; i < np-2; i++)
    {
        first_set(i);
    }
    first_set(0);

    // print first set
    for (int i = 0; i < np; i++)
    {
        if (g[i].p[1] != '\0')
            printf("\nFirst(%c%c) = { ", g[i].p[0], g[i].p[1]);
        else
            printf("\nFirst(%c) = { ", g[i].p[0]);
        for (int j = 0; j < first[i].length(); j++)
        {
            printf("%c ", first[i][j]);
        }
        printf(" }");
    }
}
