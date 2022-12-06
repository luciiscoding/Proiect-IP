#include<bits/stdc++.h>
#include "draw.cpp"
using namespace std;


bool checkIf(string s){

    return (s.length()>=3) && s[0]=='i' && s[1]=='f' && s[2]=='(';

}

bool checkFor(string s){
    return (s.length()>=4) && s[0]=='f' && s[1]=='o' && s[2]=='r' && s[3]=='(';
}


bool checkElse(string s){
    return (s.length()>=5) && s[0]=='e' && s[1]=='l' && s[2]=='s' && s[3]=='e' && s[4]=='{';
}


bool checkSwitch(string s){
    return (s.length()>=7) && s[0]=='s' && s[1]=='w' && s[2]=='i' && s[3]=='t' && s[4]=='c' && s[5]=='h' && s[6]=='(';
}

bool checkCase(string s){

return (s.length()>=5) && s[0]=='c' && s[1]=='a' && s[2]=='s' && s[3]=='e' && s[4]==' ';

}

bool checkWhile(string s){

    return (s.length()>=6) && s[0]=='w' && s[1]=='h' && s[2]=='i' && s[3]=='l' && s[4]=='e' && s[5]=='(';

}


bool checkDo(string s){

    return (s.length()>=3) && s[0]=='d' && s[1]=='o' && s[2]=='{';

}

void build(nassy *&Node, int &i, int n, string s[]){

while(true){
cout<<Node->tp<<" "<<i<<" "<<s[i]<<"\n";
if(i>n){
    return;
}

if(s[i][0]=='}'){
    i++;
    return;
}



if( (Node->tp=="main") || (Node->tp=="if") || (Node->tp=="for") || (Node->tp=="while") || (Node->tp=="while do") || (Node->tp=="else") || (Node->tp=="case") ){

    if( checkIf(s[i]) ){
            //cout<<"pam pam";
        Node->cntChildren++;
        Node->children[ Node->cntChildren ] = new nassy();
        Node->children[ Node->cntChildren ]->condition = s[i];
        Node->children[ Node->cntChildren ]->condition.pop_back();
        Node->children[Node->cntChildren]->tp = "if";
        i++;
        int ac = Node->cntChildren;
        build(Node->children[Node->cntChildren], i, n, s);
        if( checkElse(s[i]) ){
            Node->children[ac]->hasElse=true;
            Node->children[ac]->thisElse = new nassy();
            Node->children[ac]->thisElse->tp="else";
            i++;
            build(Node->children[ac]->thisElse, i, n, s);
        }
        continue;
    }


    if(checkFor(s[i])){


        Node->cntChildren++;
        Node->children[ Node->cntChildren ] = new nassy();
        Node->children[ Node->cntChildren ]->forStatement = s[i];
        Node->children[ Node->cntChildren ]->forStatement.pop_back();

        Node->children[Node->cntChildren]->tp = "for";
        i++;
        build(Node->children[Node->cntChildren], i, n, s);

        continue;
    }

    if(checkSwitch(s[i])){
        Node->cntChildren++;
        Node->children[Node->cntChildren] = new nassy();
        Node->children[ Node->cntChildren ]->tp="switch";
        Node->children[Node->cntChildren]->switchStatement=s[i];
        Node->children[Node->cntChildren]->switchStatement.pop_back();
        i++;
        build( Node->children[ Node->cntChildren ], i, n, s );
        continue;
    }

    if( checkWhile(s[i]) ){
        Node->cntChildren++;
        Node->children[Node->cntChildren] = new nassy();
        Node->children[ Node->cntChildren ]->tp = "while";
        Node->children[ Node->cntChildren ]->whileStatement = s[i];
        Node->children[ Node->cntChildren ]->whileStatement.pop_back();
        i++;
        build(Node->children[ Node->cntChildren ],i,n,s );
        continue;
    }

    if( checkDo(s[i]) ){
        Node->cntChildren++;
        Node->children[Node->cntChildren]=new nassy();
        Node->children[ Node->cntChildren ]->tp="while do";
        i++;
        build( Node->children[Node->cntChildren], i, n, s );
        i--;
        Node->children[Node->cntChildren]->whileDoStatement = s[i];
        Node->children[Node->cntChildren]->whileDoStatement.pop_back();
        Node->children[Node->cntChildren]->whileDoStatement.erase(0, 1);
        i++;
        cout<<Node->children[Node->cntChildren]->whileDoStatement<<" ";
        Node->children[Node->cntChildren]->whileDoStatement+=" do";
        continue;
    }

    //cout<<"ss";
    Node->cntChildren++;
    Node->children[Node->cntChildren]=new nassy();
    Node->children[Node->cntChildren]->tp = "code";
    Node->children[Node->cntChildren]->code = s[i];
    i++;
    continue;
}

if(Node->tp=="switch"){

    Node->cntChildren++;
    Node->children[Node->cntChildren]=new nassy();
    Node->children[Node->cntChildren]->tp="case";
    Node->children[Node->cntChildren]->caseStatement = s[i];
    Node->children[Node->cntChildren]->caseStatement.pop_back();
    i++;
    build(Node->children[Node->cntChildren ], i, n, s);
    continue;
}





}



}



nassy* read(){

int n;

cin>>n;

string s[n+5];
getline(cin, s[0]);
for(int i=1; i<=n; i++){
    getline(cin, s[i]);
    while(s[i][0]==' '){
        s[i].erase(0, 1);
    }
}

nassy *Main = new nassy();
Main->tp = "main";
int i = 1;
build(Main, i, n, s);


return Main;
}

