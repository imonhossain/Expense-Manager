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

/* All Global Variable */
int totalExpense = 0;
string expId;
int totalCategory = 0;
string cateogryList[200];

/* Function defination  */
void getCategoryList();
void displayCategoryList();
void addCategory();
void updateCategory();
void save();

map<int, Expense> expList;

void addExpense();
void displayExpList();
void updateExp(int expId){

}
int main()
{
    getCategoryList();
    int n;
    while(1){
        printf("1. For save your expense press 1 \n");
        printf("2. For display Expense, press 2\n");
        printf("3. For display Category, press 3\n");
        printf("4. For Add category, press 4\n");
        printf("5. For Update category, press 5\n");
        printf("6. For Save, press 9\n");
        scanf("%d", &n);
        if(n==1){
            addExpense();
        }else if(n==2){
            displayExpList();
        }else if(n==3){
            displayCategoryList();
        }else if(n==4){
            addCategory();
        }else if(n==5){
            updateCategory();
        }
        else if(n==9){
            save();
        }
        else if(n==0){
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

char cateogryFileName[30];
char expenseFileName[30];
void getCategoryList(){
    //printf("Input your category file name. make sure this file's name max 30 character and same directory  : ");
    //cin>>cateogryFileName;

    //ifstream MyReadFile(cateogryFileName);
    ifstream MyReadFile("ctList.txt");
    string myText;
    while (getline (MyReadFile, myText)) {
       totalCategory++;
       cateogryList[totalCategory] = myText;
    }
}
void addCategory(){
    string name;
    std::getline(std::cin >> std::ws, name);
    totalCategory++;
    cateogryList[totalCategory] = name;
    /*
    ofstream fout;
    if(cateogryFileName[0] == '\0'){
        printf("Input your category file name. make sure this file's name max 30 character and same directory  : ");
        cin>>cateogryFileName;
        ifstream MyReadFile(cateogryFileName);
    }
    fout.open(cateogryFileName);
    fout << name << endl;
    fout.close();
*/
}
void save(){
    ofstream catOut;
    if(cateogryFileName[0] == '\0'){
        printf("Input your category file name. make sure this file's name max 30 character and same directory  : ");
        cin>>cateogryFileName;
        ifstream MyReadFile(cateogryFileName);
    }
    catOut.open(cateogryFileName);
    for(int i=0; i<totalCategory; i++){
        catOut << cateogryList[i] << endl;
    }
    catOut.close();

    ofstream expOut;
    if(expenseFileName[0] == '\0'){
        printf("Input your Expense file name. make sure this file's name max 30 character and same directory  : ");
        cin>>expenseFileName;
        ifstream MyReadFile(expenseFileName);
    }
    map<int, Expense>::iterator itr;
    int i =1;
    expOut.open(expenseFileName);
    for (itr = expList.begin(); itr != expList.end(); ++itr) {

        expOut << itr->second.eName << endl;
        expOut << itr->second.eAmount << endl;
        expOut << itr->second.eCategory << endl;
        expOut << itr->second.eTime << endl;

    }
    expOut.close();
}
void updateCategory(){
    int id;
    printf("Input your category ID: ");
    cin>>id;
    printf("Input your new category name : ");
    string name;
    std::getline(std::cin >> std::ws, name);
    //totalCategory++;
    cateogryList[id] = name;
}
void displayCategoryList(){
    for(int i =1; i<=totalCategory; i++){
        cout<<i<<"."<<'\t'<<cateogryList[i]<<endl;
    }
}
