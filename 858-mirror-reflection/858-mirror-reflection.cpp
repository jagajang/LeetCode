class Solution {
private:
    int gcd(int a, int b) {
        if(a < b)
            swap(a, b);
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

public:
    int mirrorReflection(int p, int q) {
        int g = gcd(p, q);
        
        if(p / g % 2 == 0)
            return 2;
        else if(q / g % 2 == 0)
            return 0;
        else
            return 1;        
    }
};