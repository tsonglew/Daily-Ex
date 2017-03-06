package main

import "fmt"

func main() {
    x := make([]float64, 5)
    arr := [5]float64{1, 2, 3, 4, 5}
    x = arr[0:5]
    fmt.Println(x)

    slice1 := []int{1, 2, 3}
    slice2 := append(slice1, 4, 5)
    fmt.Println(slice1, slice2)

    slice3 := []int{1, 2, 3}
    slice4 := []int{4, 5}
    copy(slice3, slice4)
    fmt.Println(slice3)
    fmt.Println(slice4)
}
