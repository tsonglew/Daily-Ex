package main

import (
	"flag" //implements command-line flag parsing.
	"fmt"
	"log"
	"net"
)

var addr = flag.String("addr", ":10000", "udp server being address")

func init() {
	log.SetFlags(log.LstdFlags | log.LstdFlags)
	//       Ldate         = 1 << iota     // the date in the local time zone: 2009/01/23
	//       Ltime                         // the time in the local time zone: 01:23:23
	//       Lmicroseconds                 // microsecond resolution: 01:23:23.123123.  assumes Ltime.
	//       Llongfile                     // full file name and line number: /a/b/c/d.go:23
	//       Lshortfile                    // final file name element and line number: d.go:23. overrides Llongfile
	//       LUTC                          // if Ldate or Ltime is set, use UTC rather than the local time zone
	//       LstdFlags     = Ldate | Ltime // initial values for the standard logger
	flag.Parse()
}

func main() {
	// type UDPAddr struct {
	//        IP   IP
	//        Port int
	//        Zone string // IPv6 scoped addressing zone
	// }

	// Resolve address
	// func ResolveUDPAddr(net, addr string) (*UDPAddr, error)
	// parses addr as a UDP address of the form "host:port" or "[ipv6-host%zone]:port" and resolves a pair of domain name and port name on the network net
	udpAddr, err := net.ResolveUDPAddr("udp", *addr)
	if err != nil {
		log.Fatalln("Error: ", err)
	}

	// Build listening connections
	conn, err := net.ListenUDP("udp", udpAddr)
	if err != nil {
		log.Fatalln("Error:", err)
	}
	defer conn.Close()

	// Interact with client
	recvBuff := make([]byte, 1024)
	for {
		// func (c *UDPConn) ReadFromUDP(b []byte) (int, *UDPAddr, error)
		// ReadFromUDP reads a UDP packet from c, copying the payload into b. It returns the number of bytes copied into b and the return address that was on the packet.
		rn, rmAddr, err := conn.ReadFromUDP(recvBuff)
		if err != nil {
			log.Println("Error: ", err)
			return
		}
		fmt.Printf("<<<< %d bytes Received From %s, data: %s", rn, rmAddr.String(), string(recvBuff[:rn]))
		_, err = conn.WriteToUDP(recvBuff[:10], rmAddr)
		if err != nil {
			log.Println("Error: ", err)
			return
		}
		fmt.Printf(">>>> Sending Back to %s, data: %s", rmAddr.String(), string(recvBuff[:10]))

	}
}
