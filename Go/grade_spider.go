package main

import (
	"net/http"
	"log"
	"fmt"
	"io/ioutil"
	"encoding/base64"
	"strings"
	"encoding/json"
)

var login_url = "https://ccnubox.muxixyz.com/api/info/login/"
var grade_detail_url = "http://122.204.187.6/cjcx/cjcx_cxCjxq.html?time=1492911913954&gnmkdmKey=N305005&sessionUserKey="

func main() {
	BIGipServerpool_jwc_xk, JSESSIONID, sid := GetLoginCookie("2015210773", "170058")
	Cookie := strings.Join([]string{"BIGipServerpool_jwc_xk=", BIGipServerpool_jwc_xk, "; ", "JSESSIONID=", JSESSIONID}, "")
	fmt.Println("Cookie: ", Cookie)
	fmt.Println("sid:", sid)
	var grade_url = strings.Join([]string{grade_detail_url, "2015210773"}, "")
	fmt.Println("------------------------------------------------------------------")
}

func GetLoginCookie(sid, passwd string) (BIGipServerpool_jwc_xk, JSESSIONID, rsid string) {
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
    data, err := ioutil.ReadAll(resp.Body)
	if err != nil {
		panic(err)
	}
	type sCookie struct {
	    BIGipServerpool_jwc_xk, JSESSIONID string
	}
	var objmap map[string]*json.RawMessage
	err = json.Unmarshal(data, &objmap)
	var s sCookie
	if err = json.Unmarshal(*objmap["cookie"], &s); err != nil {
		panic(err)
	}
	if err = json.Unmarshal(*objmap["sid"], &rsid); err != nil {
		panic(err)
	}
	BIGipServerpool_jwc_xk = s.BIGipServerpool_jwc_xk
	JSESSIONID = s.JSESSIONID
	return
}

func GetAllGrade(Cookie string) (gradeData string) {
	defer func() {
		if r := recover(); r != nil {
			log.Println(r)
		}
	}()
	req, _ := http.NewRequest("POST", "http://122.204.187.6/cjcx/cjcx_cxDgXscj.html?doType=query&gnmkdmKey=N305005&sessionUserKey=2015210773",nil)
    req.Header.Set("Accept", "application/json, text/javascript, */*; q=0.01")
	req.Header.Set("Accept-Encoding", "gzip, deflate")
    req.Header.Set("Accept-Language", "en-US,en;q=0.8,zh-CN;q=0.6,zh;q=0.4")
    req.Header.Set("Connection", "keep-alive")
    req.Header.Set("Content-Length", "148")
    req.Header.Set("Content-Type", "application/x-www-form-urlencoded;charset=UTF-8")
    req.Header.Set("Cookie", "BIGipServerpool_jwc_xk=424716480.20480.0000; JSESSIONID=E0C258DA4D67D3AC16AE11E7B5D399D0")
    req.Header.Set("Host","122.204.187.6")
    req.Header.Set("Origin", "http://122.204.187.6")
    req.Header.Set("Referer", "http://122.204.187.6/cjcx/cjcx_cxDgXscj.html")
    req.Header.Set("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36")
    req.Header.Set("X-Requested-With", "XMLHttpRequest")
	client := &http.Client{}
	resp, err := client.Do(req)
	if err != nil {
		panic(err)
	}
	defer resp.Body.Close()
	fmt.Println(resp.StatusCode)
	fmt.Println(resp.ContentLength)
	fmt.Println(grade_url)
}
