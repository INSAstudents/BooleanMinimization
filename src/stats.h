#pragma once

#include <unordered_map>
#include <ctime>
#include <string>


enum ClockState {START, END};
enum SolutionState {NONE, OPTIMAL, FEASIBLE, INFEASIBLE, ERROR};
class Stats
{
public:
	static void initChrono();
	static void closeChrono();
	static void setChronoWithIndex(std::string index, ClockState state);

	static void writeStats();

	static void setSboxName(std::string pMethode);
	static void setprobability(std::string pProbability);
	static void setAlgo(std::string pAlgo);
	static void setInSize(int pInSize);
	static void setOutSize(int pOutSize);
	static void setSolutionState(SolutionState pState);


private:

	static time_t startChrono;
	static time_t endChrono;
	static time_t executionTime;

	static std::string sbox;
	static std::string probability;
	static std::string algo;
	static int inSize;
	static int outSize;
	static SolutionState state;

	static std::unordered_map<std::string, std::pair<time_t, time_t>> timeCuts;
};