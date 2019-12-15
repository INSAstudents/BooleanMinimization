#pragma once
#ifndef VALIDATION_H
#define VALIDATION_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataReader>
//
//
//------------------------------------------------------------------------

class Validation
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	Validation();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Validation();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

	void checkImplicants(vector<string> ddt, vector<string> implicants, char unknownBitValue);
	// Mode d'emploi :
	//
	// Contrat :
	//

private:

	//----------------------------------------------------- Méthodes privées
	bool checkTupleToImplicant(string tuple, string implicant, char unknownBit);
	// Mode d'emploi :
	//
	// Contrat :
	//
};

#endif