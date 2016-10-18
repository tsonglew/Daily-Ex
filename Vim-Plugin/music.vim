function! Music()
python << EOF

import sys
sys.path.append('/usr/local/lib/python2.7/site-packages')

import pyglet
import time
import os
song = pyglet.media.load('/Users/kasheemlew/Documents/Daily-Ex/Vim-Plugin/test.ogg')
song.play()
pyglet.app.run()

start_time=time.clock()
while True:
    now_time=time.clock()
    if now_time > start_time+5:
        os.system('pkill -9 vim')
        break

EOF
endfunction
