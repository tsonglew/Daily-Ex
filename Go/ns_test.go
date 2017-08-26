package main

import (
    "os"
    "os/exec"
    "syscall"
    "github.com/sirupsen/logrus"
)

func main() {
    switch os.Args[1] {
    case "run":
        run()
    case "child":
        child()
    default:
        panic("not running")
    }
}

func run() {
    logrus.Printf("Running %v", os.Args[1:])
    cmd := exec.Command("/proc/self/exe", append([]string{"child"}, os.Args[2:]...)...)
    cmd.Stdin = os.Stdin
    cmd.Stdout = os.Stdout
    cmd.Stderr = os.Stderr
    cmd.SysProcAttr = &syscall.SysProcAttr{
        Cloneflags: syscall.CLONE_NEWUTS | syscall.CLONE_NEWPID,
    }

    must(cmd.Run())
}

func child() {
    logrus.Printf("Running %v", os.Args[1:])
    cmd := exec.Command(os.Args[2], os.Args[3:]...)
    cmd.Stdin = os.Stdin
    cmd.Stdout = os.Stdout
    cmd.Stderr = os.Stderr
    must(syscall.Sethostname([]byte("container")))
    must(cmd.Run())
}

func must(err error) {
    if err != nil {
        logrus.Printf("Error: %v \n", err)
    }
}
