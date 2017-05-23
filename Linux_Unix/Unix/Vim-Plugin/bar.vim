function! Bar()
python << EOF

import vim
cur_buf = vim.current.buffer
print(len(cur_buf))
print(cur_buf[-1])

EOF
endfunction
