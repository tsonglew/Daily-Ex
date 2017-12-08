from socket import *

serverHostname = "localhost"
serverPort = 12000

clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('Input the message for server: ').encode()
clientSocket.sendto(message, (serverHostname, serverPort))

modifiedMsg, serverAddress = clientSocket.recvfrom(2048)
print('Modified Message: %r from %r' % (modifiedMsg, serverAddress))

clientSocket.close()
