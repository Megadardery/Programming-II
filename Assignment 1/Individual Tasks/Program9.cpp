// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 2 - Problem 9
// Program: Grade Count
// Author:  Adham Mamdouh Mohammed
// Date:    7 October 2018
// Version: 1.0
// Student Name : Adham Mamdouh Mohammed
// Student ID : 20170039
// Student Group : G_2

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    int grade;
    int mx = INT_MIN;
    
    while(cin >> grade, grade >= 0){ 
        v.push_back(grade);
        if(grade > mx){mx = grade;}
    }
    
    int* a = new int[mx+5];
    int sz = v.size();
    
    for(int i = 0 ; i <= mx ; ++i)
        a[i] = 0;
    
    
    for(int i = 0 ; i < sz ; ++i)
        a[v[i]]++;
    
    
    for(int i = 0 ; i <= mx ; ++i){
        if(a[i])
            cout << "Number of " << i << "'s:    " << a[i] << endl;
    }

    return 0;
}
