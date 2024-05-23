#include <iostream>
#include <string>
#include <algorithm> // For transform
using namespace std;

// Pstring class 
class Pstring : public string {
public:
    //take string object and pass it to the base class constructor
    Pstring(const string& str) : string(str) {}

    // determine if the string is a palindrome
    bool isPalindrome() {
        // create copy of the string and transform to lower case 
        string s = *this;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        // initialize two indexes
        int start = 0;
        int end = s.length() - 1;

        // compare characters from the start and end towards the center
        while (start < end) {
            if (s[start] != s[end]) {
                return false; // if mismatch, not a palindrome
            }
            start++;
            end--;
        }
        return true; // if matches, palindrome
    }
};

int main() {
    // user enters a string
    cout << "Enter a string: ";
    string userInput;
    getline(cin, userInput);

    // initialize a Pstring object with the user input
    Pstring pstr(userInput);

    // check if it is a palindrome and display the result
    if (pstr.isPalindrome()) {
        cout << "\"" << userInput << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << userInput << "\" is not a palindrome." << endl;
    }

    return 0;
}