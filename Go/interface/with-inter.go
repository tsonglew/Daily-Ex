package main

import "fmt"

type square struct { r int }
type circle struct { r int }

func (s square) area() int { return s.r*s.r }
func (c circle) area() int { return 3*c.r*c.r }

func main() {
    s := square{1}
    c := circle{1}
    a := [2]interface{}{ s, c }
    fmt.Println(s, c, a)

    sum := 0
    for _, t := range a {
        switch v := t.(type) {
        case square:
            sum += v.area()
        case circle:
            sum += v.area()
        }
    }

    fmt.Println(sum)
}
