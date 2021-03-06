## 769. Max Chunks To Make Sorted
#### Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], we split the array into some number of "chunks" (partitions), and individually sort each chunk.  After concatenating them, the result equals the sorted array.<br>What is the most number of chunks we could have made?  
  
>* Example 1:  
>>* Input: arr = [4,3,2,1,0]  
>>* Output: 1  
>>* Explanation:<br>Splitting into two or more chunks will not return the required result.<br>For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.  

>* Example 2:  
>>* Input: arr = [1,0,2,3,4]
>>* Output: 4
>>* Explanation:<br>We can split into two chunks, such as [1, 0], [2, 3, 4].<br>However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.

>* Note:
>>1. arr will have length in range [1, 10].
>>2. arr[i] will be a permutation of [0, 1, ..., arr.length - 1].
