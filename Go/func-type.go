package main

import (
    "fmt"
)

type testInt func(x int) bool

func isOdd(x int) bool {
    if x%2 == 0 {
        return false
    } else {
        return true
    }
}

func isEven(x int) bool {
    if x%2 == 0 {
        return true
    } else {
        return false
    }
}

func filter(slice []int, f testInt) []int {
    var result []int
    for _, integer := range slice {
        if f(integer) {
            result = append(result, integer)
        }
    }
    return result
}

func main() {
    slice := []int {1, 2, 3, 4, 5, 7}
    oddSlice := filter(slice, isOdd)
    evenSlice := filter(slice, isEven)
    fmt.Println("Slice: ", slice)
    fmt.Println("Odd Slice: ", oddSlice)
    fmt.Println("Even Slice: ", evenSlice)
}
