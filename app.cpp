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
struct User{
    string name;
    double balance;
} user;
struct Cateogy{
    int catId;
    string catName;
};
struct Expense{
    string eName;
    double eAmount;
    int eCategoryNo;
    string eCategory;
    time_t eTime;
};

/* All Global Variable */
double totalExpenseAmount = 0;
int totalExpense = 0;
string expId;
int totalCategory = 0;
string cateogryList[200];

/* Function defination  */
void getCategoryList();
void displayCategoryList();
void addCategory();
void updateCategory();
void categoryWiseExpance();

void save();
void deleteExp();
void showCurrentBalance();

map<int, Expense> expList;

void addExpense();
void displayExpList();
void updateExp(int expId){

}
int main()
{
    cout<<"Welcome to Expense app \n\nPlease input your name : ";
    std::getline(std::cin >> std::ws, user.name);
    cout<<"Input your wallet Amount : ";
    cin>>user.balance;

    getCategoryList();
    int n;
    while(1){
        printf("1. For add your expense press 1 \n");
        printf("2. For display Expense, press 2\n");
        printf("3. For display Category, press 3\n");
        printf("4. For Add category, press 4\n");
        printf("5. For Update category, press 5\n");
        printf("6. For Delete expense, press 6\n");
        printf("7. Show Current Balance , press 7\n");
        printf("8. Show Current Balance , press 8\n");
        printf("9. For Save, press 9\n");
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
        }else if(n==6){
            deleteExp();
        }else if(n==7){
            showCurrentBalance();
        }
        else if(n==8){
            categoryWiseExpance();
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

    if(exp.eAmount>user.balance){
        printf("fail to add. Expense amount is grater than current balance \n ");
        return;
    }

    expList.insert(pair<int, Expense>(totalExpense, exp));
    totalExpenseAmount=+ exp.eAmount;
}

void displayExpList(){
    map<int, Expense>::iterator itr;
    int i =1;
    for (itr = expList.begin(); itr != expList.end(); ++itr) {
        cout<<itr->first<< ". "<< itr->second.eName << '\t' << itr->second.eCategory
             << '\t' << itr->second.eAmount << '\n';
    }
}
void deleteExp(){
    int id;
    printf("Please Input your Expense id: ");
    cin>>id;
    std::map<int, Expense>::iterator it = expList.find(id);
    if (it != expList.end())
    totalExpenseAmount -= it->second.eAmount;

    expList.erase(id);
}
void showCurrentBalance(){
    cout<<"your Current Balance is " << user.balance - totalExpenseAmount<<endl;
}
void addAmountToWallet(){
    double amount;
    printf("Please Input your Amount : ");
    cin>>amount;
    user.balance += amount;
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
    cout<<endl<<endl;
}
void categoryWiseExpance(){
    displayCategoryList();
    int i =1, eCategoryNo;
    cout<<"Please input your Category No : ";
    cin>>eCategoryNo;

    map<int, Expense>::iterator itr;
    for (itr = expList.begin(); itr != expList.end(); ++itr) {
        if(eCategoryNo == itr->second.eCategoryNo){
            cout<<itr->first<< ". "<< itr->second.eName << '\t' << itr->second.eCategory
             << '\t' << itr->second.eAmount << '\n';
        }

    }
    cout<<endl<<endl;
}
