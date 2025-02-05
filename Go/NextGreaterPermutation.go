package main

import (
	"fmt"
	"sort"
)

func PermutationsEqual(a []int, b []int) bool {
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}

	return true
}

func PermutationExists(vecs [][]int, vec []int) bool {
	for i := range vecs {
		if PermutationsEqual(vecs[i], vec) {
			return true
		}
	}

	return false
}

func GetPermutations(arr []int, index int, permutations *[][]int) {
	if index == len(arr)-1 {
		if PermutationExists(*permutations, arr) {
			return
		}

		temp := make([]int, len(arr))
		copy(temp, arr)
		*permutations = append(*permutations, temp)
		return
	}

	for i := index; i < len(arr); i++ {
		arr[index], arr[i] = arr[i], arr[index]
		GetPermutations(arr, index+1, permutations)
		arr[index], arr[i] = arr[i], arr[index]
	}
}

func NextGreaterPermutation(arr []int) {
	var permutations [][]int

	GetPermutations(arr, 0, &permutations)

	sort.Slice(permutations, func(i, j int) bool {
		for k := range permutations[i] {
			if permutations[i][k] != permutations[j][k] {
				return permutations[i][k] < permutations[j][k]
			}
		}
		return false
	})

	for i := 0; i < len(permutations); i++ {
		if PermutationsEqual(arr, permutations[i]) {
			i++
			if i == len(permutations) {
				i = 0
			}
			copy(arr, permutations[i])
			break
		}
	}
}

func main() {
	for {
		fmt.Print("Number of elements: ")
		count := 0
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := make([]int, count)
		fmt.Print("Please enter the array: ")
		for i := 0; i < count; i++ {
			fmt.Scan(&vec[i])
		}

		NextGreaterPermutation(vec)

		fmt.Print("The next permutation is ")
		fmt.Println(vec)
	}
}
