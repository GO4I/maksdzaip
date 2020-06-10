#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <string.h>
#include "time.h"
#include "fstream"

using namespace std;

void TaskTwo() {

    cout << "������ 2. �������� ������ ������� ������� �� ������ ������� � ������." << endl;
    const int n = 4;
    const int m = 4;
    int mat[n][m];
    int k = 0;

    srand(time(NULL));
    for (int i = 0; i < n; i++)    
        for (int j = 0; j < m; j++)
            mat[i][j] = rand() % 28 - 13;

    for (int i = 0; i < n; i++)   
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " \t";
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] * mat[i][1] << "\t";
        cout << endl;
    }
    

}

void TaskFour() {

    cout << "������ 4. � ���������� ������� ����� ����� ������������� ���������, ������� �� � ���� ������� ��������� � ������������� � ������ ��������." << endl;

    const int n = 4;
    const int m = 4;
    int mat[n][m];
    int k = 0;

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = rand() % 28 - 13;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " \t";
        cout << endl;
    }

    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i + 1; j++) {
            if (mat[i][1] > 0)
                count += mat[i][1];
            if (mat[i][3] > 0)
                count += mat[i][3];
        }
           
    cout << "����� ���������: " <<  count << endl;

}

void TaskSeven() {

    cout << "������ 7. ���� �������. �������� ������ ������ � ���������� ������� � ��������������� ����, ������ ������ � ���� ����� � ���� ����. �����, ��� �� � ��� ��� ������? (������ � ����� ����� ������� ����� ��� � ����� ��������� ����)." << endl;

    const int n = 4;
    const int m = 4;
    int mat[n][m];
    int thunderone[m];
    int thundertwo[m];
    int k = 0;

    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = rand() % 28;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " \t";
        cout << endl;
    }

    
    int rain = 0;
    int rainprov = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            for (int j = 0; j < i + 1; j++) {
                if (mat[i][0] > rain) {
                    rain = mat[i][0];
                    thunderone[j] = mat[i][0];
                }
                if (mat[i][2] > rain) {
                    rain = mat[i][2];
                    thunderone[j] = mat[i][2];
                    thunderone[j] = rainprov;
                }
            }
        }
    }

    int wind = 0;
    int windprov = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            for (int j = 0; j < i + 1; j++) {
                if (mat[i][1] > wind) {
                    wind = mat[i][1];
                    thundertwo[j] = mat[i][1];
                    thundertwo[j] = windprov;
                }
                if (mat[i][3] > wind) {
                    wind = mat[i][3];
                    thundertwo[j] = mat[i][3];
                    thundertwo[j] = windprov;
                }
            }

        }
    }
    cout << "�����- " << wind << " ������- " << rain << endl;
    if (windprov = rainprov) {
        cout << "����� ���" << endl;
    }
    else {
        cout << "������ �� ����" << endl;
    }

}
 
void TaskNineB() {
    cout << "������ 9b. ��������, ����������� ���������� ������� � ���������� ��� �� ����� � ������� �� ����� �������, ����������� ��������� ��������. ���������� ���� �������." << endl;
    cout << "��������� ������ �� ��������� �����. ����� ��������������� ������� ������, ��������� ��������." << endl;

    ifstream in("input.txt");

    if (in.is_open())
    {
        int count = 0;
        int temp;

        while (!in.eof())
        {
            in >> temp;
            count++;
        }

        in.seekg(0, ios::beg);
        in.clear();

        int count_space = 0;
        char symbol;
        while (!in.eof())
        {
            in.get(symbol);
            if (symbol == ' ') count_space++;
            if (symbol == '\n') break;
        }
        
        in.seekg(0, ios::beg);
        in.clear();

        int n = count / (count_space + 1);
        int m = count_space + 1;
        double** x;
        x = new double* [n];
        for (int i = 0; i < n; i++) x[i] = new double[m];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                in >> x[i][j];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << x[i][j] << "\t";
            cout << "\n";
        }

        for (int i = 0; i < n; i++) delete[] x[i];
        delete[] x;

        in.close();
    }
    else
    {
        cout << "���� �� ������.";
    }
}

int main() {

    setlocale(LC_ALL, "Russian");

    cout << "����� ������ ���/�-19-1-�" << endl;
    cout << endl;

    TaskTwo();
    cout << endl;
    TaskFour();
    cout << endl;
    TaskSeven();
    cout << endl;
    TaskNineB();

    return 0;
}