package main

import (
    "fmt"
    "log"

    "github.com/PuerkitoBio/goquery"
)

func main() {
    // returns a Document pointer
    doc, err := goquery.NewDocument("https://news.ycombinator.com/")
    if err != nil {
        log.Fatalln(err)
    }

    // get html
    html, err := doc.Html()
    if err != nil {
        log.Println(err)
    }
    fmt.Println(html)

    // find class "hname"
    fname := doc.Find(".hnname").Text()
    fmt.Println("fname: " + fname)
    if link, exists := doc.Find(".hnnmae a").Attr("href"); exists {
        fmt.Println(link)
    }

    // Story titles and links
    doc.Find(".storylink").Each(func(i int, sel *goquery.Selection) {
        fmt.Println(sel.Text())
        if attr, exists := sel.Attr("href"); exists {
            fmt.Println(attr)
        }
    })
}
