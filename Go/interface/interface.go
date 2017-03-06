package main

import ("fmt"; "math")

type Circle struct {
    r float64
}

type Rectangle struct {
    d float64
    h float64
}

func main() {
    c := Circle{10}
    r := Rectangle{5, 10}
    fmt.Println("total area")
    fmt.Println(totalArea(&c, &r))
}

func (c *Circle) area() float64 {
    return math.Pi * c.r * c.r
}

func (r *Rectangle) area() float64 {
    return r.d * r.h
}

type Shape interface {
    area() float64
}
func totalArea(shapes ...Shape) float64 {
    var area float64
    for _, s := range shapes {
        area += s.area()
    }
    return area
}
/*func totalArea(cs ...Circle, rs ...Rectangle) float64 {
    var total float64
    for _, c := range cs {
        total += c.area()
    }

    for _, r := range rs {
        total += r.area()
    }
    return total
}*/
