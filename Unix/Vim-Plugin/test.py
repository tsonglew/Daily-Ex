import sys
sys.path.append('/usr/local/lib/python2.7/site-packages')

import pyglet
import time
import os
song = pyglet.media.load('/Users/kasheemlew/Documents/Daily-Ex/Vim-Plugin/test.ogg')
song.play()
pyglet.app.run()
