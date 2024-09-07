import socket


def client_program():
    host = socket.gethostname()
    port = 4500

    client_socket = socket.socket()
    client_socket.connect((host, port))

    while True:
        message = input("Client: ")
        client_socket.send(message.encode('utf-8'))

        data = client_socket.recv(1024).decode('utf-8')
        print("Server:", data)

        if data.lower() == "bye" or data.lower() == "exit":
            break

    client_socket.close()


if __name__ == '__main__':
    client_program()
