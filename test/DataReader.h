#pragma once
#ifndef DATAREADER_H
#define DATAREADER_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include <string>
#include <fstream>

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <DataReader>
//
//
//------------------------------------------------------------------------

class DataReader
{
	//----------------------------------------------------------------- PUBLIC

public:
	//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste de paramètres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	DataReader();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~DataReader();
	// Mode d'emploi :
	//
	// Contrat :
	//

	//------------------------------------------------------------------ PRIVE

	vector<string> loadDDT(string fileName, string separator);
	// Mode d'emploi :
	//
	// Contrat :
	//

	vector<string> loadImplicants(string fileName, bool isInverted = false);
	// Mode d'emploi :
	//
	// Contrat :
	//

};

#endif