# Minitalk

Minitalk is a simple client-server application written in C that allows communication between two processes using only signals.
This project demonstrates inter-process communication (IPC) through signal handling in Unix-like operating systems.

## How to Use

1. **Compile:**
   - Open a terminal window.
   - Navigate to the directory containing the source files.
   - Run the following command to compile both the server and client:
   - server Pid will be printed
     ```
     make
     ```

2. **Run the Server:**
   - In the terminal, execute the following command to start the server:
     ```
     ./server
     ```

3. **Run the Client:**
   - Open another terminal window.
   - Execute the client binary with the server's process ID as an argument:
     ```
     ./client [server_pid] "string"
     ```
     Replace `[server_pid]` with the process ID of the server obtained in step 2.

4. **Communication:**
   - Once both the server and client are running, they are ready to communicate.
   - The client sends a message to the server by passing signals.
   - The server receives the signals, decodes them, and prints the message.

## Important Notes

- The communication is one-way from the client to the server.
- Messages sent by the client are limited to ASCII characters.
- Ensure that the server is running before starting the client.
- The server must be running on the same machine.

## Example

1. Compile the source files as mentioned in step 1.
2. Start the server in one terminal:
3. 3. In another terminal, run the client with the server's process ID:
4. Enter a message in the client terminal and press Enter.
5. Check the server terminal to see the received message.

## Files

- `server.c`: Contains the server implementation.
- `client.c`: Contains the client implementation.
- `README.md`: This file, providing instructions and information about the project.
