//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>

//------------------------------------------------------ Include personnel
#include "DataReader.h"

DataReader::DataReader()
// Algorithme :
//
{

} //----- Fin de DataReader


DataReader::~DataReader()
// Algorithme :
//
{

} //----- Fin de ~DataReader


vector<string> DataReader::loadDDT(string fileName, string separator)
// Algorithme :
//
{
	vector<string> response;
	ifstream ddtFlow(fileName);

	if (!ddtFlow)
	{
		cout << "error during ddt file reading" << endl;
		return response;
	}

	string line;
	int separatorLength = separator.size();
	int counterLigne(0);
	while (getline(ddtFlow,line))
	{
		int separatorPosition = line.find(separator);
		line.erase(separatorPosition, separatorLength);
		line.erase(line.find(" "));
		response.push_back(line);
	}
	return response;
}


vector<string> DataReader::loadImplicants(string fileName, bool isInverted)
// Algorithme :
//
{
	vector<string> response;
	ifstream implicantsFlow(fileName);

	if (!implicantsFlow)
	{
		cout << "error during implicants file reading" << endl;
		return response;
	}

	string line;
	while (getline(implicantsFlow, line))
	{
		if (isInverted)
		{
			string last_line = line.substr(0, line.size() / 2);
			line.erase(0, line.size() / 2);
			line = line + last_line;
		}
		response.push_back(line);
	}
	return response;
}


