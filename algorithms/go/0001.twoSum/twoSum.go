package leetcode

/**
 * 解法一：
 * 暴力法，时间复杂度O(n*n)
 */
func twoSumV1(nums []int, target int) []int {
	var res []int
	for i := 0; i < len(nums); i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return append(res, i, j)
			}
		}
	}
	return res
}

/**
 * 解法二：
 * 遍历数组，将元素依次存入map，直到能在map中能找到对于目标值来说当前元素等另一半数
 * 时间复杂度O(n)
 */
func twoSum(nums []int, target int) []int {
	m := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		another := target - nums[i]
		if _, ok := m[another]; ok {
			return []int{m[another], i}
		}
		m[nums[i]] = i
	}
	return nil
}
