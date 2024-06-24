
#include <math.h>
using namespace std;

double fx(double x) {

		if (1 < x && x <= 3) {
			return sqrt(exp(sin(x) * sin(x) * sin(x))) + 4 * log(5) * x + (1.0 / 12.0);
		}
		else if (-2 < x && x < -1) {
			return pow(x, 30);
		}
		else {
			return pow(x, -10);
		}
}