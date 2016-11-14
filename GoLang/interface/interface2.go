package main
import "fmt"

type Human struct {
    name string
    age int
    phone string
}

type Student struct {
    Human //匿名字段
    school string
}

// Human实现SayHi方法
func (h Human) SayHi() {
    fmt.Printf("Hi, I am %s you can call me on %s\n", h.name, h.phone)
}

// Human实现Sing方法
func (h Human) Sing(lyrics string) {
    fmt.Println("La la la la...", lyrics)
}

// Student重载SayHi方法
func (s Student) SayHi() {
    fmt.Printf("Hi, I am %s from %s school", s.name, s.school)
}

// Men interface(Human和Student都实现了Men interface中的两个方法)
type Men interface {
    SayHi()
    Sing(lyrics string)
}

func main() {
    normal_people := Human{"annoymous", 20, "110"}
    kasheem := Student{Human{"Kasheem Lew", 19, "1507-XXXX-XXX"}, "CCNU"}
    //定义Men类型的变量i
    var i Men
    //i能存储Student
    i = kasheem
    fmt.Println("This is Kaheem Lew, a Student:")
    i.SayHi()
    i.Sing("la la la...")
    i = normal_people
    i.SayHi()
    i.Sing("la...")
}
