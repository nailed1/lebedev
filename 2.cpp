#include <iostream>
#include <locale.h>
using namespace std;

int main() {
    setlocale(LC_ALL,"Russian");
    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;
    int minBase = 2;
    bool found = false;
    
    for(int base = 2; base <= n; base++) {
        int temp = n;
        bool hasZero = false;
        
        while(temp > 0) {
            int digit = temp % base;
            if(digit == 0) {
                hasZero = true;
                break;
            }
            temp /= base;
        }
        
        if(!hasZero) {
            minBase = base;
            found = true;
            break;
        }
    }
    
    for(int base = 2; base <= minBase; base++) {
        cout << "Основание " << base << ": ";
        int digits[100];
        int count = 0;
        int temp = n;
        
        if(temp == 0) {
            digits[0] = 0;
            count = 1;
        } else {
            while(temp > 0) {
                digits[count++] = temp % base;
                temp /= base;
            }
        }

        bool containsZero = false;
        for(int i = count - 1; i >= 0; i--) {
            cout << digits[i];
            if(digits[i] == 0) containsZero = true;
        }
        
        if(containsZero) {
            cout << " (содержит 0)";
        } else {
            cout << " (не содержит 0)";
        }
        cout << endl;
    }

    cout << "В системе с основанием " << minBase << " число " << n << " не содержит нулей" << endl;
    
    return 0;
}