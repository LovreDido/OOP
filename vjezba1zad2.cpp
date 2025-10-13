#include <iostream>
#include <iomanip>
int preopterecenje(int a, int low = 0, int high = 1000){
	if ( a < low) return low;
	if ( a > high)return high;
	return a;
}
double preopterecenje(double a, double low = 0.0, double high = 1000.0) {
	if (a < low) return low;
	if (a > high)return high;
	return a;
}
int main() {
	std::cout << "za broj 50 :  " << preopterecenje(50) << std::endl; 
	std::cout << "za broj 3 :  " << preopterecenje(3) << std::endl;
	std::cout << "za broj -5 :  " << preopterecenje(-5) << std::endl;
	std::cout << "za broj 1001 :  " << preopterecenje(1001) << std::endl;

	std::cout << "za broj 50.1: " << preopterecenje(50.1) << std::endl;
	std::cout << "za broj 3.0 :  " << preopterecenje(3.0) << std::endl;
	std::cout << "za broj -5.0 :  " << preopterecenje(-5.0) << std::endl;
	std::cout << "za broj 1001.0 :  " << preopterecenje(1001.0) << std::endl;
	return 0;
}