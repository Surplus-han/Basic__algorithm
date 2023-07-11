//
// Created by 72829 on 2022/10/28.
//
/*
 * 单调栈 + 累计贡献
 *
 *
 */


/*
 * 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
由于答案可能很大，因此 返回答案模 10^9 + 7 。
 https://leetcode.cn/problems/sum-of-subarray-minimums/description/

 题解：https://leetcode.cn/problems/sum-of-subarray-minimums/solutions/1930857/gong-xian-fa-dan-diao-zhan-san-chong-shi-gxa5/
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	const int MOD = 1e9 + 7;
 public:
	int sumSubarrayMins(vector<int>& arr)
	{
		int n = arr.size();
		//z左边界为严格小于arr[i]的最近的元素位置
		vector<int> left(n, -1);
		stack<int> st;
		for (int i = 0; i < n; i++)
		{
			while (!st.empty() && arr[st.top()] >= arr[i])
			{
				st.pop();
			}
			if (!st.empty())
				left[i] = st.top();
			st.push(i);
		}
		// 右边界 right[i] 为右侧小于等于 arr[i] 的最近元素位置（不存在时为 n）
		vector<int> right(n, n);
		while (!st.empty()) st.pop();
		for (int i = n - 1; i >= 0; --i)
		{
			while (!st.empty() && arr[st.top()] > arr[i])
				st.pop(); // 移除无用数据
			if (!st.empty()) right[i] = st.top();
			st.push(i);
		}

		long ans = 0L;
		for (int i = 0; i < n; ++i)
			ans += (long)arr[i] * (i - left[i]) * (right[i] - i); // 累加贡献
		return ans % MOD;

	}
};






/*
 * https://leetcode.cn/problems/next-greater-element-iv/description/
 * 下两个更大的元素
 * 给你一个下标从 0 开始的非负整数数组 nums 。对于 nums 中每一个整数，你必须找到对应元素的 第二大 整数。

如果 nums[j] 满足以下条件，那么我们称它为 nums[i] 的 第二大 整数：

j > i
nums[j] > nums[i]
恰好存在 一个 k 满足 i < k < j 且 nums[k] > nums[i] 。
如果不存在 nums[j] ，那么第二大整数为 -1 。

比方说，数组 [1, 2, 4, 3] 中，1 的第二大整数是 4 ，2 的第二大整数是 3 ，3 和 4 的第二大整数是 -1 。
请你返回一个整数数组 answer ，其中 answer[i]是 nums[i] 的第二大整数。


 输入：nums = [2,4,0,9,6]
输出：[9,6,6,-1,-1]
解释：
下标为 0 处：2 的右边，4 是大于 2 的第一个整数，9 是第二个大于 2 的整数。
下标为 1 处：4 的右边，9 是大于 4 的第一个整数，6 是第二个大于 4 的整数。
下标为 2 处：0 的右边，9 是大于 0 的第一个整数，6 是第二个大于 0 的整数。
下标为 3 处：右边不存在大于 9 的整数，所以第二大整数为 -1 。
下标为 4 处：右边不存在大于 6 的整数，所以第二大整数为 -1 。
所以我们返回 [9,6,6,-1,-1] 。
 */


/*
 * class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        ans,s,t = [-1]*len(nums),[],[]
        for i,x in enumerate(nums):
            while t and nums[t[-1]] < x:
                ans[t.pop()] = x
            j = len(s)-1
            while j >= 0 and nums[s[j]] < x:
                j -= 1
            t += s[j + 1:]
            del s[j+1:]
            s.append(i)
        return ans
 */
/*
 * 思路：准备两个栈，S是一个单调递减栈，从左往右遍历 nums用（递减）单调栈 s 记录元素，如果 x=nums[i]比 s的栈顶大，
 * 则 x是栈顶的下个更大元素，弹出栈顶。最后把 x 入栈（实际入栈的是下标 i）。

把弹出的元素加到另一个栈 t中（注意保持原始顺序），后续循环时，如果 y=nums[j]比 ttt 的栈顶大，
 则 y是栈顶的下下个更大元素，记录答案，弹出栈顶。


 */
class Solution2
{
 public:
	vector<int> secondGreaterElement(vector<int>& nums)
	{
		int n = nums.size();
		vector<int> ans(n, -1), s, t;
		for (int i = 0; i < n; ++i)
		{
			int x = nums[i];
			while (!t.empty() && nums[t.back()] < x)
			{
				ans[t.back()] = x;
				t.pop_back();
			}
			int j = (int)s.size() - 1;
			while (j >= 0 && nums[s[j]] < x) --j;
			t.insert(t.end(), s.begin() + (j + 1), s.end());
			s.resize(j + 1);
			s.push_back(i);
		}
		return ans;
	}
};

/**
* https://leetcode.cn/problems/maximum-frequency-stack/
 * 最大频率栈
 * 设计一个类似堆栈的数据结构，将元素推入堆栈，并从堆栈中弹出出现频率最高的元素。

实现 FreqStack类:

FreqStack()构造一个空的堆栈。
void push(int val)将一个整数val压入栈顶。
int pop()删除并返回堆栈中出现频率最高的元素。
如果出现频率最高的元素不只一个，则移除并返回最接近栈顶的元素。

 *
*/

/**
* 题解：https://leetcode.cn/problems/maximum-frequency-stack/solution/mei-xiang-ming-bai-yi-ge-dong-hua-miao-d-oich/
*/

/**
* 建立一个计数的哈希表和一个列表，列表的每一个元素都是一个栈,每个栈从左至右表示
 * 不同频率，弹出时弹出右边的栈中的栈顶元素，即频率最高的
*/

class FreqStack
{
 public:
	unordered_map<int, int> cnt;
	vector<stack<int>> stacks;
	FreqStack()
	{

	}
	void push(int val)
	{
		if (cnt[val] == stacks.size())
		{//当前元素出现次数等于vector的大小，现在又出现了一次，则必须创建一个新栈
			stacks.push_back({});
		}
		stacks[cnt[val]].push(val);//添加频次栈
		++cnt[val];//更新频率
	}
	int pop()
	{
		int ans = stacks.back().top();
		stacks.back().pop();
		if (stacks.back().empty())
		{
			stacks.pop_back();
		}
		--cnt[ans];
		return ans;
	}
};

