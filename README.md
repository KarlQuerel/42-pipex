<a id="top"></a>

# pipex
The `pipex` project is designed to teach students about inter-process communication using pipes in a UNIX environment. The goal is to reproduce the behavior of the shell pipeline `|` operator.

## Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Introduction
The `so_long` project aims to introduce students to:
- Understanding and utilizing Unix system calls
- Managing multiple processes and inter-process communication (IPC)
- Handling file descriptors and redirection of input/output
- Creating and managing pipelines between processes
- Error handling and debugging in a Unix environment

## Installation
1. Clone this repository to your local machine:
	```sh
	git clone https://github.com/KarlQuerel/42-pipex.git
	```

2. Navigate to the project directory:
	```sh
	cd pipex
	```

3. Compile the project using `make`:
	```sh
	make
	```

## Usage
The `pipex` program should be run with the following syntax:
```sh
./pipex infile cmd1 cmd2 outfile
```
- **infile**:	the input file.
- **cmd1**:		the first command to execute.
- **cmd2**:		the second command to execute.
- **outfile**:	the output file (that will be created if not present).

The program will execute cmd1 **with infile as input**, and then pass the output of cmd1 as input to cmd2, finally writing the result **to outfile as output**.

## Example
```sh
./pipex infile "ls -l" "wc -l" outfile
```
This example will:
- **`ls -l`**: list the contents of the current directory in long format
- **`wc -l`**: count the number of lines in the output of `ls -l`
- write the final ouput in a created file named "outfile"

For more information, refer to the [subject PDF](https://github.com/KarlQuerel/42-pipex/blob/master/docs/en.subject.pdf).

[Back to Top](#top)
