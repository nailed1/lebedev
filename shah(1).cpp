#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    setlocale(LC_ALL, "");
    srand(time(NULL));
    
    bool board[64];
    int magic_cell = 12;
    
    cout << "Троль раскладывает монеты...\n";
    for(int i = 0; i < 64; i++) {
        board[i] = rand() % 2;
    }

    cout << "ДОСКА ДО ПЕРЕВОРАЧИВАНИЯ \n";
    for(int i = 0; i < 64; i++) {
        cout << board[i];
        if((i + 1) % 8 == 0) cout << "\n";
    }
    cout << "\n";
    
    cout << "Указанная клетка: " << magic_cell << "\n\n";
    
    int parity = 0;
    for(int i = 0; i < 64; i++) {
        if(board[i]) {
            parity ^= i;
        }
    }
    
    int flip_cell = parity ^ magic_cell;
    
    cout << "Вы переворачиваете монету в клетке: " << flip_cell << "\n";
    board[flip_cell] = !board[flip_cell];
    
    cout << "ДОСКА ПОСЛЕ ПЕРЕВОРАЧИВАНИЯ\n";
    for(int i = 0; i < 64; i++) {
        cout << board[i];
        if((i + 1) % 8 == 0) cout << "\n";
    }
    cout << "\n";

    int new_parity = 0;
    for(int i = 0; i < 64; i++) {
        if(board[i]) {
            new_parity ^= i;
        }
    }
    
    cout << "\nДруг входит и видит доску.\n";
    cout << "Друг определяет клетку как: " << new_parity << "\n";
    
    if(new_parity == magic_cell) {
        cout << "СВОБОДА УРА УРА УРА УРА\n";
    } else {
        cout << "БЭУМ\n";
    }
    
    cout << "\nПроверка: " << parity << " XOR " << magic_cell << " = " << flip_cell << "\n";
    
    return 0;
}
//какое минимальное кол-во действий можно сделать, если троль кузывает 2 клетки (на 1/2 досках)