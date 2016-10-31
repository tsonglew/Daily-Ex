package main

import "fmt"

func main() {
    add := func(x, y int) int {
        return x + y
    }
    fmt.Println(add(1, 2))

    x := 0

    increment := func() int {
        x++
        return x
    }
    fmt.Println(increment())
    fmt.Println(increment())

    nextEven := makeEvenGenerator()
    fmt.Println(nextEven())
    fmt.Println(nextEven())
    fmt.Println(nextEven())
}

func makeEvenGenerator() func() uint {
    l := uint(0)
    return func() (ret uint) {
        ret = l
        l += 2
        return
    }
}
