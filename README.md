# Keylogger
Repository for the Udemy Course: "Build an Advanced Keylogger using C++ for Ethical Hacking!" with instructor Ermin Kreponic.

Brief Description:
This keylogger captures keyboard strokes using system hooks. It writes the keystrokes to a log file hidden in the AppData folder. This log file is encrypted in case the user somehow locates the log. In addition an email can be sent on a timer with the log file attached.


Upcoming Updates:
The next commit in this repository is to decrypted the encrypted log file saved in at the secure location in the teser disk space. 
This can be done by creating a new project which input a log file to dycrpt it and procudes its output over the console in C++ which will be commited soon in this repository.


My Overview:
I went through the course and followed along with Ermin as we built a keylogger from scratch.  This keylogger is written in C++ and can be used on Windows 7,8,10 machines. I personally built this keylogger on a Windows 10 machine and tested it successfully on it as well. To compile it in CodeBlocks, be sure to enable C++11 standards and the -mwindows flag. Another note: if you're using gmail to test, make sure the "Access for less secure apps" feature is enabled.
