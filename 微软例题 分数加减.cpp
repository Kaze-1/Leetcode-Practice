#include <unordered_map>
#include<bits/stdc++.h>

#include <vector>
using namespace std;

const int MOD = 1000000007;

/*
在leetcode上看到真的靠谱的结果：
https://leetcode.com/discuss/interview-question/415307/american-express-online-codility-fraction-addition

找出分母的最大公倍数，然后转换成two_sum，用哈希表查找是正确的


*/



//下述为chatGPT的生成成果 都不正确
int getPairs(vector<int>& X, vector<int>& Y) {
    // Store fractions and their counts in a hash map
    unordered_map<long long, int> counts;
    for (int i = 0; i < X.size(); i++) {
        long long numerator = X[i];
        long long denominator = Y[i];
        // If the denominator is larger, swap numerator and denominator
        if (numerator > denominator) {
            swap(numerator, denominator);
        }
        long long fraction = (numerator << 32) | denominator;
        counts[fraction]++;
    }
    int pairs = 0;
    // Iterate through the hash map and count pairs of fractions that sum to 1
    for (auto& p : counts) {
        long long fraction = p.first;
        int count = p.second;
        long long numerator = fraction >> 32;
        long long denominator = fraction & 0xffffffff;
        // Check if the complement of the current fraction is also in the hash map
        long long complement = ((1000000000 - numerator) << 32) | denominator;
        if (counts.count(complement)) {
            pairs = (pairs + (long long)count * counts[complement]) % MOD;
        }
    }
    return pairs;
}




int solution(vector<int>& X, vector<int>& Y) {
    unordered_map<int, int> freq;
    for (int i = 0; i < X.size(); i++) {
        freq[X[i] * 1000000000 + Y[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < X.size(); i++) {
        ans = (ans + freq[(1000000000 - Y[i]) * 1000000000 + X[i]]) % MOD;
        ans = (ans + freq[X[i] * 1000000000 + Y[i]] / 2) % MOD;
    }
    return ans;
}


int main()
{
    //vector<int>a = { 1,1,2 };
    //vector<int>b = { 3,2,3 };
    //cout << solution(a,b);

    float a = (1+0.0) / 54;
    float b = (53+0.0) / 54;
    cout << (a + b == 1.);
    return 0;
}