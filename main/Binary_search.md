二分时候区间问题
⼀、寻找⼀个数（基本的⼆分搜索）
搜索⼀个数，如果存在，
返回其索引，否则返回 -1。

```c++
int binarySearch(int[] nums, int target)
{

	int left = 0;
	int right = nums.length - 1; // 注意
	while(left <= right) 
	{
		int mid = left + (right - left) / 2;
		if(nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1; // 注意
		else if (nums[mid] > target)
			right = mid - 1; // 注意
    }
	return -1;
}
```

1、为什么 while 循环的条件中是 <=，⽽不是 <？
答：因为初始化 right 的赋值是 nums.length - 1 ，即最后⼀个元素的索
引，⽽不是 nums.length 。
这⼆者可能出现在不同功能的⼆分查找中，区别是：前者相当于两端都闭区
间 [left, right] ，后者相当于左闭右开区间 [left, right) ，因为索引⼤
⼩为 nums.length 是越界的。
我们这个算法中使⽤的是前者 [left, right] 两端都闭的区间。这个区间
其实就是每次进⾏搜索的区间。
什么时候应该停⽌搜索呢？当然，找到了⽬标值的时候可以终⽌：
if(nums[mid] == target)
return mid;
但如果没找到，就需要 while 循环终⽌，然后返回 -1。那 while 循环什么时
候应该终⽌？搜索区间为空的时候应该终⽌，意味着你没得找了，就等于没
找到嘛。
while(left <= right) 的终⽌条件是 left == right + 1 ，写成区间的形式
就是 [right + 1, right] ，或者带个具体的数字进去 [3, 2] ，可⻅这时候
区间为空，因为没有数字既⼤于等于 3 ⼜⼩于等于 2 的吧。所以这时候
我写了⾸诗，让你闭着眼睛也能写对⼆分搜索
while 循环终⽌是正确的，直接返回 -1 即可。
while(left < right) 的终⽌条件是 left == right ，写成区间的形式就是
[left, right] ，或者带个具体的数字进去 [2, 2] ，这时候区间⾮空，还
有⼀个数 2，但此时 while 循环终⽌了。也就是说这区间 [2, 2] 被漏掉
了，索引 2 没有被搜索，如果这时候直接返回 -1 就是错误的。
