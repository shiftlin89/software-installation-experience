#include <casadi/casadi.hpp>
using namespace casadi;

int main()
{
    // // Create scalar/matrix symbols
    // MX x = MX::sym("x",5,1);

    // // Compose into expressions
    // MX y = norm_2(x);

    // // Sensitivity of expression -> new expression
    // MX grad_y = gradient(y,x);

    // // Create a Function to evaluate expression
    // Function f = Function("f",{x},{grad_y});

    // // Evaluate numerically
    // std::vector<DM> grad_y_num = f(DM({1,2,3,4,5}));

            // Create an instance of Opti
        Opti opti;

        // Define decision variables
        MX x = opti.variable();
        MX y = opti.variable();

        // Define the objective function
        MX objective = pow(x - 3, 2) + pow(y + 4, 2);
        opti.minimize(objective);

        // Add a constraint
        opti.subject_to(x + 2*y >= 5);

        // // Choose a solver, e.g., IPOPT, and solve the problem
        
         // Specify IPOPT options
	 casadi::Dict opts;
	 opts["ipopt.print_level"] = 5; // Suppress IPOPT output
	 opts["print_time"] = 0; // Suppress CASAdi solver print
	 opts["ipopt.linear_solver"] = "ma27"; // Set the linear solver to MUMPS
	    
        opti.solver("ipopt",opts);
        OptiSol sol = opti.solve();

        // Retrieve and print the solution
        //double x_sol = sol.value(x);
        //double y_sol = sol.value(y);
        //std::cout << "Solution: x = " << x_sol << ", y = " << y_sol << std::endl;


    // Symbols/expressions
    // MX x = MX::sym("x");
    // MX y = MX::sym("y");
    // MX z = MX::sym("z");
    // MX f = pow(x,2)+100*pow(z,2);
    // MX g = z+pow(1-x,2)-y;

    // MXDict nlp;                 // NLP declaration
    // nlp["x"]= vertcat(x,y,z);   // decision vars
    // nlp["f"] = f;               // objective
    // nlp["g"] = g;               // constraints

    // // Create solver instance
    // Function F = nlpsol("F","ipopt",nlp);

    // // Solve the problem using a guess
    // F(DMDict{{"x0",DM({2.5,3.0,0.75})},{"ubg",0},{"lbg",0}});


    std::cout<<"ssss"<<std::endl;

    return 1;
}

