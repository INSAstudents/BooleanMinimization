#include "stats.h"
#include <iostream>
#include <fstream>
#include <time.h>

time_t Stats::startChrono;
time_t Stats::endChrono;
time_t Stats::executionTime;

std::string Stats::sbox = "unknown";
std::string Stats::algo = "unknown";
std::string Stats::probability = "unknown";
size_t Stats::inSize = 0;
size_t Stats::outSize = 0;
SolutionState Stats::state = SolutionState::NONE;

std::unordered_map<std::string, std::pair<time_t, time_t>> Stats::timeCuts;

void Stats::initChrono()
{
	
	startChrono = clock();
}

void Stats::closeChrono()
{
	endChrono = clock();
	executionTime = endChrono - startChrono;
}

void Stats::setChronoWithIndex(std::string index, ClockState state)
{
	if (state == ClockState::START)
	{
		timeCuts[index].first = clock();
		timeCuts[index].second = NULL;
	}

	else if (state == ClockState::END)
	{
		timeCuts[index].second = clock();
		if (timeCuts[index].first == NULL)
		{
			timeCuts[index].first = startChrono;
		}
	}
}


void Stats::writeStats()
{
	if (executionTime == 0)
	{
		executionTime = clock() - startChrono;
	}
	//create stats line information
	std::string statLine = sbox + " " + probability + " " + algo + " " + std::to_string(inSize) + " " + std::to_string(outSize) + " " + std::to_string(executionTime);
	switch (state)
	{
	case OPTIMAL:
		statLine = statLine + " " + "OPTIMAL";
		break;
	case FEASIBLE:
		statLine = statLine + " " + "FEASIBLE";
		break;
	case INFEASIBLE:
		statLine = statLine + " " + "INFEASIBLE";
		break;
	case NONE:
		break;
	case ERROR:
		statLine = statLine + " " + "ERROR";
		break;
	default:
		break;
	}

	statLine += "\n";

	//check if file exist
	std::ifstream inFile("stats.txt");
	bool isFileExist = inFile.good();
	inFile.close();

	//beggining of writing 
	std::ofstream statsFile("stats.txt", std::ios::app);

	if (!statsFile)
	{
		std::cerr << "ERROR during stats.txt file writing" << std::endl;
	}

	//Write the header if file doesn't exist
	if (!isFileExist)
	{
		statsFile << "Sbox " << "Probability " << "Algorithm " << "SystemSizeIn " << "SystemSizeOut " << "Duration " << "[SOLUTION STATUS]" << std::endl;
	}

	statsFile << statLine;

	std::unordered_map<std::string, std::pair<time_t, time_t>>::iterator it = timeCuts.begin();
	for (it; it != timeCuts.end(); it++)
	{
		time_t start = it->second.first;
		time_t end = it->second.second;
		statsFile << "\t" << it->first << " : " << std::to_string(end - start) << std::endl;
	}

	timeCuts.clear();
}

void Stats::setSboxName(std::string pSbox)
{
	sbox = pSbox;
}

void Stats::setProbability(std::string pProbability)
{
	probability = pProbability;
}

void Stats::setAlgo(std::string pAlgo)
{
	algo = pAlgo;
}

void Stats::setInSize(size_t pInSize)
{
	inSize = pInSize;
}

void Stats::setOutSize(size_t pOutSize)
{
	outSize = pOutSize;
}

void Stats::setSolutionState(SolutionState pState)
{
	state = pState;
}
