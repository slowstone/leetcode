## me_test
#### 解题思路

>* 两种情况:1 一样长,比较是否只有一处不一样 2 长度相差1,分别从左右开始遍历最长公共串,左公共串和右公共串长度之和应该大于等于短串长度,即lend + s.size() - rend >= s.size() 即lend和rend距离大于0;
>* 50ms, beats 85.60%

>* rend并不需要找完右侧最长公共串,找到lend为止即可
>* 5ms, beats 100%