#include<bits/stdc++.h>
using namespace std;
 
unordered_map <int, int> m;
// map to identify whether element is already present in the set

// handle the extreme cases

// inserting the 2: [1 - 10]
long long max_done = 0, min_done = LLONG_MAX;

// only adding (x+1) and (x-1) to the result
// also need to handle corner elements separately
long long getOutput (long long X, long long N) {
    long long res = 0;

    // min_done denotes the min value added (1 less than the minimum element in the set)
    // X = 1 (the first element of the range)
    if (X - 1 == 0) {
        res += 1;
        if (1 < min_done) {
            min_done = 1;
        }
    } 
    else {
        res += X - 1;
        if (X - 1 < min_done) {
            min_done = X - 1;
        }
    }

    // x is my query, 

    // X = N (the last element of the range)
    if (X + 1 == N + 1) {
        res += N;
        // max_done denotes the max value added (1 more than maximum element in the set)
        if (N > max_done) {
            max_done = N;
        }
    }
    else {
        res += X + 1;
        // update max_done accordingly
        if (X + 1 > max_done) {
            max_done = X + 1;
        }
    }
    return res;
}
 
int main() {
 
    long long N, M, X;
    cin >> N >> M; // N = A, M = no. of queries

    long long out_ = 0, res = 0, prev_res;

    // res denotes the answer for a query
    // out_ denotes sum of ranges for prev value (might not handle the extreme cases)
    while(M--){
        res = 0;
        cin >> X; // query
        if (!m[X]) {
            out_ += getOutput(X, N);
            // I can increase the length of last good range by the difference between
            // N and max_done
            if (max_done < N) {
                res += N - max_done;
            }
            // 
            if (min_done > 1) {
                res -= min_done - 1;
            }

            // add the query result
            res += out_;

            // mark it done in the set
            m[X] = 1;

            // update the prev_res (result for the previous query)
            prev_res = res;
        }
        else {
            // add the previous queries result to the current one
            res += prev_res;
        }
        cout << res << endl;
    }
}