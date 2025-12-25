//1. 
#include <iostream>
using namespace std;

void PrimeFactors(int n, int divisor) {
    if (n == 1) {
        return;
    }
    
    if (n % divisor == 0) {
        cout << divisor << " ";
        PrimeFactors(n / divisor, divisor);
    }
    else {
        PrimeFactors(n, divisor + 1);
    }
}

int main() {
    int n;
    cin >> n;
    
    PrimeFactors(n, 2);
    
    return 0;
}