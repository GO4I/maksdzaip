#include "iostream"
#include "iomanip"
#include "math.h"
#include "fstream"
#include "string"

using namespace std;

//int main() {
//
//    void basicFileWrite();
//
//    std::ofstream outFile;
//    outFile.open("results1.txt");
//
//    for (int i = 1; i < 25; i++) {
//        for (int j = 0; j < i; j++) {
//
//
//          
//           std::cout << 0;
//           outFile << 0;
//        }
//        std::cout << std::endl;
//        outFile << std::endl;
//    }
//
//    std::cout << std::endl;
//    outFile.close();
//
//    std::getchar();  
//    std::getchar();  
//    return 0;
//
//
//}


    int main() {

        float deltax, xmin, xmax;
        const float eps = 0.000001;  

        std::cout << "Enter [xmin, xmax]: ";   // интервал
        std::cin >> xmin >> xmax;

        std::cout << "Enter deltax: ";  // дельта
        std::cin >> deltax;

        std::ofstream outFile;

        outFile.open("results2.txt");

        
        std::cout << "\tx\t\ty" << std::endl;
        outFile << "\tx\t\ty" << std::endl;

        std::cout.precision(5);
        float y;
        float x = xmin;
        while (x < xmax) {
            if (fabs(x-2) < eps) {
                std::cout << "\t"
                    << x
                    << "\t\t Divide on zero or -deltax- is too low"
                    << std::endl;

                outFile << "\t"
                    << x
                    << "\t\t Divide on zero or -deltax- is too low"
                    << std::endl;

                return 0;
            }
            else {
                y = (-0.1*(x*x))+(2*x)+1 ;

                std::cout << "\t"
                    << x 
                    << "\t\t"
                    << y
                    << std::endl;

                outFile << "\t"
                    << x
                    << "\t\t"
                    << y
                    << std::endl;
            }
            x = x + deltax;
        }

        outFile.close();
        return 0;

    }



