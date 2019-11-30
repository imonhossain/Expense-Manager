#include<iostream>
#include <ctime>
#include <iterator>
#include <map>
#include <bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "category.cpp"
using namespace std;

struct Cateogy{
    int catId;
    string catName;
};
struct Expense{
    int eId;
    string eName;
    string eAmount;
    int eCategoryNo;
    string eCategory;
    time_t eTime;
};

/* all Global Variable */
int totalExpense = 0;
string expId;
int totalCategory = 0;
string cateogryList[200];
/* Function defination  */
void getCategoryList();
void displayCategoryList();

map<int, Expense> expList;

void addExpense();
void displayExpList();
void updateExp(int expId){

}
int main()
{
    getCategoryList();
    //displayCategoryList();

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



void addExpense(){
    totalExpense++;
    Expense exp;
    printf("Input Expense name : ");
    std::getline(std::cin >> std::ws, exp.eName);
    printf("Input Expense Amount : ");
    cin>>exp.eAmount;
    printf("Input your expense category id: \n");
    displayCategoryList();
    cin>>exp.eCategoryNo;
    exp.eCategory = cateogryList[exp.eCategoryNo];
    cout<<endl;
    exp.eTime = time(0);
    expList.insert(pair<int, Expense>(totalExpense, exp));
}

void displayExpList(){
    map<int, Expense>::iterator itr;
    int i =1;
    for (itr = expList.begin(); itr != expList.end(); ++itr) {
        cout<<i<< ". "<< itr->second.eName << '\t' << itr->second.eCategory
             << '\t' << itr->second.eTime << '\n';
    }
}


void getCategoryList(){
    ifstream MyReadFile("categoryList.txt");
    string myText;
    while (getline (MyReadFile, myText)) {
       totalCategory++;
       cateogryList[totalCategory] = myText;
    }
}
void displayCategoryList(){
    for(int i =1; i<=totalCategory; i++){
        cout<<i<<"."<<'\t'<<cateogryList[i]<<endl;
    }
}
