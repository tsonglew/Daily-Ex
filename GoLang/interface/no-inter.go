package main

import (
    "fmt";
)

type square struct { r int }
type circle struct { r int }

func (s square) area() int { return s.r*s.r }
func (c circle) area() int { return 3*c.r*c.r }

func main() {
    s := square{2}
    c := circle{1}
    fmt.Println(s, c, s.area()+c.area())
}
