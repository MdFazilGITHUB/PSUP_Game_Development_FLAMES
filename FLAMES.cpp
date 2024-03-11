#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string getInput(const string& prompt);
char calculateFLAMES(const string& name1, const string& name2);
string getStatusLabel(char relationshipStatus);
void displayResult(char relationshipStatus);

int main() {
    string firstName = getInput("Enter the first name: ");
    string secondName = getInput("Enter the second name: ");

    char relationshipStatus = calculateFLAMES(firstName, secondName);

    displayResult(relationshipStatus);

    return 0;
}

string getInput(const string& prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}

char calculateFLAMES(const string& name1, const string& name2) {
    unordered_map<char, int> letterCounts;

    for (char letter : name1) {
        letterCounts[letter]++;
    }

    for (char letter : name2) {
        letterCounts[letter]--;
    }

    int flamesIndex = 0;
    for (const auto& pair : letterCounts) {
        flamesIndex += abs(pair.second);
    }

    flamesIndex %= 6;
    return "FLAMES"[flamesIndex];
}

string getStatusLabel(char relationshipStatus) {
    switch (relationshipStatus) {
        case 'F': return "Friendship";
        case 'L': return "Love";
        case 'A': return "Affection";
        case 'M': return "Marriage";
        case 'E': return "Enemies";
        case 'S': return "Siblings";
        default: return "Unknown";
    }
}

void displayResult(char relationshipStatus) {
    cout << "Relationship Status: " << getStatusLabel(relationshipStatus) << endl;
}
