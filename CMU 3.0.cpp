#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long long ll;
#define MAX 0x7FFFFFFF



//构成M-alignd的点的特色：坐标对M同余，所以用余数划分集合刚刚好！
//
// https://stackoverflow.com/questions/29531715/pair-of-points-with-distance-divisible-by-integer
// 一遍哈希解法：
int solution_hash(vector<int>& A, int M) {
    unordered_map<int, vector<int>>set;
    int i, n = A.size();
    int res = 1;
    for (i = 0; i < n; ++i)
    {
        int tem = A[i] % M > 0 ? A[i] % M: A[i] % M + M;
        set[tem].emplace_back(A[i]);
        res = max(res, int(set[tem].size()));
    }
    return res;
}


// 动态规划解法，参考leetcode 368
int solution_dp(vector<int>& A, int M) {
    int i, j,n = A.size();
    vector<int>dp(n,1);
    int res=1;
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < i; ++j)
            if (abs(A[j] - A[i]) % M == 0)
            {
                dp[i] = max(dp[i], dp[j] + 1);
                res = max(res, dp[i]);
            }
    }
    return res;
}



//chatGPT理解错了，找坐标是M的倍数的了
int solution2(std::vector<int>& A, int M) {
    // Create a map to store the frequencies of each coordinate that is a multiple of M
    std::unordered_map<int, int> frequencies;
    for (int coord : A) {
        if (coord % M == 0) {
            ++frequencies[coord];
        }
    }

    // Find the size of the largest M-aligned subset
    int max_size = 0;
    for (int coord : A) 
    {
        // Check if the current coordinate is M-aligned
        if (coord % M == 0) {
            // If it is, the size of the M-aligned subset is the frequency of the coordinate
            max_size = std::max(max_size, frequencies[coord]);
        }
        else {
            // If it is not, we need to check if the other coordinates that are M-aligned with it exist
            int other_coord = coord % M;
            // If the other coordinate exists, the size of the M-aligned subset is the sum of the frequencies of both coordinates
            if (frequencies.count(M - other_coord) > 0)
                max_size = std::max(max_size, frequencies[M - other_coord] + 1);
        }
    }

    return max_size;
}

//chatGPT生成的用不了的sliding_window
int solution1(std::vector<int>& A, int M) {
    // Create a set to store the coordinates of the points in the current window
    std::unordered_set<int> window;

    // Initialize the size of the largest M-aligned subset to 0
    int max_size = 0;

    // Iterate over the points in the array
    for (int i = 0; i < A.size(); ++i) {
        // Add the current point to the set
        window.insert(A[i]);

        // Check if the set is M-aligned
        bool is_aligned = true;
        for (int coord : window) {
            if ((A[i] - coord) % M != 0) {
                is_aligned = false;
                break;
            }
        }

        // If the set is M-aligned, update the size of the largest M-aligned subset
        if (is_aligned) {
            max_size = std::max(max_size, static_cast<int>(window.size()));
        }

        // If the end of the window has been reached, remove the first element from the set
        if (i == A.size() - 1) {
            window.erase(A[0]);
        }
    }

    return max_size;
}

int main() {
    int M = 3;
    vector<int>A = { -3,-2,1,0,8,7,1};

    //int M = 8;
    //vector<int>A = { 7,1,11,8,4,10};
    //vector<int>B = { 1,3,4,4 };
    cout << solution_dp(A,M);

    return 0;
}
