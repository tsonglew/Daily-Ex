package main

import (
    "fmt"
)

type Part struct {
    Id int
    Name string
}

type Part2 struct {
    Part
    Name string
}

func main() {
    p := Part2{ Part{1, "kasheem"}, "lew"}
    fmt.Println(p.Part.Id)
}
