// LineReverser.cpp
// A Thing for Reversing Line Order from a text file.
// 2014 EMcG
// Code Test from Seebs. ~1.5 hours taken.

#include "stdafx.h"
#include <fstream>
#include <vector>
#include "LineReverser.h"

using namespace std;

lineReverser::lineReverser(std::string fileConst){ //Passed filename on construction
	filename = fileConst;
}

int lineReverser::countLines() //Get the number of lines in a file
{
	int numLines = 0;
	std::string line;
	ifstream fileToCount(filename);
	while (getline(fileToCount, line))
	{
		numLines++;
	}
	fileToCount.close();
	return numLines;
}

int lineReverser::reverseLines()
{
	// Get text file
	ifstream fileIn(filename);
	if (!fileIn.is_open())
	{
		//File failed to open
		cout << "File failed to open\nPress any key to continue\n";
		cin.get();
		return 0;
	}
	else
	{
		//File exists. Get how many lines there are in the text file
		int numLines;
		int i = 0;
		numLines = countLines();
		cout << numLines << " lines in file\n";

		//Make an array of string to hold the file
		std::vector<std::string> lineArray(numLines + 1);
		//Getline into the array backwards
		for (i = 1; i <= numLines; i++){
			getline(fileIn, lineArray[numLines - i]);
			//cout << "Reading line " << i << " to array index " << (numLines - i) << "\n"; //Debuggery
		}
		fileIn.close();
		//Write array to output file
		ofstream fileOut(filename);
		for (i = 0; i < numLines; i++)
		{
			fileOut << lineArray[i] << "\n";
			//cout << "Writing line " << i << " from array index " << i << "\n"; //Debuggery
		}
		fileOut.close();
		lineArray.clear();
	}
	cout << "File reversed into " << filename << "\n";
	cout << "Press any key to continue\n";
	cin.get();
	return 1;
}