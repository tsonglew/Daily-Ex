package main

import "fmt"

func main() {
    fmt.Println("string with double quotes:")
    fmt.Println("Hello,\n World!")
    fmt.Println("string with backticks:")
    fmt.Println(`Hello, \n
    World!`)
    fmt.Println(len("Hello, World!"))
    fmt.Println("Hello, World!"[1])
    fmt.Println("Hello, " + "World!")
}
