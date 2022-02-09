package main

import (
	"fmt"
	"sort"
)

func findRepeatNumber(nums []int) int {
	sort.Ints(nums)
	len := len(nums)
	for i := 0; i < len-1; i++ {
		if nums[i] == nums[i+1] {
			return nums[i]
		}
	}
	return 0
}

func main() {
	nums := []int{2, 3, 1, 0, 2, 5, 3}
	res := findRepeatNumber(nums)
	fmt.Println(res)
}
