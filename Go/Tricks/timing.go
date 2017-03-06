package main

import (
    "log";
    "time";
)

func StartTime(name string) func() {
    t := time.Now()
    log.Println(name, "started")

    return func() {
        d := time.Now().Sub(t)
        log.Println(name ,"took", d)
    }
}

func FunckyTime() {
    stop := StartTime("Funcky")
    defer stop()

    time.Sleep(1 * time.Second)
}

func main() {
    FunckyTime()
}
