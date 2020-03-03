#include "iostream"


/* первое задание*/
int main() {

    std::cout << "**----**" << std::endl;
    std::cout << "***--***" << std::endl;
    std::cout << "***--***" << std::endl;
    std::cout << "**-**-**" << std::endl;
    std::cout << "**-**-**" << std::endl;

    std::getchar();  // ожидание ввода, чтобы прога
    std::getchar();  // не закрывалась после выполнения

    return 0;

}




/* пятая задача 

int main() {
    float n1,n2,n3;
    float num1,num2,num3,num4;

    std::cout << "Number 1: ";
    std::cin >> n1;

    std::cout << "Number 2: ";
    std::cin >> n2;

    std::cout << "Number 3: ";
    std::cin >> n3;

    num1 = (n1*2);
    num2 = (n1/3);
    num3 = (n3*n3);
    num4 = num1+num2+num3;

    std::cout << num1 << "-" << "Number 1" << std::endl;
    std::cout << num2 << "-" << "Number 2" << std::endl;
    std::cout << num3 << "-" << "Number 3" << std::endl;
    std::cout << num4 << "-" << "Summary" << std::endl;

}
*/


/* вторая b задача
int main() {

    float n1, n2, per, squ;

    std::cout << "First: ";
    std::cin >> n1;

    std::cout << "Second: ";
    std::cin >> n2;

    per = 0.5 * (n1 * n2);
    squ = (n1 * n2);

    std::cout << per << "-" << "Perimetr" << std::endl;
    std::cout << squ << "-" << "Square" << std::endl;

}
*/

/* задача 8b

int main() {

    float x,res;

    std::cout << "X: ";
    std::cin >> x;

    res=abs(x) + (x * 5);

    std::cout << res << "-" << "Result" << std::endl;
}

*/


/* конвертер 9b
int main() {

    int x;
    float x1, x2, x3;
    
    std::cout << "Litr-1; Cube-2; Barrel-3,  insert the number you want to use: ";
    std::cin >> x;

    if (x == 1) {

        std::cout << "Amount: ";
        std::cin >> x1;

        std::cout << "In cube " << (x1*0.001) << "   " << "In barrel " << (x1 * 0.006) << std::endl;

    }
    else if (x == 2) {

        std::cout << "Amount: ";
        std::cin >> x2;

        std::cout << "In barrel " << (x2 * 6.28) << "   " << "In litr " << (x2 * 1000) << std::endl;

    }
    else if (x == 3) {

        std::cout << "Amount: ";
        std::cin >> x3;

        std::cout << "In cube " << (x3 * 0.158) << "   " << "In litr " << (x3 * 158.98) << std::endl;


    }

    return 0;
}
*/

/* 11 задача
int main() {

    float n1, n2, n3;
    float num1, num2, num3;

    std::cout << "Number 1: ";
    std::cin >> n1;

    std::cout << "Number 2: ";
    std::cin >> n2;

    std::cout << "Number 3: ";
    std::cin >> n3;

    if (n1 > n2  && n1 > n3) {
        n1 = n1 * 5;

    }
    else if (n2 > n1 && n2 > n3) {
        n2 = n2 * 5;


    }
    else if (n3 > n1 && n3 > n2) {
        n3 = n3 * 5;
    }

    if (n1 < n2&& n1 < n3) {
        n1 = n1 * 3;

    }
    else if (n2 < n1&& n2 < n3) {
        n2 = n2 * 3;


    }
    else if (n3 < n1&& n3 < n2) {
        n3 = n3 * 3;
    }

    std::cout << "Number 1: " << n1 << " Number 2: " << n2 << " Number 3: " << n3 << std::endl;
}
*/