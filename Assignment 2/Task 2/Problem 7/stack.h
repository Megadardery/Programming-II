#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <cstdlib>
#include <iostream>
#include <string>
#include <valarray>


using namespace std;

void error (string message);


class Stack {
  private:
		valarray<int> data;
      	int  size;

  public:
		Stack ()
		{
		    size = 0;
        }
        Stack (int s)
        {
            size = s ;
            data.resize(size);
            for (int i = 0 ; i<size ; ++i)
            {
                data[i] = 0 ;
            }
        }
        Stack (int s , int f)
        {
            size = s ;
            data.resize(size);
            for (int i = 0 ; i<size ; ++i)
            {
                data[i] = f ;
            }
        }
  		int pop() {
  			if (size == 0) error("Underflow\n");
  			return data[--size];
		}

		void push(int v) {
  			if (size == data.size()) data.resize(size*2);
  			data[size++] = v;
		}
		void clear()
		{
		    data.resize(0);
		    size = 0;
		}
		bool isEmpty()
		{
		    return(!size); // if size = 0 return 1 only
		}
		int getSize()
		{
		    return size;
		}
		void print()
		{
		    for (int i = 0 ; i<size ; ++i) cout << data[i] << " ";
		    cout << "\n";
		}
};

void error (string message) {
	cout << "\n" << message << "\n";
	exit (1);
}

#endif
