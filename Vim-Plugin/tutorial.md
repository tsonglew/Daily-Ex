# Vim Plugin Tutorial

## Before developing

check whether vim supports python

`vim --version | grep +python`

## During developing

create file `vimmit.vim`

1. check whether python is supported. If not, errors would be thrown

```
if !has('python')
    echo "Error: Required vim compiled with +python"
    finish
endif
```

2. main function

```
function! MyFunction()

python << EOF

--->Write your Python code here<---
```
