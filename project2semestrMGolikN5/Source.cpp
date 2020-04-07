#include "iostream"
#include "fstream"

using namespace std;

//int main()
//{
//
//    ofstream outFile;
//    outFile.open("results(3).txt");
//
//
//    const int n = 10;
//    int arr[n];
//    int chet, nechet;
//
//    srand(10);
//
//    for (int i = 0; i < n; i++)
//        arr[i] = rand() % 10 + 10;
//
//
//    chet = 0;
//    nechet = 0;
//
//    for (int i = 0; i < n; i++) {
//       cout << arr[i] << ", ";
//       outFile << arr[i] << ", ";
//
//       if (arr[i] % 2) {
//         nechet = nechet + arr[i];
//       }
//       else {
//         chet = chet + arr[i];
//       }
//       
//    }
//    
//    cout << endl;
//
//    cout << "Chetniy: " << chet << endl;
//    outFile << chet << ", " << endl;
//    cout << "Nechetniy: " << nechet << endl;
//    outFile << nechet << ", " << endl;
//
//    cin.get();
//    cin.get();
//    
//    return 0;
//    outFile.close();
//}

//int main()
//{
//
//    ofstream outFile;
//    outFile.open("results(9).txt");
//
//
//    const int n = 10;
//    int arr[n];
//    int chet, nechet;
//    int negative, positive;
//    negative = 0;
//    positive = 0;
//
//    srand(10);
//
//    for (int i = 0; i < n; i++)
//        arr[i] = rand() % 20-10;
//
//    for (int i = 0; i < n; i++) {
//       cout << arr[i] << ", ";
//       outFile << arr[i] << ", ";
//
//       if (arr[i] > 0) {
//           positive = positive + 1;
//       }
//       else {
//           negative = negative + 1;
//       }
//    }
//    cout << endl;
//    
//    cout << "More than 0: " << positive << endl;
//    outFile << "More than 0; " << positive << endl;
//    cout << "Less than 0: " << negative << endl;
//    outFile << "Less than 0: " << negative << endl;
//
//    cin.get();
//    cin.get();
//    
//    return 0;
//    outFile.close();
//}

//int main()
//{
//
//    ofstream outFile;
//    outFile.open("results(11).txt");
//
//
//    const int n = 10;
//    int arr[n];
//    int chet, nechet;
//    float mid, arifm;
//    int negative, positive;
//    mid = 0;
//    negative = 0;
//    positive = 0;
//    arifm = 0;
//
//    srand(10);
//
//    for (int i = 0; i < n; i++)
//        arr[i] = rand() % 20 - 10;
//
//    for (int i = 0; i < n; i++) {
//        cout << arr[i] << ", ";
//        outFile << arr[i] << ", ";
//
//        mid = mid + arr[i];
//        arifm = mid / n;               
//    }
//
//    cout << endl;
//
//    cout << "Srednee arifm is: " << arifm << endl;
//    outFile << "Srednee arifm is: " << arifm << endl;
//
//    cout << endl;
//
//    for (int i = 0; i < n; i++) {
//        if (arr[i] < arifm)
//            cout << arr[i] << " is lower than srednee arifm." << endl;
//            outFile << arr[i] << " is lower than srednee arifm." << endl;
//    }
//    
//    cin.get();
//    cin.get();
//
//    return 0;
//    outFile.close();
//}

int main()
{

    ofstream outFile;
    outFile.open("results(14b).txt");


    const int n = 10;
    int arr[n];
    

    srand(10);

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 20 - 10;

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
        outFile << arr[i] << ", ";
    }
  
    cout << endl;
    
    int min_number = 15;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            if (min_number > arr[i])
                min_number = arr[i];
        }
    }

    cout << "Minimum of array is " << min_number << endl;
    outFile << "Minimum of array is " << min_number << endl;

    return 0;
    outFile.close();
}