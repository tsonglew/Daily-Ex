package main

import (
	"flag"
	"fmt"
	"log"
	"net"
)

var raddr = flag.String("raddr", "127.0.0.1:10000", "remote server address")

func init() {
	log.SetFlags(log.LstdFlags | log.Lshortfile)
	flag.Parse()
}

func main() {
	remoteAddr, err := net.ResolveUDPAddr("udp", *raddr)
	if err != nil {
		log.Fatalln("Error: ", err)
	}

	// make connection
	tmpAddr := &net.UDPAddr{
		IP:   net.ParseIP("127.0.0.1"),
		Port: 0,
	}
	conn, err := net.DialUDP("udp", tmpAddr, remoteAddr)
	if err != nil {
		log.Fatalln("Error: ", err)
	}
	defer conn.Close()
	_, err = conn.Write([]byte("Hello World!\n"))
	if err != nil {
		log.Println("Error: ", err)
	} else {
		fmt.Println(">>>>Packet sent to ", remoteAddr.String())
	}

	buf := make([]byte, 1024)
	rn, rmaddr, err := conn.ReadFromUDP(buf)
	if err != nil {
		log.Println("Error ", err)
	} else {
		fmt.Printf("<<<< %d bytes received from %v, data: %s", rn, *rmaddr, string(buf))
	}
}
