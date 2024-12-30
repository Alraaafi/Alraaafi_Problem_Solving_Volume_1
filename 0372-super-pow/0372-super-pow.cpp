   long long pw(long x, int n) {
        if (n == 0) return 1;
        long v = pw(x, n / 2);
        if (n % 2 == 0) {
            return v * v % 1337;
        } 
        else {
            return v * v * x % 1337;
        }
    }


class Solution {
    public:
     int superPow(int a, vector<int> b) {
        long long res = 1;
        a = a % 1337;
        int len = b.size();
        for (int i = 0; i < len; ++i) {
            res = pw(res, 10) * pw(a, b[i]) % 1337;
        }
        return (int)res;
    }

};