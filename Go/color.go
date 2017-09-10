package main

import (
	"flag"
	"fmt"
	"image/color"
	"strconv"
)

func main() {
	background := flag.String("bg", "000000", "background color")
	foreground := flag.String("fg", "ffffff", "foreground color")
	flag.Parse()
	draw(parseColor(*foreground), parseColor(*background))
}

func parseColor(s string) color.Color {
	v, _ := strconv.ParseInt(s, 16, 64)
	b := uint8(v % 256)
	g := uint8((v / 256) % 256)
	r := uint8((v / (256 * 256)) % 256)
	return color.RGBA{R: r, G: g, B: b, A: 255}
}

func strColor(c color.Color) string {
	r, g, b, a := c.RGBA()
	r, g, b, a = r/256, g/256, b/256, a/256
	return fmt.Sprintf("rgba(%v, %v, %v, %v)", r, g, b, a)
}

func draw(fg, bg color.Color) {
	fmt.Printf("draw with foreground %s background %s", strColor(fg), strColor(bg))
}
