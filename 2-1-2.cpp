//2. Дано слово, состоящее только из строчных латинских букв. Проверьте, является ли это слово палиндромом. Выведите YES или NO. При решении этой задачи нельзя пользоваться циклами, в решениях на питоне нельзя использовать срезы с шагом, отличным от 1.
#include <iostream>
using namespace std;

bool isPalindrome(char s[], int left, int right) {
    if (left >= right) {
        return true;
    }
    
    if (s[left] != s[right]) {
        return false;
    }
    
    return isPalindrome(s, left + 1, right - 1);
}

int getLength(char s[], int index) {
    if (s[index] == '\0') {
        return index;
    }
    return getLength(s, index + 1);
}

int main() {
    char word[1000];
    cin >> word;
    
    int len = getLength(word, 0);
    
    if (isPalindrome(word, 0, len - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}