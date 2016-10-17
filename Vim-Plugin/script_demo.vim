function! Foo()
python << EOF
class Foo_demo:
    def __init__(self):
        print 'Foo_demo init'
Foo_demo()
EOF
endfunction
