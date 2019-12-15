//-------------------------------------------------------- Include système
using namespace std;
#include <string>
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Validation.h"

Validation::Validation()
// Algorithme :
//
{

} //----- Fin de Validation


Validation::~Validation()
// Algorithme :
//
{

} //----- Fin de ~Validation


void Validation::checkImplicants(vector<string> ddt, vector<string> implicants, char unknownBitValue)
// Algorithme :
//
{
	//part one, check for each implicant if there is a in-out tuple
	//for all possible combinations
	cout << endl << "--------------------Test phase one : eache implicant has all tuples------------------" << endl << endl;
	int incompletImplicants = 0;
	for (string implicant : implicants)
	{
		int combinationsCounter = 0;
		for (char bit : implicant)
		{
			if (bit == unknownBitValue)
			{
				combinationsCounter++;
			}
		}
		combinationsCounter = pow(2, combinationsCounter);
		vector<string>::iterator it = ddt.begin();
		for (it; it != ddt.end();it++)
		{
			if (checkTupleToImplicant(*it, implicant, unknownBitValue))
			{
				combinationsCounter--;
			}
			
			if (combinationsCounter == 0)
			{
				//in the case of non-redundancy
				//it = ddt.erase(it);
				break;
			}
			/*else
			{
				it++;
			}*/
		}
		if (combinationsCounter != 0)
		{
			cout << "error : after first test on " + implicant + " left " << combinationsCounter <<  " tuples" << endl;
			incompletImplicants++;
		}
	}

	//part two, check for all the tuples that rest if there are an implicant
	cout << endl << "--------------------Test phase two : eache tuple match an implicant------------------" << incompletImplicants << endl << endl;
	vector<string>::iterator itTuple = ddt.begin();
	for (itTuple; itTuple != ddt.end(); )
	{
		bool isValidated = false;
		for (string implicant : implicants)
		{
			if (checkTupleToImplicant(*itTuple, implicant, unknownBitValue))
			{
				itTuple = ddt.erase(itTuple);
				isValidated = true;
				break;
			}
		}
		if (!isValidated)
		{
			itTuple++;
		}
	}
	if (ddt.size() != 0)
	{
		cout << "----------------------second phase error------------------" << ddt.size() << endl << endl;
		for (string tuple : ddt)
		{
			cout << "tuple " + tuple << " dont have any implicant" << endl;
		}
	} 
	else
	{
		cout << "\t Test passed with success :=)" << endl;
	}
	system("PAUSE");
}


bool Validation::checkTupleToImplicant(string tuple, string implicant, char unknownBit)
// Algorithme :
//
{
	for (int charIndex(0); charIndex < implicant.size(); charIndex++)
	{
		if (tuple[charIndex] != implicant[charIndex] && implicant[charIndex] != unknownBit)
		{
			return false;
		}
	}
	return true;
}

