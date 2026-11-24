package main

import "fmt"

func sum(xs []int) int {
	var out int
	for _, x := range xs {
		out += x
	}
	return out
}

func maxSumSubArray(xs []int, k int) int {
	out, start, end := 0, 0, k
	for end < len(xs) {
		res := sum(xs[start:end])
		if res > out {
			out = res
		}
		start++
		end++
	}
	return out
}

func maxSumSubArray2(xs []int, k int) int {
	start, end := 0, k
	out, prev := sum(xs[start:end]), 0
	for end < len(xs) {
		prev -= xs[start]
		prev += xs[end]
		if prev > out {
			out = prev
		}
		start++
		end++
	}
	return out
}

func main() {
	nums := []int{8, 3, -2, 4, 5, -1, 0, 5, 3, 9, -6}
	fmt.Println("nums:", nums)
	fmt.Println("---")
	fmt.Println("v1:", maxSumSubArray(nums, 5))
	fmt.Println("---")
	fmt.Println("v2:", maxSumSubArray2(nums, 5))
}
