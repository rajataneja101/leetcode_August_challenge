// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int SorB = rand7();
        int ret = rand7();
        while (ret > 5) ret = rand7();
        if (SorB < 4) return ret;
        else if (SorB > 4) return ret + 5;
        return rand10();
    }
};