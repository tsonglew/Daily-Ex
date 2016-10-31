package main

import "fmt"

func average(xs []float64) float64 {
    total := 0.0
    for _, i := range xs {
        total += i
    }
    return total / float64(len(xs))
}

func f() (int, int) {
    return 5, 6
}

func f2() (r int) {
    r = 1
    return
}

func main() {
    xs := []float64{98,93,77,82,83}
    fmt.Println(average(xs))
    x, y := f()
    fmt.Println(x, y)
    fmt.Println(f2())
}
