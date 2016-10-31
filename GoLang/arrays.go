package main

import "fmt"

func main() {
    var x [5]float64
    x[0] = 98
    x[1] = 93
    x[2] = 77
    x[3] = 82
    x[4] = 83

    var total float64 = 0
    for i:= 0; i < len(x); i++ {
        total += x[i]
    }
    // len() has different types with float64
    fmt.Println(total / float64(len(x)))

    total = 0

    for _, value := range x {
        total += value
    }
    fmt.Println(total)
}
