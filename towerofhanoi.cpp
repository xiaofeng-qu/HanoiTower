// Xiaofeng Qu xq6@zips.uakron.edu
// towerofhanoi.cpp : Defines the entry point for the console application.
//DO NOT MODIFY THIS FILE

#include <iostream>
#include "towers.h"

using namespace std;

int main()
{
	int numDisk = 10;
	Towers t(numDisk);
	t.start();
	return 0;
}

