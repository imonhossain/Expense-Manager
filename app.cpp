#include<iostream>
#include <ctime>
#include <iterator>
#include <map>
#include<stdio.h>
using namespace std;

struct Expense{
    //int eId;
    string eName;
    string eCategory;
    time_t eTime;
};
int totalExpense = 0;
Expense exp;
string expId;
map<int, Expense> expList;

void addExpense(){
    totalExpense++;
    Expense exp;
    //exp.eId = 1;
    printf("Input Expense name : ");
    cin>>exp.eName;

    printf("Input Expense Category : ");
    cin>>exp.eCategory;
    cout<<endl;
    exp.eTime = time(0);
    expList.insert(pair<int, Expense>(totalExpense, exp));
}
void displayExpList(){
    map<int, Expense>::iterator itr;
    for (itr = expList.begin(); itr != expList.end(); ++itr) {
        cout << '\t' << itr->second.eName << '\t' << itr->second.eCategory
             << '\t' << itr->second.eTime << '\n';
    }
}
void updateExp(int expId){

}
int main()
{
    int n;
    while(1){
        printf("For save your expense press 1 \n");
        printf("For display press 2\n");
        scanf("%d", &n);
        if(n==1){
            addExpense();
        }if(n==2){
            displayExpList();
        }
        if(n==0){
            break;
        }
        else{

        }

    }

    cout << endl;

    return 0;
}
