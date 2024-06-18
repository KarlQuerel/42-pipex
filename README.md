<a id="top"></a>

# pipex
The `pipex` project is designed to teach students about inter-process communication using pipes in a UNIX environment. The goal is to reproduce the behavior of the shell pipeline `|` operator.

## Table of Contents
- [Description](#description)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Project Structure](#project-structure)
- [Examples](#examples)

## Installation
1. Clone this repository to your local machine:
	```sh
	git clone https://github.com/yourusername/pipex.git
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
- **outfile**:	the output file.

The program will execute cmd1 **with infile as input**, and then pass the output of cmd1 as input to cmd2, finally writing the result **to outfile as output**.

## Example
```sh
./pipex infile "ls -l" "grep pipex" outfile
```
This example will:
- **ls -l**: list the contents of the current directory in long format
- **grep pipex**: filter the results to include only lines containing the word "pipex"
- write the final ouput in a created file named "outfile"

For more information, refer to the [subject PDF](https://github.com/KarlQuerel/42-pipex/blob/master/docs/en.subject.pdf).

[Back to Top](#top)