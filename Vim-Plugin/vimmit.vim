" The Vim plugin to show homepage information of Reddit on Vim dashboard
"
" Check whether Vim supports Python
if !has('python')
    echo "Error: Required vim compiled with +python"
    finish
endif

" Vim comments start with a double quote.
" Function definition is VimL. We can mix VimL and Python in
" function definition.
function! Reddit()

" Start the Python code
python << EOF
import vim
import urllib2
import json
