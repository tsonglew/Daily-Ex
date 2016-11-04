package main

import (
    "fmt"
    "time"
    "math/rand"
)

func f(n int) {
    for i := 0; i< 10; i++ {
        fmt.Println(n, ":", i)
        // Intn returns, as an int, a non-negative pseudo-random number in
        // [0,n) from the default Source. It panics if n <= 0.
        amt := time.Duration(rand.Intn(250))
        time.Sleep(time.Millisecond * amt)
    }
}

func main() {
    for i := 0; i < 10; i++ {
        go f(i)
    }
    var input string
    fmt.Scanln(&input)
}
