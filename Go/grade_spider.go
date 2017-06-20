package main

import (
	"net/http"
	"log"
	"fmt"
	"io/ioutil"
	"encoding/base64"
	"strings"
)

var login_url = "https://ccnubox.muxixyz.com/api/info/login/"

func main() {
	defer func() {
		if r := recover(); r != nil {
			log.Println("[Error]", r)
		}
	}()

	fmt.Println("URL:>", login_url)
	req, _ := http.NewRequest("GET", login_url, nil)
	auth := strings.Join([]string{"Basic", base64.StdEncoding.EncodeToString([]byte("2015210773:170058"))}, " ")
	req.Header.Set("Authorization", auth)
	fmt.Println(auth)

	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}
	defer resp.Body.Close()
	fmt.Println("Status Code: ", resp.StatusCode)
	fmt.Println("Response Header: ", resp.Header)
    bodyBytes, err2 := ioutil.ReadAll(resp.Body)
	if err2 != nil {
		panic(err2)
	}
	fmt.Println(string(bodyBytes))
}
