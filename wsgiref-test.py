from wsgiref.simple_server import make_server

def simple_app(environ, start_response):
    start_response('200 OK', [('Content-type', 'text/plain')])
    return ['Hello World!\n']

httpd = make_server('', 8000, simple_app)
print("Server listening on port 8000...")
httpd.serve_forever()
