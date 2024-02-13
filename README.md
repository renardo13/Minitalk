## Minitalk
Preliminary notions to go throught Minitalk project

The project minitalk is about a discussion between two programs named clients and a server. The server receive informations from the client which send to him signals that has to be handle. 
A signal is a numeric value - behind a constant - send  to a running process in order to stop a process and execute an action. 
All running process have a PID (an identifiant) and you have to print PID's server and enter it in the parameters of the client program.

First of all, you can read this page that explained how works Unix signals http://brunogarcia.chez.com/Unix/Docs/Signaux.html.
You have to use the <signal.h> librairy. In this librairy you have a structure that contains 3 elements.

.sa_handler --> 

.

#Bitwise operations

AND
----------------------
  0101 (decimal 5)   |
  & 0011 (decimal 3) |
  = 0001 (decimal 1) |
----------------------

OR
----------------------
  0101 (decimal 5)   |
 | 0011 (decimal 3)  |
 = 0111 (decimal 7)  |
----------------------


for the project, you have to know about bitwise operations. Web page in french https://zestedesavoir.com/tutoriels/755/le-langage-c-1/notions-avancees/manipulation-des-bits/ . It is more simple 
to manipulate bits without "mask" (that would have allow us to use = and other operations) because the syntax and the concept are bit difficult. That's why, for the project, I used logic operations and compared bit by bit with binary value (0 or 1) to "extract" the bit
for the client who reveive the string in parameter. And I use comparaison also for the server, when I receive individualy bit because my char will be initialized at 00000000.
