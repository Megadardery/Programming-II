// Course:  CS213 - Programming II  - 2018
// Title:   Assignment 3 - Task 2 - Problem 4
// Program: Problem 7.cpp
// Purpose: Recursive Permute String
// Author:  Belal Hamdy Ezzat
// Date:    16 October 2018
// Version: 1
//-------------------------------------------------
#include <iostream>
using namespace std;
typedef long long ll;
string deletechar (string w , int c)
{
    string f;
    for (int i = 0 ; i<w.size();++i)
    {
        if (i==c)continue;
        f+=w[i];
    }
    return f;
}
void list_perm(string curr , string word)
{
    if (word.size())
    {
        for (int i = 0 ; i<word.size() ; ++i)
        {
            string newword = deletechar(word , i);;
            string newcurr = curr;
            newcurr+=word[i];
            list_perm(newcurr,newword);
        }
    }
    else
    {
        cout << curr << endl;
    }
}
ll fact (int n)
{
    return (n<=1? 1 : n*fact(n-1));
}
int main()
{
    i:
    string word;
    cout << "Enter the word (maximum length is 11) : ";
    cin >> word;
    cout << fact(int(word.size())) << "  Permutations is Found!\n\n";
    list_perm("",word);
    cout << endl ;
    goto i;
   return 0;
}
