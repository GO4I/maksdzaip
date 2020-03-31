
#include "iostream"
#include "stdlib.h"
#include "fstream"


//int main()
//{
//
//    std::ofstream outFile;
//    outFile.open("results(1b).txt");
// 
//
//    const int n = 10;
//    int arr[n];
//
//    srand(10); 
//
//    for (int i = 0; i < n; i++)
//        arr[i] = rand() % 10+10;
//
//
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << ", ";
//        outFile << arr[i] << ", ";
//    }
//    
//    std::cin.get();
//    std::cin.get();
//    
//    return 0;
//    outFile.close();
//}

//int main()
//{
//
//    std::ofstream outFile;
//    outFile.open("results(2f).txt");
//
//
//    const int n = 10;
//    const int x = 8;
//    int y = 0;
//    int sum=0;
//
//    int arr[n];
//    int gar[x];
//  
//    
//
//    srand(10);
//
//    for (int i = 0; i < n; i++)
//        arr[i] = rand() % 10 + 10;
//
//    int size;
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << ", ";
//        outFile << arr[i] << ", ";
//    }
//
//    std::cout << std::endl;
//
//    int temp;
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10 - i - 1; j++) {
//            if (arr[j] > arr[j + 1]) {
//                temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//
//    for (int i = 0; i < 10; i++) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
// 
//    for (int i = 0;i < 3;i++) {
//        sum = sum + arr[i];
//    }
//
//    std::cout << "Sum is: " << sum << std::endl;
//    outFile << "Sum is: " << sum << std::endl;
//
//    std::cin.get();
//    std::cin.get();
//
//       
//    return 0;
//    outFile.close();
//}

//int main()
//{
//
//    std::ofstream outFile;
//    outFile.open("results(2b).txt");
//
//
//    const int n = 10;
//    const int x = 8;
//    int y = 0;
//    int sum = 0;
//
//    int arr[n];
//    int gar[x];
//
//
//
//    srand(10);
//
//    for (int i = 0; i < n; i++)
//        arr[i] = rand() % 10 + 10;
//
//    int size;
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << ", ";
//        outFile << arr[i] << ", ";
//    }
//
//    std::cout << std::endl;
//
//    int temp;
//    for (int i = 0; i < 10; ++i)
//    {
//        for (int r = 0; r < 10 - i; r++)
//        {
//            if (arr[r] < arr[r + 1])
//            {
//                // Обмен местами
//                int temp = arr[r];
//                arr[r] = arr[r + 1];
//                arr[r + 1] = temp;
//            }
//        }
//    }
//
//    for (int i = 0; i < 10; i++) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    for (int i = 0;i < 7;i++) {
//        sum = sum + arr[i];
//    }
//
//    
//    std::cout << "Sum is: " << sum << std::endl;
//    outFile << "Sum is: " << sum << std::endl;
//
//    std::cin.get();
//    std::cin.get();
//
//
//    return 0;
//    outFile.close();
//}
//
int main()
{

    std::ofstream outFile;
    outFile.open("results(4).txt");


    const int n = 10;
    const int x = 8;
    int y = 0;
    long long sum = 1;

    int arr[n];
    int gar[x];



    srand(10);

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10 + 10;

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ", ";
        outFile << arr[i] << ", ";
    }

    std::cout << std::endl;

    

    for (int i = 0;i < 10;i++) {
        sum = sum * arr[i];
        std::cout << sum << std::endl;
    }


    std::cout << "Proizvedenie is: " << sum << std::endl;
    outFile << "Proizvedenie is: " << sum << std::endl;

    std::cin.get();
    std::cin.get();


    return 0;
    outFile.close();
}