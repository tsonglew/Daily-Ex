package main

import "fmt"

func main() {
    x := []int{1, 2, 3, 4}
    fmt.Println(add(x...))
}

func add(argv ...int) int {
    total := 0
    for _, value := range argv {
        total += value
    }
    return total
}
