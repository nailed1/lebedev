#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    char isbn[11];
    cout << "Введите 10 цифр ISBN: ";
    cin >> isbn;
    
    int len = 0;
    while(isbn[len] != '\0') len++;
    
    if(len != 10) {
        cout << "Ошибка: ISBN должен содержать 10 цифр" << endl;
        return 1;
    }
    
    int sum = 0;
    int coefficient = 10;
    
    for(int i = 0; i < 10; i++) {
        if(isbn[i] >= '0' && isbn[i] <= '9') {
            int digit = isbn[i] - '0';
            sum += digit * coefficient;
            coefficient--;
        } else {
            cout << "Ошибка: ISBN должен содержать только цифры" << endl;
            return 1;
        }
    }
    
    int remainder = sum % 11;
    
    cout << "Контрольная сумма: " << sum << endl;
    cout << "Остаток от деления на 11: " << remainder << endl;
    
    if(remainder == 0) {
        cout << "ISBN правильный" << endl;
    } else {
        cout << "ISBN неправильный" << endl;
    }
    
    return 0;
}