package main

import (
    "log";
    "time"
)

var (
    concurrent = 5
    semaphoreChan = make(chan struct{}, concurrent)
)

func doWork(item int) {
    semaphoreChan <- struct{}{}
    go func() {
        defer func() {
            <-semaphoreChan
        }()
        log.Println(item)
        time.Sleep(1 * time.Second)
    }()
}

func main() {
    for i:=0; i<10000; i++ {
        doWork(i)
    }
}
