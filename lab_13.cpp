#include <bits/stdc++.h>
#include <iostream>
#include <string.h>

using namespace std;

// id = any integer or any character

int np;
char ts[10];
string first[10], follow[10];
int visited[10][10];

struct grammer
{
    string p;
    string prod; // production
} g[10];

void follow_set(int i)
{
    for (int j = 0; j < np; j++)
    {
        int pos = g[j].prod.find(g[i].p);
        if (pos != string::npos) // g[i].p find successfully in g[j].prod
        {
            string temp = g[j].prod;
            if (temp[pos + 1] == '\'')
                pos++;
            if (temp[pos + 1] == '\0' || temp[pos + 1] == '|') // g[i].p is last character of g[j].prod
            {
                if (g[j].p != g[i].p)
                {
                    if (!follow[j].empty())
                        follow[i] += follow[j];
                }
            }
            else if (temp[pos + 1] >= 'A' && temp[pos + 1] <= 'Z') //containing non terminal value after g[i].p in g[j].pord
            {
                string non_terminal = "";
                non_terminal += temp[pos + 1];
                if (temp[pos + 2] == '\'')
                {
                    non_terminal += temp[pos + 2];
                    pos++;
                }
                // finding the grammar which contains non_terminal
                for (int k = 0; k < np; k++)
                {
                    if (g[k].p == non_terminal)
                    {
                        if (!first[k].empty() && visited[i][k] != 1) //if first of non_terminal is not empty
                        {
                            visited[i][k] = 1;
                            for (int l = 0; l < first[k].length(); l++)
                            {
                                if (first[k][l] == 'e')  // checking for epsilon
                                {
                                    pos++;
                                    // cout << g[j].p <<" "<< g[k].p << endl;
                                    // cout<<temp[pos + 1]<<endl;
                                    if (temp[pos + 1] == '\0' || temp[pos + 1] == '|')
                                    {
                                        if (g[j].p != g[k].p)
                                        {
                                            if (!follow[j].empty())
                                                follow[i] += follow[j];
                                        }
                                    }
                                }
                                else
                                    follow[i] += first[k][l];    // adding first of non_terminal to follow of g[i].p without epsilon
                            }
                        }
                    }
                }
            }
            else
            {
                follow[i] += temp[pos + 1];
                return;
            }
        }
    }
}

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
    // first started here
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

    // follow started here
    // find follow set
    for (int i = 0; i < np; i++)
    {
        if (i == 0)
            follow[i] += "$";
        follow_set(i);
    }

    // print follow set
    cout << "Follow Set: " << endl;
    for (int i = 0; i < np; i++)
    {
        cout << g[i].p << " -> {" << follow[i] << "}" << endl;
    }
}
