#include <iostream>
#include <string>

using namespace std;

int num;
int *ptr = &num;

int count1 = 0, count2 = 0;

string findMostFrequentCharString(const string& str1, const string& str2, char target, bool& sameCount) {

    for (char c : str1) {
        if (c == target) {
            count1++;
        }
    }
    for (char c : str2) {
        if (c == target) {
            count2++;
        }
    }

    if (count1 == 0 && count2 == 0) {
        return "Not found";
    }

    if (count1 == count2) {
        sameCount = true;
        return "Same times";
    }

    return (count1 > count2) ? str1 : str2;
}

void convertCaseAndCountDigits(string& str, int& numDigits) {
    numDigits = 0;
    for (char& c : str) {
        if (islower(c)) {
            c = toupper(c);
        } else if (isupper(c)) {
            c = tolower(c);
        }

        if (isdigit(c)) {
            numDigits++;
        }
    }
}

template <typename T>
T largestSumPair(T val1, T val2, T val3) {
    T maxPair = max(val1 + val2, val2 + val3);
    return max(maxPair, val1 + val3);
}

template <typename T>
void findMinMax(const T arr[], int size, T& minVal, T& maxVal) {
    minVal = arr[0];
    maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }
}

int main(){

    //1
    cout << "Enter the first num: ";
    cin >> num;

    int num;
    int *point = &num;
    cout << "Enter the second num: ";
    cin >> num;

    cout << "The remainder is is " << (*ptr)%(*point) << endl;

    //2
    string str1, str2;
    char target;
    bool sameCount = false;

    cout << "Enter two strings: ";
    cin >> str1 >> str2;

    cout << "Enter the character to search: ";
    cin >> target;

    string result = findMostFrequentCharString(str1, str2, target, sameCount);

    if (result == "Not found") {
        cout << "Not found" << endl;
    } else if (sameCount) {
        cout << "The character '" << target << "' appears the same number of times in both strings (" << count1 << " times)." << endl;
    } else {
        cout << "The string '" << result << "' contains character '" << target << "' most often (" << (result == str1 ? count1 : count2) << " times)." << endl;
    }

    //3
    string str;
    int numDigits;

    do {
        cout << "Enter a string ending in 'x' (or 'X'): ";
        cin >> str;
    } while (str.back() != 'x' && str.back() != 'X');

    // Remove the ending 'x'
    str.pop_back();

    convertCaseAndCountDigits(str, numDigits);

    cout <<  str << " contains " << numDigits << " digits" << endl;

    //4
    int choice;
    cout << "Enter 1 to find largest sum pair or 2 to find min/max in an array: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int val1, val2, val3;
            cout << "Enter three numeric values (same type): ";
            cin >> val1 >> val2 >> val3;
            int result = largestSumPair(val1, val2, val3);
            cout << "Largest sum pair: " << result << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    //5

    return 0;
}

