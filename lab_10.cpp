#include<bits/stdc++.h>
#include<string.h>
using namespace std;

char ip[20],stk[20],ts[20];
int len,i=0,j=0,np,ck;

struct grammer
{
    char p[10];
    char prod[10];
}g[10];

void check(){
    string temp = stk;
    int flag = 0;
        for(int m=0;m<np;m++){
           ck = temp.find(g[m].prod);
        //    cout<<stk<<" "<<g[m].prod<<" "<<ck<<endl;
            if(ck>=0){
                printf("\tReduced by %s->%s",g[m].p,g[m].prod);

                stk[ck] = g[m].p[0];
                stk[ck+1] = '\0';
                i=i-(strlen(g[m].prod)-1);
                printf("\n$%s\t%s",stk,ip);
                break;
            }
        }
}


int main(){
    printf("Enter the number of productions: ");
    cin>>np;
    printf("\nEnter the productions: ");
    for(int i=0;i<np;i++){
        cin>>ts;
        strncpy(g[i].p,ts,1);
        strcpy(g[i].prod,&ts[3]);
    }
    printf("\nEnter the input string: ");
    cin>>ip;
    len = strlen(ip);

    printf("\n$\t%s",ip);

    for(i=0,j=0;j<len;i++,j++){

        printf("\tShifted");

        stk[i]=ip[j];
        stk[i+1]='\0';
        ip[j]=' ';

        printf("\n$%s\t%s",stk,ip);

        check();
        check();
    }

    if(strcmp(stk,"E")== 0 && stk[1] == '\0')
        printf("\n\nString is accepted");

}