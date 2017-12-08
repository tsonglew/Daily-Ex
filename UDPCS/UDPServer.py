from socket import *

serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('localhost', 12000))
while True:
    msg, clientAddress = serverSocket.recvfrom(2048)
    print("received %r from %r" % (msg, clientAddress))
    modifiedMsg = msg.upper()
    serverSocket.sendto(modifiedMsg, clientAddress)
