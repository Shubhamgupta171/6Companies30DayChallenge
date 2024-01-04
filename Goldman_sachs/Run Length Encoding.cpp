#include <iostream>
using namespace std;

string encode(string src) {
    string answer = "";
    int count = 1;

    for (int i = 1; i <= src.size(); i++) {
        if (src[i - 1] != src[i]) {
            // Append the current character and its count to the result string
            answer = answer + src[i - 1];
            answer += to_string(count);
            count = 1;  // Reset the count for the new character
        } else {
            count = count + 1;  // Increment the count for consecutive repeated characters
        }
    }

    return answer;
}

int main() {
    string input = "aaabbbcccd";
    string result = encode(input);
    cout << "Original string: " << input << endl;
    cout << "Encoded string: " << result << endl;

    return 0;
}
