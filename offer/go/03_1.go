package main

import "fmt"

func findRepeatNumber(nums []int) int {
	m := make(map[int]int)
	len := len(nums)
	for i := 0; i < len; i++ {
		if m[nums[i]] != 0 {
			return nums[i]
		}
		m[nums[i]]++
	}
	return 0
}

func main() {
	nums := []int{2, 3, 1, 0, 2, 5, 3}
	res := findRepeatNumber(nums)
	fmt.Println(res)
}
