package main

import "fmt"

func main() {
    fmt.Println("Enter a number: ")
    var x int
    fmt.Scanf("%d", &x)
    switch x {
    case 1: fmt.Println("Number is 1")
case 2: fmt.Println("number is 2")
default: fmt.Println("undefined")
}
}
