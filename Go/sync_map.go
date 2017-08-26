/*
try to explain the new sync.Map in Go1.9

the former solutions:

var counter = struct {
    sync.RWMutex
    m map[string]int
}{m: make(map[string]int)}

// while reading
counter.RLock()
n := counter.m["some_key"]
counter.RUnlock()
fmt.Println()

// while writing
*/

package main

import (
    "fmt"
)

func main() {

}
