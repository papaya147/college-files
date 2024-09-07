import socket


def server_program():
    host = socket.gethostname()
    port = 4500

    server_socket = socket.socket()
    server_socket.bind((host, port))

    server_socket.listen(1)
    print("Server started. Waiting for connections...")

    client_socket, address = server_socket.accept()
    print("Connection from:", address)

    while True:
        data = client_socket.recv(1024).decode('utf-8')
        print("Client:", data)

        if data.lower() == "bye" or data.lower() == "exit":
            break

        message = input("Server: ")
        client_socket.send(message.encode('utf-8'))

    client_socket.close()
    server_socket.close()


if __name__ == '__main__':
    server_program()
