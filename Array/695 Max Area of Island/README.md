## 695. Max Area of Island
#### Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

>* Example 1:
>>* Input:  
[[0,0,1,0,0,0,0,1,0,0,0,0,0],  
 [0,0,0,0,0,0,0,1,1,1,0,0,0],  
 [0,1,1,0,1,0,0,0,0,0,0,0,0],  
 [0,1,0,0,1,1,0,0,1,0,1,0,0],  
 [0,1,0,0,1,1,0,0,1,1,1,0,0],  
 [0,0,0,0,0,0,0,0,0,0,1,0,0],  
 [0,0,0,0,0,0,0,1,1,1,0,0,0],  
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
>>* Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.

>* Example 2:
>>* Input:  
[[0,0,0,0,0,0,0,0]]
>>* Given the above grid, return 0.

>* Note:
>> The length of each dimension in the given grid does not exceed 50.