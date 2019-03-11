# Sort
https://www.cnblogs.com/onepixel/articles/7674659.html
# Quick sort
https://www.cnblogs.com/eudiwffe/p/6202996.html
&emsp;base quick sort
```C++
// A simple quick sort version, which combine partition and sort
void quick_sort(int arr[], int begin, int end)
{
    int i=begin, j=end-1, key;
    if (i>=j) return;
    for(key=arr[i]; i<j;){
        for(; i<j && arr[j]>=key; --j);
        arr[i] = arr[j];
        for(; i<j && arr[i]<=key; ++i);
        arr[j] = arr[i];
    }
    arr[i] = key;
    quick_sort(arr,begin,i);
    quick_sort(arr,i+1,end);
}
```
&emsp;link quick sort.
&emsp;由于数组进行划分时，其元素进行移动很费时，然而对于链表而言，其元素划分后，并不需要移动，只需要指针交换即可。所以，定义两个指针mid和p，p进行快速向后遍历，当遇到小于KEY的节点时，将其加入到mid尾部并且mid后移一位。执行一趟partition后，p到达尾部NULL，mid为KEY的位置，然后继续划分begin~mid以及mid~end。
```C++
// A simple quick sort version, which combine partition and sort
// A simple ListNode define
typedef struct __ListNode
{
    int val;
    struct __ListNode *next;
}ListNode;
// quick sort by ascending order for list
void qsort(ListNode *begin, ListNode *end)
{
    if (begin==end || begin==NULL) return;
    ListNode *p, *mid;
    for(mid=begin, p=mid->next; p!=end; p=p->next){
        if (p->val > begin->val) continue;
        mid = mid->next;
        if (mid!=p) swap(p->val,mid->val);
    }
    swap(begin->val,mid->val);
    qsort(begin,mid);
    qsort(mid->next,end);
}
```
&emsp;Kth-smallest number
```C++
// Partition - <small> KEY <big>
int partition(int arr[], int begin, int end)
{
    int i=begin, j=end-1, key;
    if (i>=j) return i;
    for (key=arr[i]; i<j;){
        // find last arr[j]<key
        for(; i<j && arr[j]>=key; --j);
        arr[i] = arr[j];
        // find first arr[i]>key
        for(; i<j && arr[i]<=key; ++i);
        arr[j] = arr[i];
    }
    arr[i] = key;
    return i;       // current key position
}   // Time O(n)
// after partition, the KEY must be the position where ordered
// Kth-smallest number, partition by ascending order
int kth_smallest(int k, int arr[], int n) {
    int i=0, j=n, pos=-1;
    for(--k; pos!=k;){
        pos = partition(arr,i,j);
        i = (pos<k ? pos+1 : i);
        j = (pos>k ? pos : j);
    }
    return arr[k];
}
```