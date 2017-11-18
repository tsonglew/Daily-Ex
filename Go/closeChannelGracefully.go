package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	var wg sync.WaitGroup

	jobs := make(chan int)
	timeout := make(chan bool)

	go func() {
		time.Sleep(time.Second * 3)
		timeout <- true
	}()

	go func() {
		for i := 0; ; i++ {
			select {
			case <-timeout:
				close(jobs)
				return
			default:
				jobs <- i
				fmt.Println("produce: ", i)
			}
		}
	}()
	wg.Add(1)
	go func() {
		defer wg.Done()
		for i := range jobs {
			fmt.Println("consume: ", i)
		}
	}()
	wg.Wait()
}
