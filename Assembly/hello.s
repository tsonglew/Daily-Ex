.data
        msg : .string "Hello, world!\\n"
        len = . - msg
.text
.global _start

_start:
        movl $len, %edx
        movl $msg, %ecx
        movl $1, %ebx
        movl $4, %eax      # 系统调用功能号放在寄存器eax中
        int $0x80          # 中断

        movl $0,%ebx
        movl $1,%eax       # 系统调用完成后返回值在寄存器eax中获得
        int $0x80
