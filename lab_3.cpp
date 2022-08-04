#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string str,dept,courseCode,fulldept,year,semester,courseName,coursetype;
    int index;
    ifstream file;
    file.open("lab_3.txt");
    getline(file, str);
    file>>str;
    for(int i=0;i<3;i++){
        dept+=str[i];
    }
    cout<<"Department = "<<dept<<endl;
    for(int i=4;i<8;i++){
        courseCode+=str[i];
    }
    cout<<"Course code = "<<courseCode<<endl;
    for(int i=12;i<str.length();i++){
        if(str[i]==',') {index=i;break;}
        fulldept+=str[i];
    }
    cout<<"Full department = "<<fulldept<<endl;
    for(int i=index+1;i<str.length();i++){
                if(str[i]==',') {index=i;break;}
        year+=str[i];
    }
    cout<<"Year = "<<year<<endl;
    for(int i=index+1;i<str.length();i++){
                if(str[i]==',') {index=i;break;}
        semester+=str[i];
    }
    cout<<"Semester = "<<semester<<endl;
    for(int i=index+1;i<str.length();i++){
                if(str[i]==',') {index=i;break;}
        courseName+=str[i];
    }
    cout<<"Course name = "<<courseName<<endl;
    for(int i=index+1;i<str.length();i++){
                if(str[i]=='.') {index=i;break;}
        coursetype+=str[i];
    }
    cout<<"Course type = "<<coursetype<<endl;
}