package main

import (
    "fmt";
)

func main() {
    const allDone = 2
    doneCount := 0
    answera := make(chan int)
    answerb := make(chan int)

    defer func() {
        close(answera)
        close(answerb)
    }()

    done := make(chan bool)
    defer func() {
        close(done)
    }()

    go expensiveComputation(data1, answera, done)
    go expensiveComputation(data2, answerb, done)

    for doneCount != allDone() {
        var which, result int
        select {
        case result = <- answera:
            which = 'a'
        case result = <- answerb:
            which = 'b'
        case <- done:
            doneCount++
        }

        if which!= 0 {
            fmt.Println("%c->%d ", which, result)
        }
    }
}
fmt.Println()
