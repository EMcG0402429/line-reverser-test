//Main.cpp
//Main program body thing. This is a useless comment.
//2014 EMcG
//Code Test from Seebs. ~1.5 hours taken.

#include "stdafx.h"
#include "LineReverser.h"

using namespace System;
using namespace std;

int main(array<System::String ^> ^args)
{
	int reverseResult;
	std::string filename;
	// Ask for text file
	cout << "Enter the name of the text file you want reversed\nThis file will be overwritten in reverse order: ";
	cin >> filename;
	cin.ignore();
	// Make a reverser and do the thing
	lineReverser lineRev(filename);
	reverseResult = lineRev.reverseLines();
	// Return results: 0 for fail, 1 for success. I am not sure if this is at all meaningful.
	return reverseResult;
}