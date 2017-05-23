function! Reddit()

python << EOF
import vim
import urllib2
import json

TIMEOUT = 20
URL = "https://www.reddit.com/.json"

try:
    # response = urllib2.urlopen(URL, None, TIMEOUT).read()
    # Get data with the method above may cause http error 429, so I turned to the method below
    with open('/Users/kasheemlew/Documents/Daily-Ex/Vim-Plugin/response.json') as f:
        response = f.read()
        json_response = json.loads(response)
        posts = json_response.get("data", "").get("children", "")

        vim.current.buffer[:]

        vim.current.buffer[0] = 80*"-"

        for post in posts:
            post_data = post.get("data", {})
            up = post_data.get("ups", 0)
            down = post_data.get("downs", 0)
            title = post_data.get("title", "NO TITLE").encode("utf-8")
            score = post_data.get("score", 0)
            permalink = post_data.get("permalink").encode("utf-8")
            url = post_data.get("url").encode("utf-8")
            comments = post_data.get("num_comments")

            vim.current.buffer.append("↑ %s" % up)
            vim.current.buffer.append("    %s [%s]" % (title, url,))
            vim.current.buffer.append("↓ %s    | comments: %s [%s]" % (down, comments, permalink,))

            vim.current.buffer.append(80*"-")

except Exception, e:
    print e

EOF
endfunction
command! -nargs=0 Reddit call Reddit()
