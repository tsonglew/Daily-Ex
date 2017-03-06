package main

import "fmt"

func main() {
    fmt.Println(factorials(3))
}

func factorials(x int) int {
    if x == 1 {
        return 1
    } else {
        return x * factorials(x-1)
    }
}
