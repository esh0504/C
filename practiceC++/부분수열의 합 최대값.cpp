#include <string>
#include <vector>
#include <climits>

using namespace std;
int FMCS(vector<int>& param, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += param[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += param[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }
    return left_sum + right_sum;
}

int FMS(vector<int>& param, int low, int high) {
    if (high == low) {
        return param[low];
    }
    else {
        int mid = (low + high) / 2;
        int left_sum = FMS(param, low, mid);
        int right_sum = FMS(param, mid + 1, high);
        int cross_sum = FMCS(param, low, mid, high);
        if (left_sum >= right_sum && left_sum >= cross_sum) {
            return left_sum;
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum) {
            return right_sum;
        }
        else {
            return cross_sum;
        }
    }
}

int solution(vector<int> param0) {
    int answer = FMS(param0, 0, param0.size() - 1);

    return answer;
}
