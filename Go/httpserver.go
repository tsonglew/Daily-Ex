package main

import (
	"context"
	"fmt"
	"log"
	"net/http"
	"os"
	"os/signal"
)

var Host string
var Port string

func main() {
	server := &http.Server{Addr: fmt.Sprintf("%s:%s", Host, Port)}

	go func() {
		sigquit := make(chan os.Signal, 1)
		// Notify causes package signal to relay incoming signals to c.
		// If no signals are provided, all incoming signals will be relayed to c.
		// Otherwise, just the provided signals will.
		signal.Notify(sigquit, os.Interrupt, os.Kill)
		sig := <-sigquit
		log.Printf("caught sig: %+v", sig)
		log.Printf("Gracefully shutting down server...")
		if err := server.Shutdown(context.Background()); err != nil {
			log.Printf("Unable to shut down server: %v", err)
		} else {
			log.Println("Server stopped")
		}
	}()

	log.Printf("Starting HTTP Server. Listening at %q", server.Addr)
	if err := server.ListenAndServe(); err != http.ErrServerClosed {
		log.Printf("%v", err)
	} else {
		log.Println("Server closed!")
	}
}
