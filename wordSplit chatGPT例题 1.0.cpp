#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

bool wordSplit(const string& s, const unordered_set<string>& dict) {
    int n = s.size();
    vector<bool> dp(n + 1);

    // Initialize the DP table
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        dp[i] = false;
    }

    // Fill in the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.count(s.substr(j, i - j)) > 0) {
                dp[i] = true;
                break;
            }
        }
    }

    // Return the final result
    return dp[n];
}

int main() {
    string s = "thequickbrownfoxjumpsoverthelazydog";
    unordered_set<string> dict = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog" };

    if (wordSplit(s, dict)) {
        cout << "The string can be split into valid words." << endl;
    }
    else {
        cout << "The string cannot be split into valid words." << endl;
    }

    return 0;
}
