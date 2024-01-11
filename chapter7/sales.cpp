#include<iostream>
#include "Screen.h"

using namespace std;

int main(){
    Screen myScreen(5,5,'X');
    myScreen.move(4,0).set('#').display(cout);
    cout<<"\n";
    const Screen blank(5,3);
    blank.display(cout);
    cout<<"\n";
    return 0;
}