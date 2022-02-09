package main

import "fmt"

func findRepeatNumber(nums []int) int {
	len := len(nums)
	for i := 0; i < len; i++ {
		temp := 0
		for {
			if nums[i] == i {
				break
			}
			if nums[i] == nums[nums[i]] {
				return nums[i]
			}
			temp = nums[nums[i]]
			nums[nums[i]] = nums[i]
			nums[i] = temp
		}
	}
	return 0
}

func main() {
	nums := []int{2, 3, 1, 0, 2, 5, 3}
	res := findRepeatNumber(nums)
	fmt.Println(res)
}
