#include <iostream>
using namespace std;

template <typename A>
void swapData(A &m, A &n){
    A temp = m;
    m = n;
    n = temp;
}

int main(){
    float num1, num2;
    char ch1, ch2;

    cout << "Enter the two characters to be swapped: ";
    cin >> ch1 >> ch2;

    cout << "Enter the two numbers to be swapped: ";
    cin >> num1 >> num2;


    cout << "Before swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "ch1 = " << ch1 << ", ch2 = " << ch2 << endl;

    swapData(num1, num2);
    swapData<char>(ch2, ch1);

    cout << endl << "After swapping:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
    cout << "ch1 = " << ch1 << ", ch2 = " << ch2 << endl;

    return 0;
}