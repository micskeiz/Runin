#include <cmath>
#include "critical_field.h"

double e3 = pow(ITM_QE, 3);
double pi_e02_me_4_c2 = ITM_PI * pow(ITM_EPS0, 2) * ITM_ME * 4.0 * pow(ITM_C, 2);

bool is_field_critical(profile pro) {

	for (std::vector<cell>::iterator it = pro.begin(); it != pro.end(); ++it) {
		if (calculate_critical_field(it->electron_density, it->electron_temperature)
				< it->electric_field)
			return true;
	}

	return false;
}

double calculate_critical_field(double electron_density, double electron_temperature) {

	double coulomb_log = 23.5 - log(sqrt(electron_density) * pow(electron_temperature, -1.25))
			- sqrt(10e-5 + pow((log(electron_temperature) - 2.0), 2) / 16.0);

	return electron_density * e3 * coulomb_log / pi_e02_me_4_c2;
}
