#include<bits/stdc++.h>
using namespace std;






struct nassy{

string tp;
int cntChildren;
nassy *children[100];

int szx, szy; //pixels;


//tp==0, nothing


//tp==1, 1-linie de cod;
    string code;

//tp==2, 2-if;
    string condition;
    bool hasElse=false;
    nassy *thisElse;
    //cntChildren = 2;

//tp==3, 3-for
    string forStatement;

//tp==4, 4-while
    string whileStatement;

//tp==5, 5-while do
    string whileDoStatement;

//tp==6, 6-switch
    string switchStatement;

//tp else

//tp case
string caseStatement;

//tp==-1, -1-main

};
