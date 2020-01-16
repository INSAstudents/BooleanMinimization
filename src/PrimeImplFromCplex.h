#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

typedef struct {
	std::string name;
	std::string term;
	float value;
} implicant;

std::vector<std::string> split(std::string line)
{
	std::vector<std::string> response;
	int pos = line.find(" ");
	while (pos != -1)
	{
		response.push_back(line.substr(0, pos));
		line.erase(0, pos + 1);
		pos = line.find(" ");
	}
	response.push_back(line);
	return response;
}

std::string replace(std::string &line, char target, char result)
{
	for (int i(0); i < line.size(); i++)
	{
		if (line[i] == target)
			line[i] == result;
	}
	return line;
}

void writePrimeImplicantsFromCplex(std::string fileName, std::string outputFileName)
{
	std::ifstream fileFlow(fileName);
	if (!fileFlow)
	{
		std::cout << "Erreur durant la lecture du fichier" << std::endl;
	}

	std::vector<implicant> implicants;

	int edgeSize = 10;
	std::string line = "";
	while (getline(fileFlow, line))
	{
		if (line.find("variable ") != -1)
		{
			std::vector<std::string> attributs = split(line);
			if (attributs.back().find("reducedCost") != -1)
			{
				edgeSize = 8;
			}
			std::string name;
			float value;
			for (std::string attribut : attributs)
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
			if (value>0)
			{
				implicants.push_back(curImp);
			}
		}

	}

	std::ofstream outFlow(outputFileName);
	if (!outFlow)
	{
		std::cout << "Erreur durant l'écriture de la solution" << std::endl;
	}
	int implicantsSize = implicants.size() - 1;
	int implicantNameSize = implicants[0].name.size();
	for (int i(0); i < implicantsSize; i++)
	{
		outFlow << implicants[i].name.substr(1, implicantNameSize - 2) << " " << implicants[i].value << std::endl;
	}
	outFlow << implicants[implicantsSize].name.substr(1, implicantNameSize - 2) << " " << implicants[implicantsSize].value;
}
