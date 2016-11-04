package main

import (
    "fmt"
    "hash/crc32"
)

func main() {
    // create a hasher
    h := crc32.NewIEEE()
    // write data
    h.Write([]byte("test"))
    // calculate crc32 checksum
    v := h.Sum32()
    fmt.Println(v)
}
