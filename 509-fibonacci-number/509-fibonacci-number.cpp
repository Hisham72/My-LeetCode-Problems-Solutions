class Solution {
public:
    int fib(int n) {
        if (!n) return 0;
        if (n == 1) return 1;
        int f = 0, s = 1;
        for (int i = 2; i <= n; i++){
            s += f;
            f = s - f;
        }
        return s;
    }
};