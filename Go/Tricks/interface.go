package main


type Sizer interface {
    Size() int64
}

type Sizers []Sizer

func Fits(capacity int64, v Sizer) bool {
    return capacity > v.Size()
}

func IsEmailable(v Sizer) bool {
    return 1<<20 > v.Size()
}

// Size gets the size of a file
func (f *File) Size() int64 {
    return f.info.Size()
}

func (s Sizers) Size() int64 {
    var total int64
    for _, sizer := range s {
        total += sizer.Size()
    }
    return total
}
