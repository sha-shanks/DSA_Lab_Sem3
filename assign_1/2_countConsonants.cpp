#include <iostream>
#include <string>
using namespace std;

bool isCons(char c){
    c = tolower(c);
    return (c >= 'a' && c <= 'z' && c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u');
}

int countCons(const string& str, int index){
    if (index < 0) {
        return 0; // Base case: no consonants found
    }
    return isCons(str[index]) + countCons(str, index - 1);
}

int main(){
    string phrase;
    cout << "Enter a string: ";
    cin >> phrase;

    int totalCons = countCons(phrase, phrase.length() - 1);
    cout << "Teh total num of consonants is: " << totalCons << endl;

    return 0;
}
