class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        if(num == 1) return true;
        if(num%2 == 0) return isUgly(num/2);
        if(num%3 == 0) return isUgly(num/3);
        if(num%5 == 0) return isUgly(num/5);
        return false;
    }
};

class Solution {
public:
    bool isUgly(int num) 
    {
        if (num <= 0)
            return false;
        
        while (0 == num % 2)
            num /= 2;
        while (0 == num % 3)
            num /= 3;
        while (0 == num % 5)
            num /= 5;
        
        return 1 == num;
    }
};