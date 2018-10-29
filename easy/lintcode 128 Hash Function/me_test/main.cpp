class Solution {
public:
    /**
     * @param key: A string you should hash
     * @param HASH_SIZE: An integer
     * @return: An integer
     */
    int hashCode(string &key, int HASH_SIZE) {
        // write your code here
        long long res = 0;
        for(auto s:key){
            res = (res*33 % HASH_SIZE + s) % HASH_SIZE;
        }
        return res % HASH_SIZE;
    }
};