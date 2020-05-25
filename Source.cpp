#include "iostream"
#include "fstream"
#include "stdlib.h"
#include "time.h"

int main() {

	std::ofstream outFile;
	outFile.open("results(1b).txt");
	using namespace std;


	const int n = 5000;
	int arr[n];
	int counter = 0;

	struct Plane {
		string number;
		int age;
		float price;
	};
	

	srand(time(NULL));

	for (int i = 0; i < n; i++)
		arr[i] = (float)rand() / RAND_MAX * (20+10) - 10;
	cout.precision(3);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ", ";
		outFile << arr[i] << ", ";
	}
	
	int j = 0;
	float tmp = 0;
	int len = n;

	for (int i = 0; i < len; i++) {
		// ищем номер наименьшего элемента среди элементов от i-го до конца
		j = i;


		for (int k = i; k < len; k++) {
			if (arr[j] > arr[k]) {
				j = k;
				counter++;
			}
		}
		// меняем местами наибольший элемент и текущий
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}


	/*int j = 0;
	float tmp = 0;
	int len = n;

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
	}*/
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
	
	// 100 - 251 сортировка, 500 - 1443, 1000 - 2879 2500 - 7435 5000 - 14683 сортировка вставками
	std::cin.get();
	std::cin.get();

	return 0;
	outFile.close();
}