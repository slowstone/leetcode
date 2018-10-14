class Solution {
public:
    int numSquares(int n) {
        while(n % 4 == 0)
            n /= 4;
        if(n % 8 == 7)
            return 4;
        
        int a = 0;
        while(a * a <= n)
        {
            int b = sqrt(n - a * a);
            if(a * a + b * b == n)
                return (a!=0) + (b!=0);
            a++;
        }
        
        return 3;
    }
};

class Solution {
    bool isSquare(int n) {
        int sqroot = floor(sqrt(n));
        
        return sqroot * sqroot == n;
    }
public:
    int numSquares(int n) {
        if(isSquare(n))
            return 1;
        
        for(int i = 1; i*i < n; i++) {
            if(isSquare(n - i*i))
                return 2;
        }
        
        int p4 = 1;
        while(n % (4 * p4) == 0)
            p4 *= 4;
        
        if((n / p4)%8 == 7)
            return 4;
        
        return 3;
    }
};

class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>> q;
        q.push(make_pair(n,0));
        vector<bool> visited(n+1,false);
        visited[n] = true;
        while(!q.empty()){
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            for(int i = 1;num - i * i >= 0;i++){
                int a = num - i * i;
                if(!visited[a]){
                    if(a < 0) break;
                    if( a == 0) return step +1;
                    q.push(make_pair(a,step+1));
                    visited[a] = true;
                }
            }
        }
    }
};