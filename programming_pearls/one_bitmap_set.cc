#include <iostream>
#include <string>
#include<bitset>

using namespace std;

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define N 10000
int arr[1 + N/BITSPERWORD];

// i>>SHIFT == i/32

void set(int i){
    arr[i>>SHIFT] |= (1<<(i & MASK));
}

void clr(int i){
    arr[i>>SHIFT] &= ~(1<<(i & MASK));
}

int test(int i){
    return arr[i>>SHIFT] & (1 << (i & MASK));
}

int main(void){
    set(0);
    set(1);
    set(3);
    set(5);
    set(7);
    set(11);
    set(31);
    set(33);
    std::cout << "size:" << N/BITSPERWORD << std::endl;
    std::cout << "31 hex:" << hex << (31) << std::endl;
    std::cout << "31%32:" << hex << (31/32) << std::endl;
    std::cout << "shift:" << hex << (31>>SHIFT) << std::endl;
    std::cout << "mask:"  << hex << (1<<(31 & MASK)) << std::endl;
    std::cout << "arr[0]:" << hex << arr[0] << std::endl;
    std::cout << "arr[0]:" << (bitset<BITSPERWORD>)arr[0] << std::endl;
    std::cout << "arr[1]:" << hex << arr[1] << std::endl;
    std::cout << "arr[1]:" << (bitset<BITSPERWORD>)arr[1] << std::endl;
    return 0;
}

