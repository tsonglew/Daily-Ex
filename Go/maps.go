package main

import "fmt"

func main() {
    // var x map[string]int WRONG
    // map should be initialized before they can be used
    x := make(map[string]int)
    x["key"] = 10
    fmt.Println(x)
    fmt.Println(x["key"])

    elements := make(map[string]string)
    elements["H"] = "Hydrogen"
    elements["He"] = "Helium"
    elements["Li"] = "Lithium"
    elements["Be"] = "Beryllium"

    fmt.Println(elements["hello"])

    if name, ok := elements["hello"]; ok {
        fmt.Println(name, ok)
    }

    nums := make(map[string]int)
    if num, ok := nums["world"]; ok {
        fmt.Println(num, ok)
    } else {
        fmt.Println("No num!")
        fmt.Println(num, ok)
    }

    elems := map[string]map[string]string {
        "H": map[string]string {
            "name": "Hydrogen",
            "state": "gas",
        },
        "He": map[string]string {
            "name": "Helium",
            "state": "gas",
        },
    }

    if elem, ok := elems["H"]; ok {
        fmt.Println(elem["name"], elem["state"], ok)
    }
}
