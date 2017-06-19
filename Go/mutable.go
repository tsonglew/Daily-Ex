package main

import "fmt"

type Mutable struct {
    a, b int
}

func (m Mutable) StayTheSame() {
    m.a = 5
    m.b = 7
}

func (m *Mutable) Mutate() {
    m.a = 5
    m.b = 7
}

func main() {
    m := &Mutable{}
    fmt.Println(m)
    m.StayTheSame()
    fmt.Println(m)
    m.Mutate()
    fmt.Println(m)
}
