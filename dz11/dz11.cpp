// dz11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Stor 31- 32

#include <iostream>
using namespace std;

int getNumberOfStars(const char* str) {
    int n = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '*') {
            n++;
        }
    }
    return n;
}

int main() {
    const char* str = "Hello*world*!";
    int numStars = getNumberOfStars(str);
    cout << "Number of stars: " << numStars << endl;
    return 0;
}


//Stor 32 -33

#include <iostream>
#include <cstring>
using namespace std;

int getLengthOfFirstWord(const char* str) {
    int spaceInd = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ' ') {
            spaceInd = i;
            break;
        }
    }
    return spaceInd;
}

int getLengthOfLastWord(const char* str) {
    int spaceInd = 0;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == ' ') {
            spaceInd = i;
            break;
        }
    }
    return strlen(str) - spaceInd - 1;
}

int main() {
    const char* str = "Hello world! This is a test.";
    int lenFirstWord = getLengthOfFirstWord(str);
    int lenLastWord = getLengthOfLastWord(str);
    cout << "Length of first word: " << lenFirstWord << endl;
    cout << "Length of last word: " << lenLastWord << endl;
    return 0;
}

//Stor 37 -38

#include <iostream>
#include <cstring>
using namespace std;

int checkUserLevel(const char* login, const char* adminLog, const char* standardLog) {
    if (strcmp(login, adminLog) == 0) {
        return 1; // Admin
    }
    else if (strcmp(login, standardLog) == 0) {
        return 0; // Standard user
    }
    else {
        return -1; // Wrong login
    }
}

int main() {
    const int n = 50;
    const char* adminLog = "admin";
    const char* standardLog = "user";

    char* login = new char[n];
    cout << "Input login: ";
    cin.getline(login, n);

    int m = strlen(login);
    char* tempLog = new char[m];
    strcpy(tempLog, login);

    if (checkUserLevel(tempLog, adminLog, standardLog) == 1) {
        cout << "Welcome, admin!" << endl;
    }
    else if (checkUserLevel(tempLog, adminLog, standardLog) == 0) {
        cout << "Welcome, user!" << endl;
    }
    else {
        cout << "Wrong login!" << endl;
    }

    delete[] login;
    delete[] tempLog;

    return 0;
}

//2.	Дано рядок.Перевірити, чи є він паліндромом

#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - i - 1]) {
            return false; 
        }
    }
    return true; 
}

int main() {
    const char* str1 = "abba";
    const char* str2 = "tenet";
    const char* str3 = "some";

    cout << "Is 'abba' a palindrome? " << boolalpha << isPalindrome(str1) << endl;
    cout << "Is 'tenet' a palindrome? " << boolalpha << isPalindrome(str2) << endl;
    cout << "Is 'some' a palindrome? " << boolalpha << isPalindrome(str3) << endl;

    return 0;
}

//Zawdannia 3

#include <iostream>
#include <string>

using namespace std;

string decrypt_cesar_cipher(string ciphertext, int k) {
    string plaintext = "";

    for (char& c : ciphertext) {
        if (isupper(c)) { 
            c = 'A' + (c - 'A' - k + 26) % 26; 
        }
        plaintext += c; 
    }

    return plaintext;
}

int main() {
    string ciphertext;
    int k;

    
    cout << "Enter the encrypted text: ";
    cin >> ciphertext;
    cout << "Enter the value of K: ";
    cin >> k;

    
    cout << "Decrypted text: " << decrypt_cesar_cipher(ciphertext, k) << endl;

    return 0;
}

//Zavdannia 5

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

pair<int, int> findTreasureCoordinates() {
    int x = 0, y = 0; 

    string direction;
    int steps;

    while (true) {
        cin >> direction;
        if (direction == "Stop") break; 

        cin >> steps;

        
        if (direction == "North") {
            y += steps;
        }
        else if (direction == "South") {
            y -= steps;
        }
        else if (direction == "East") {
            x += steps;
        }
        else if (direction == "West") {
            x -= steps;
        }
    }

    return make_pair(x, y);
}

int main() {
    pair<int, int> treasureCoordinates = findTreasureCoordinates();
    cout << "[" << treasureCoordinates.first << ", " << treasureCoordinates.second << "]" << endl;

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
