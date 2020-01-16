#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename type>
void run_Cplex(string fileName)
{
	IloEnv env;

	try {
		IloModel model(env);
		IloCplex cplex(env);

		IloObjective   obj;
		IloNumVarArray var(env);
		IloRangeArray  rng(env);
		cplex.importModel(model, fileName, obj, var, rng);

		cplex.extract(model);
		if (!cplex.solve()) {
			env.error() << "Failed to optimize LP model : " << fileName << endl;
			return
		}

		if (cplex.getStatus() == IloAlgorithm::Optimal) {
			IloNumArray vals(env);
			cplex.getValues(vals, var);
			env.out() << "Solution status = " << cplex.getStatus() << endl;
			env.out() << "Solution value  = " << cplex.getObjValue() << endl;
			env.out() << "Solution vector = " << vals << endl;
		}
	}
	catch (IloException& e) {
		cerr << "C-Exp: " << e << endl;
	}
	catch (...) {
		cerr << "Unknown Exception" << endl;
	}

	const string str = logfile.str();
	cout << str << endl;
	env.end();
}
