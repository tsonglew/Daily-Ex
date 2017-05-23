import pyglet
import time
import os
song = pyglet.media.load('/Users/kasheemlew/Documents/Daily-Ex/Vim-Plugin/test.ogg')
song.play()
pyglet.app.run()

start_time=time.clock()
pyglet.app.exit()
