#include "iostream"
#include "fstream"
#include "math.h"


using namespace std;

//int main() {
//
//    float deltax, xmin, xmax;
//    const float eps = 0.000001;
//
//    std::cout << "Enter [xmin, xmax]: ";   // интервал
//    std::cin >> xmin >> xmax;
//
//    std::cout << "Enter deltax: ";  // дельта
//    std::cin >> deltax;
//
//    std::ofstream outFile;
//
//    outFile.open("results3.txt");
//
//
//    std::cout << "\tx\t\ty" << std::endl;
//    outFile << "\tx\t\ty" << std::endl;
//
//    std::cout.precision(5);
//    float y;
//    float x = xmin;
//    double cotan;
//    while (x < xmax) {
//        if (fabs(x - 2) < eps) {
//            std::cout << "\t"
//                << x
//                << "\t\t Divide on zero or -deltax- is too low"
//                << std::endl;
//
//            outFile << "\t"
//                << x
//                << "\t\t Divide on zero or -deltax- is too low"
//                << std::endl;
//
//            return 0;
//        }
//        else {
//            cotan = pow(1. / tan((double)x), 2);
//
//            y = sqrt(5 + (3 / x)) + 11 * x + cotan * ((2 * x) + 15);
//             
//
//            std::cout << "\t"
//                << x
//                << "\t\t"
//                << y
//                << std::endl;
//
//            outFile << "\t"
//                << x
//                << "\t\t"
//                << y
//                << std::endl;
//        }
//        x = x + deltax;
//    }
//
//    outFile.close();
//    return 0;
//
//}

//int main() {
//
//	int x, y;
//
//	std::ofstream outFile;
//	outFile.open("results4.txt");
//
//	std::cout.precision(5);
//	std::cout << "Enter x: ";
//    std::cin >> x;
//
//	if (x == 3) {
//		y = 1;
//
//		std::cout << y << std::endl;
//		outFile << y << std::endl;
//
//		return 0;
//
//	}
//	if (x > 3) {
//		
//		y = 5 * x - 10;
//
//		std::cout << y << std::endl;
//		outFile << y << std::endl;
//
//		
//	}
//	if (x < 3) {
//	
//	y = 2 * abs(x) - 5;
//
//	std::cout << y << std::endl;
//	outFile << y << std::endl;
//
//	;
//}
//outFile.close();

//int main (){
//
//	int a, b, c, i;
//
//    std::ofstream outFile;
//	outFile.open("results5.txt");	
//
//	std::cout << "Enter min and max: ";
//	std::cin >> a >> b;
//
//	std::cout << "Enter delta: ";
//	std::cin >> c;
//
//	for (i = 1;i < 2;i++) {
//		std::cout << a << std::endl;
//		outFile << a << std::endl;
//	}
//
//	while (a < b) {
//		a = a + c;
//		std::cout << a << std::endl;
//		outFile << a << std::endl;
//	}
//outFile.close();
//}

//long double fact(int n)
//{
//    if (n < 0) 
//        return 0; 
//    if (n == 0) 
//        return 1;
//    else 
//        return n * fact(n - 1); 
//}
//
//int main()
//{
//    int n;
//    std::ofstream outFile;
//    outFile.open("results6.txt");
//    
//    cout << "number: ";
//    cin >> n;
//    outFile << n << std::endl;
//    cout << "factorial: "  << fact(n) << endl; 
//    outFile << fact(n) << endl;
//    outFile.close();
//    return 0;
//   }


//int main() {
//	
//	std::ofstream outFile;
//	outFile.open("results7.txt");
//	
//	float x, c, y, i;
//	
//
//	std::cout << "Enter x: ";
//	std::cin >> x;
//	std::cout << "Enter predel: ";
//	std::cin >> c;
//	i = 1;
//	y = 0;
//	
//	double sum = 0;
//
//	for (int i = 1; i <= c; i++) {
//	
//		y = 1 / (x * i);
//		sum += y;
//			
//	}
//		std::cout << sum << " ";
//
//	std::cout << std::endl;
//	outFile << sum << std::endl;
//
//	
//	return 0;
//
//	
//	outFile.close();
//}


int main() {

	std::ofstream outFile;
	outFile.open("results8.txt");

	int x, c, y,u ;
	int i;

	std::cout << "Enter x: ";
	std::cin >> x;
	std::cout << "Enter predel: ";
	std::cin >> c;
	
	
	
	double sum = 0;

	for (i = 1; i <= c; i++) {

		if (i % 2 == 0) {
			u = x * i;
			sum = sum - u;
		}
		else {
			u = x * i;
			sum = sum + u;
		}
			
	}
	std::cout << sum << " ";

	std::cout << std::endl;
	outFile << sum << std::endl;
	
	return 0;

	outFile.close();
}