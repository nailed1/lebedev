#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isTenDigit(long long n) {
    return n >= 1000000000LL && n <= 9999999999LL;
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    ifstream file("e2mil.txt");
    
    long long currentNumber = 0;
    int digitCount = 0;
    int position = 0;
    char c;
    
    while (file.get(c)) {
        if (c >= '0' && c <= '9') {
            int digit = c - '0';
            
            if (digitCount < 10) {
                currentNumber = currentNumber * 10 + digit;
                digitCount++;
                
                if (digitCount == 10) {
                    if (isTenDigit(currentNumber) && isPrime(currentNumber)) {
                        cout << "Найдено первое десятизначное простое число!" << endl;
                        cout << "Число: " << currentNumber << endl;
                        cout << "Позиция начала: " << position - 9 << endl;
                        file.close();
                        return 0;
                    }
                }
            } else {
                currentNumber = (currentNumber % 1000000000LL) * 10 + digit;
                
                if (isTenDigit(currentNumber) && isPrime(currentNumber)) {
                    cout << "Найдено первое десятизначное простое число!" << endl;
                    cout << "Число: " << currentNumber << endl;
                    cout << "Позиция начала: " << position - 9 << endl;
                    file.close();
                    return 0;
                }
            }
            
            position++;
        }
    }
    
    file.close();
    
    return 0;
}