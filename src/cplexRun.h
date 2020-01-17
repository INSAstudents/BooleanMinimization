#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <ilcplex/ilocplex.h>
#include "PrimeImplFromCplex.h"
#include "stats.h"

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

		//setup callback for cplex
		//cplex.use(dataCallBack(env, cplex.getCplexTime()));
		cplex.importModel(model, fileName.c_str(), obj, var, rng);
		cplex.setParam(IloCplex::TiLim, 12000);

		cplex.extract(model);
		
		if (!cplex.solve()) {
			env.error() << "Failed to optimize LP model : " << fileName << std::endl;
			Stats::setSolutionState(SolutionState::ERROR);
			return;
		}
		if (cplex.getStatus() == IloCplex::Optimal)
		{
			Stats::setSolutionState(SolutionState::OPTIMAL);
		}
		else if (cplex.getStatus() == IloCplex::Feasible)
		{
			Stats::setSolutionState(SolutionState::FEASIBLE);
		}
		else if (cplex.getStatus() == IloCplex::Infeasible)
		{
			Stats::setSolutionState(SolutionState::INFEASIBLE);
		}
		
		IloNumArray vals(env);
		int counter = 0;
		cplex.getValues(vals, var);
		for (int i(0); i < vals.getSize(); i++)
		{
			if (vals[i] > 0)
			{
				counter++;
			}
		}
		

		std::string solutionFileName = "cplexSolution" + fileName.substr(0, fileName.size() - 3) + ".txt";
		cplex.writeSolution(solutionFileName.c_str());
	}
	catch (IloException& e) {
		std::cerr << "C-Exp: " << e << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown Exception" << std::endl;
	}
	env.end();
	Stats::closeChrono();
	
}
