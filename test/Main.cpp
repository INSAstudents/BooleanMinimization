#include "DataReader.h"
#include "Validation.h"
#include <iostream>
#include <string>

int main()
{
	string ddtPath;
	string implicantsPath;
	string separator;
	char unknownBitChar;
	string isInvertedAnswer = "n";
	bool isInverted = false;
	
	cout << "set the ddt path..." << endl;
	getline(cin, ddtPath);
	
	cout << "set separator sequence in ddt file..." << endl;
	getline(cin, separator);

	cout << "set implicants file path..." << endl;
	getline(cin, implicantsPath);

	cout << "set is implicant has inverted in/out  [y/n]" << endl;
	getline(cin, isInvertedAnswer);

	cout << "set unknown character in implicants..." << endl;
	cin >> unknownBitChar;

	if (isInvertedAnswer == "y")
	{
		isInverted = true;
	}

	DataReader reader;
	vector<string> ddt = reader.loadDDT(ddtPath, separator);
	vector<string> implicants = reader.loadImplicants(implicantsPath, isInverted);

	Validation validation;
	validation.checkImplicants(ddt, implicants, unknownBitChar);

	return 0;
}