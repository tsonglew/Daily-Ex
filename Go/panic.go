package main

import "fmt"

func main() {
    defer func() {
        str := recover()
        fmt.Println(str)
        fmt.Println("After panic")
    }()
    panic("PANIC")
}
