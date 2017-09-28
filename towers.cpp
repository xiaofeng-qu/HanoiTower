// Xiaofeng Qu xq6@zips.uakron.edu
#include <iostream>
#include "towers.h"
#include "mystack.h"

using namespace std;
// constructor
Towers::Towers(int numDisk)
{
    this->numDisk = numDisk;
    setDisks();
}

// destructor
Towers::~Towers()
{
    peg1->~MyStack();
    peg2->~MyStack();
    peg3->~MyStack();
    delete peg1;
    delete peg2;
    delete peg3;
    peg1 = nullptr;
    peg2 = nullptr;
    peg3 = nullptr;
}

// copy constructor
Towers::Towers(const Towers &tw)
{
    numDisk = tw.numDisk;
    peg1 = new MyStack<int>(numDisk);
    peg2 = new MyStack<int>(numDisk);
    peg3 = new MyStack<int>(numDisk);
    *peg1 = *tw.peg1;
    *peg2 = *tw.peg2;
    *peg3 = *tw.peg3;
}

// initial the pegs
void Towers::setDisks()
{
    // create peg1, peg2, peg3
    peg1 = new MyStack<int>(numDisk);
    peg2 = new MyStack<int>(numDisk);
    peg3 = new MyStack<int>(numDisk);
    // push all the disks into peg1
    for (int i = numDisk; i > 0; i--)
    {
        peg1->push(i);
    }
    // plot the pegs
    plotPegs();
}

//display disks on the three pegs in the console window (stdout)
//DO NOT MODIFY THIS FUNCTION
void Towers::plotPegs()
{
  	if (peg1==NULL || peg2==NULL || peg3==NULL) return;

	int n1=peg1->size();
	int n2=peg2->size();
	int n3=peg3->size();
	int numDisk = n1+n2+n3;

	MyStack<int> tmp1(*peg1);
	MyStack<int> tmp2(*peg2);
	MyStack<int> tmp3(*peg3);

	//plot
	for (int i=0; i<numDisk; i++) {
		//peg1
		if (numDisk-n1-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m1 = tmp1.top();
			tmp1.pop();
			for (int j=0; j<m1; j++)
				cout << "*";
			for (int j=m1; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg2
		if (numDisk-n2-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m2 = tmp2.top();
			tmp2.pop();
			for (int j=0; j<m2; j++)
				cout << "*";
			for (int j=m2; j<numDisk; j++)
				cout << " ";
		}
		cout <<" | ";

		//peg3
		if (numDisk-n3-i>0) {
			for (int j=0; j<numDisk; j++)
				cout << " ";
		}
		else {
			int m3 = tmp3.top();
			tmp3.pop();
			for (int j=0; j<m3; j++)
				cout << "*";
			for (int j=m3; j<numDisk; j++)
				cout << " ";
		}
		cout<<endl;
	}
	for ( int i = 0 ; i < numDisk * 3 + 7; i++)
    {
        cout << "_";
    }
	cout << "\n";
}

// function that moves n disks from the start peg to the destination peg
void Towers::move(int n, MyStack<int>* s, MyStack<int>* t, MyStack<int>* d)
{
    // if there are no disk to move, return
    if ( n == 0 ) return;
    // move n - 1 disks from the start peg to the temporary peg
    move(n - 1, s, d, t);
    // move the largest disk from the start peg to the destination peg
    moveOne(s, d);
    // plot the the pegs
    plotPegs();
    // move the n - 1 disks from the temporary peg to the destination peg
    move(n - 1, t, s, d);
}

// function that moves 1 disk from the start peg to the destination peg
void Towers::moveOne(MyStack<int>* s, MyStack<int>* d)
{
    d->push(s->pop());
}
