# BTP-200 Seneca College

These are simple C++ projects created as assignments in the Second Semester of College.

The main goal of the projects is to practice C++ syntax and produce working code without errors or memory leaks.

Some of the projects contain simple mathematical work, input processing, error checking, memory handeling, inheritance & polymorphism, templated classes & functions, file processing, and output formatting.

Some of the projects contain data files which are being processed in that specific project.

<br/>
<br/>
<br/>
To compile any of the individual projects use the Command:

<br/>
** For G++: **

```bash
g++ -Wall -o output.o *.cpp
valgind output.o        #optional
output
```

** For Clang: **

```powershell
cl /W4 *.cpp /out:output.exe
./output.exe
```

[Valgrind](https://valgrind.org/) is a Linux-only tool for C++ memory leak checking and is very useful for development.<br/>
It can be used on Windows with either installing WSL, Mingw, or Cygwin.<br/>
Valgrind is not a dependancy and can be ignored from the Build & Run Command.<br/>
