package main

func findNumberIn2DArray(matrix [][]int, target int) bool {
	n := len(matrix)
	if n == 0 {
		return false
	}
	m := len(matrix[0])
	if m == 0 {
		return false
	}
	for i := 0; i < n; i++ {
		left := 0
		right := m - 1
		mid := 0
		for {
			if left > right {
				break
			}
			mid = (left + right) / 2
			if matrix[i][mid] > target {
				right = mid - 1
			} else if matrix[i][mid] < target {
				left = mid + 1
			} else {
				return true
			}
		}
	}
	return false
}
