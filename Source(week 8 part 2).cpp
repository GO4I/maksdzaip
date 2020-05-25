#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>


using namespace std;


struct Plane {
    string number;
    int age;
    float price;
};

struct Shoe {
    string serial;
    int years;
    float cost;
};

void randString(string& str) {
    static const char alphabet[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
    str = "        ";


    for (int i = 0; i < str.length(); i++) {
        int r = rand() % (sizeof(alphabet) - 1);
        str[i] = alphabet[r];
    }
    str[str.length()] = 0;
}


void showPlanes(const Plane s) {
    cout << s.number << "\t"
        << s.age << "\t"
        << s.price << endl;
}

void showShoes(const Shoe s) {
    cout << s.serial << "\t"
        << s.years << "\t"
        << s.cost << endl;
}

int findPlanesPrice(const Plane s[], const int l, const float key) {
    int count = 0;
    for (int i = 0; i < l; i++) {
        if (s[i].price > key) {
            showPlanes(s[i]);
            count++;
        }
    }
    return count;
}

int findShoesCost(const Shoe s[], const int l, const float key) {
    int count = 0;
    for (int i = 0; i < l; i++) {
        if (s[i].cost > key) {
            showShoes(s[i]);
            count++;
        }
    }
    return count;
}

void bubbleSort(Plane data[], int len) {
    Plane tmp;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j >= i + 1; j--) {
            if (data[j].price < data[j - 1].price) {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
}

void bubbleSortShoes(Shoe data[], int len) {
    Shoe tmp;
    for (int i = 0; i < len; i++) {
        for (int j = len - 1; j >= i + 1; j--) {
            if (data[j].cost < data[j - 1].cost) {
                tmp = data[j];
                data[j] = data[j - 1];
                data[j - 1] = tmp;
            }
        }
    }
}

void write2File(const Plane s[], const int l) {
    ofstream f;
    f.open("data.txt");


    for (int i = 0; i < l; i++)
        f << s[i].number << "\t"
        << s[i].age << "\t"
        << s[i].price << endl;
    f.close();

}

void write2FileShoes(const Shoe s[], const int l) {
    ofstream f;
    f.open("data.txt");


    for (int i = 0; i < l; i++)
        f << s[i].serial << "\t"
        << s[i].years << "\t"
        << s[i].cost << endl;
    f.close();

}

int main() {
    const int len = 20;
    Plane planes[len];
    Shoe shoes[len];

    for (int i = 0; i < len; i++) {
        planes[i].age = rand() % 50;
        planes[i].price = 500000.0 * (float)rand() / RAND_MAX;
        randString(planes[i].number);
        showPlanes(planes[i]);
    }

    float avg_mark = 250000.0;
    cout << endl << "Find all who more than " << avg_mark << endl;
    int findCount = findPlanesPrice(planes, len, avg_mark);
    cout << "Total " << findCount << " elements" << endl;


    cout << endl << "Sorted planes" << endl;
    bubbleSort(planes, len);


    for (int i = 0; i < len; i++)
        showPlanes(planes[i]);


    write2File(planes, len);

    for (int i = 0; i < len; i++) {
        shoes[i].years = rand() % 5;
        shoes[i].cost = 500.0 * (float)rand() / RAND_MAX;
        randString(shoes[i].serial);
        showShoes(shoes[i]);
    }

    float avg_price = 250.0;
    cout << endl << "Find all shoes, which price is more than " << avg_price << endl;
    int findShoesCount = findShoesCost(shoes, len, avg_price);
    cout << "Total " << findShoesCount << " elements" << endl;

    cout << endl << "Sorted shoes" << endl;
    bubbleSortShoes(shoes, len);


    for (int i = 0; i < len; i++)
        showShoes(shoes[i]);


    write2FileShoes(shoes, len);


    return 0;
}
