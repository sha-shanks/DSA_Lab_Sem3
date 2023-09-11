#include <iostream>
using namespace std;

bool isPalindrome(int a){
    int rev = 0;
    int temp, n = a;

    while(n!=0){
        temp = n % 10;
        rev = (rev*10) + temp;
        n /= 10;
    }

    if(a == rev){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int num;
    cout << "Enter the number to be checked for palindrome: ";
    cin >> num;

    if(isPalindrome(num)){
        cout << num << " is a palindrome!" << endl;
    }
    else{
        cout << num << " is not a palindrome." << endl;
    }
}