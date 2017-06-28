package main

// Basic flag declarations are available for string, integer, and boolean options.

import (
	"flag"
	"fmt"
	"math/rand"
)

func main() {
	//						|flag|default|description|
	wordPtr := flag.String("name", "foo", "a string") // return a String pointer
	numbPtr := flag.Int("numb", 42, "an int")
	boolPtr := flag.Bool("fork", false, "a bool")
	maxp := flag.Int("max", 6, "the max value")

	// declare an option that uses an existing var declared elsewhere in the program.(need to pass in a pointer)
	var svar string
	flag.StringVar(&svar, "svar", "bar", "a string var")

	// execute the command-line parsing.
	flag.Parse()
	fmt.Println(rand.Intn(*maxp))
	fmt.Println(*numbPtr)
	fmt.Println(*wordPtr)
	fmt.Println(*boolPtr)
	//If you provide a flag that wasn’t specified to the flag package, the program will print an error message and show the help text again.
}
