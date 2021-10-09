# minitalk
 [![Intro](https://img.shields.io/badge/Cursus-Minitalk-success?style=for-the-badge&logo=42)](https://github.com/mlanca-c/Minitalk)<br>
The purpose of this project is to code a small data exchange program using UNIX signals. <br>

## Cloning <br>
```
https://github.com/MashkaCoder/minitalk.git
cd minitalk
make
```
## Make commands

- `make` to compile mandatory part. <br>
- `make bonus` to compile with bonuses(ACK and UNICODE). <br>
- `make clean` to clean all object files of libft. <br>
- `make fclean` to remove executable files. <br>
- `make re` to recompile this project.<br>

## Usage <br>

The server must be launched first, and after being launched it must display its PID. <br>

 ```
 $ ./server
 PID: <PID_SERVER>
 
 (wait)
 ```
 After the server is started, in the second window of the term, start the client, as parameters, give it the server **PID** and the **string** <br>
 
 ```
 $ ./client <PID_SERVER> <STRING>
 ```
 
 ## Subject
 > [subject](subject.pdf)
