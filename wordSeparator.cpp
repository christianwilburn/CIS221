#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

// Function to convert a camel case sentence to a spaced sentence
string convertSentence(const string& input) {
    string output;
    bool firstWord = true;

    for (size_t i = 0; i < input.size(); ++i) {
        if (isupper(input[i])) {
            if (!firstWord) {
                output += ' '; // add amspace before the new word
            }
            if (firstWord) {
                output += input[i]; // keep first letter of first word uppercase
                firstWord = false;
            } else {
                output += tolower(input[i]); // convert following words first letters to lowercase
            }
        } else {
            output += input[i]; // add the rest of the letters
        }
    }

    return output;
}

int main() {
    // ask the user to enter a camel case sentence
    cout << "Enter sentence without spaces, making the first letter of each word capitalized: ";
    string userInput;
    getline(cin, userInput);

    // convert the sentence
    string result = convertSentence(userInput);

    // display the converted sentence
    cout << "Converted sentence: " << result << endl;

    return 0;
}