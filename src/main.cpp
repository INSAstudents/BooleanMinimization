
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
typedef struct {
	string name;
	string term;
	float value;
} implicant;

vector<string> split(string line)
{
	vector<string> response;
	int pos = line.find(" ");
	while (pos != -1)
	{
		response.push_back(line.substr(0, pos));
		line.erase(0, pos+1);
		pos = line.find(" ");
	}
	response.push_back(line);
	return response;
}

string replace(string &line, char target, char result)
{
	for (int i(0); i < line.size(); i++)
	{
		if (line[i] == target)
			line[i] == result;
	}
	return line;
}

int main(int argc, const char* argv[])
{
	cout << "Entrez le nom du fichier de solution... " << endl;
	string fileName = "";
	getline(cin,fileName);

	
	ifstream fileFlow(fileName);
	if (!fileFlow)
	{
		cout << "Erreur durant la lecture du fichier" << endl;
	}

	vector<implicant> implicants;
	//unordered_map<string, string> terms;

	int edgeSize = 10;
	string line = "";
	while (getline(fileFlow, line))
	{
		if (line.find("variable ") != -1)
		{
			vector<string> attributs = split(line);
			if (attributs.back().find("reducedCost") != -1)
			{
				edgeSize = 8;
			}
			string name;
			float value;
			for (string attribut : attributs)
			{
				if (attribut.find("name") != -1)
				{
					name = attribut.substr(6, attribut.size() - 7);
				}
				else if (attribut.find("value") != -1)
				{
					value = atof(attribut.substr(7, attribut.size() - edgeSize).c_str());
				}
			}
			implicant curImp;
			curImp.name = name;
			curImp.value = value;
			if(value>0)
			{ 
				implicants.push_back(curImp);
			}
		}

	}

	/*vector<string> termsAssociations = split(line);
	for (int i(0); i < termsAssociations.size(); i++)
	{
		int pos = termsAssociations[i].find("=");
		string name = termsAssociations[i].substr(0, pos);
		string term = termsAssociations[i].substr(pos+1, 17);
		terms[name] = term;
	}*/

	ofstream outFlow("primeImplicantsFromCplex.txt");
	if (!outFlow)
	{
		cout << "Erreur durant l'écriture de la solution" << endl;
	}
	int implicantsSize = implicants.size()-1;
	int implicantNameSize = implicants[0].name.size();
	for (int i(0); i < implicantsSize; i++)
	{
		//outFlow << terms[implicants[i].name] << " " << implicants[i].value << endl;
		outFlow << replace(implicants[i].name.substr(1, implicantNameSize-2), '?', '-') << " " << implicants[i].value << endl;
	}
	outFlow << replace(implicants[implicantsSize].name.substr(1, implicantNameSize - 2), '?', '-') << " " << implicants[implicantsSize].value;
	return 0;
}

