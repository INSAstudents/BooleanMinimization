#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <ilcplex/ilocplex.h>
#include "PrimeImplFromCplex.h"

ILOCONTINUOUSCALLBACK1(dataCallBack,
	IloNum, timeStart)
{
	if (isFeasible())
	{
		std::cout << "Best Value : " << getObjValue() << "  Duration : " << getCplexTime() - timeStart << std::endl;
	}
}

void run_Cplex(std::string fileName)
{
	IloEnv env;

	try {
		IloModel model(env);
		IloCplex cplex(env);

		IloObjective   obj;
		IloNumVarArray var(env);
		IloRangeArray  rng(env);

		cplex.use(dataCallBack(env, cplex.getCplexTime()));
		cplex.importModel(model, fileName.c_str(), obj, var, rng);

		cplex.extract(model);
		
		if (!cplex.solve()) {
			env.error() << "Failed to optimize LP model : " << fileName << std::endl;
			return;
		}
		std::string solutionFileName = "cplexSolutions/cplexSolution" + fileName.substr(0, fileName.size() - 3) + ".txt";
		std::string PrimeImplicantFileName = "cplexSolutions/PrimeImpl" + fileName.substr(0, fileName.size() - 3) + ".txt";
		cplex.writeSolution(solutionFileName.c_str());
		writePrimeImplicantsFromCplex(solutionFileName, PrimeImplicantFileName);
	}
	catch (IloException& e) {
		std::cerr << "C-Exp: " << e << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown Exception" << std::endl;
	}
	env.end();
}
