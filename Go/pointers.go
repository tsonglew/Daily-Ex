package main

import "fmt"

func zero(xPtr *int) {
    *xPtr = 0
}

func main() {
    x := 5
    zero(&x)
    fmt.Println(x)

    yPtr := new(int)
    zero(yPtr)
    fmt.Println(*yPtr)
}
