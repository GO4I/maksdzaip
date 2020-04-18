#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "time.h"

int main() {
	
	    std::ofstream outFile;
	    outFile.open("results(1b).txt");
		using namespace std;
		
	    
	    const int n = 10000;
	    float arr[n];
		int counter = 0;
		void selectionSort();
	
	    srand(time(NULL));
	
	    for (int i = 0; i < n; i++)
	        arr[i] = (float)rand() / RAND_MAX * (1 - 0.2) + 0.2;
		cout.precision(3);
	
	    for (int i = 0; i < n; i++) {
	        std::cout << arr[i] << ", ";
	        outFile << arr[i] << ", ";
	    }

		// сортирока выбором
			int j = 0;
			float tmp = 0;
			int len=n;

			for (int i = 0; i < len; i++) {
				j = i;


				for (int k = i; k < len; k++) {
					if (arr[j] > arr[k]) {
						j = k;
						counter = counter + 1;
					}
				}
				
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				cout << endl;
				std::cout << arr[i] << ", ";
				outFile << arr[i] << ", ";
			}
		/*float tmp = 0;
		int len = n;
		
		for (int i = 0; i < len; i++) {
			for (int j = len - 1; j >= i + 1; j--) {
				if (arr[j] < arr[j - 1]) {  
					tmp = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = tmp;
					counter = counter + 1;
				}
			}
			cout << endl;
			std::cout << arr[i] << ", ";
			outFile << arr[i] << ", ";
		}
		*/
		cout << endl;
		cout << counter << endl;
		// сортировка выбором - 10 элементов: 12,10,15 ходов, одинаково при всех значениях длины
		// 100 - 351; 500 - 2388, 1000 - 5439, 5000 - 35020, 10000 - 78207
		// сортировка пузырьком - 10 элементов: 25,23,26 ходов, одинаково при всех значениях длины 
		// 100-2474 ходов, 500-63640, 1000 - 243819, 5000 - 6275008, 10000 - 24970252
	    // сортировка выбором оказалась гораздо эффективнее сортировки пузырьком
	    std::cin.get();
	    std::cin.get();
	    
	    return 0;
	    outFile.close();
}