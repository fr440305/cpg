package main

import "fmt"

func twoSum(nums []int, target int) []int {
	m := make(map[int]int, len(nums))
	for i1, n := range nums {
		i2, find := m[target-n]
		if find && i1 != i2 {
			return []int{i1, i2}
		}
		m[n] = i1
	}
	return nil
}

func main() {
	fmt.Println(twoSum([]int{3, 2, 4}, 6))
}
