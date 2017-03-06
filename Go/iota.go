package main

import "fmt"

func main() {
    const (
        a = 10
        b = iota
        c = 1
        d
        e = iota
    )

    fmt.Println(a, b, c, d, e)
}
