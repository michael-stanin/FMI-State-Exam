#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>


void july_2017(char * argv[])
{
	/*  *file.txt*		
		abcdef
		0123456789
		ABCD
	*/
	int fdi, fdo, k, broi, i = 0, status; // initialize variables
	char buff[40], c; // -- // --
	if ((fdi = open("file.txt", O_RDWR)) == -1) // open for read/write - if -1 is returned, file can't be opened - the program finishes
	{
		printf("\n Cannot open \n"); exit(1);
	}

	if ((fdo = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0666)) == -1) // creates file named with the first argument (ff). clears it if it existed and opens it for read/write
	{
		printf("\n Cannot open \n"); exit(1);
	}

	if (fork() == 0) // In case of the child process
	{
		k = dup(1); close(1); dup(fdi); // copy the stdout and close it. change the stdout to point to the fdi (file.txt) and dup writes new line in the file?!
		broi = read(fdi, buff, 40); // read the first 40 chars from the file and store them in buff. in our case broi will be equal to 22 - all chars + '\n' * 2
		/*
		buff: abcdef\n\n0123456789\nABCD
		*/
		c = buff[i++]; // assign c the 0th (i == 0) character and then increment i. c == 'a'
		if (c <= '0' || c >= '9') // if we read a character which is not a digit
		{
			while (buff[i++] != '\n' && i < broi) // reads bcdef
				write(1, "*", 1); // for every char bcdef write a '*' into file.txt
			/*
			file.txt = 
			"abcdef
			0123456789
			ABCD
			*****"
			*/
			write(1, "\n", 1); // write a new line in file.txt
			/*
			file.txt =
			"abcdef
			0123456789
			ABCD
			*****

			"
			*/
			close(1); dup(k); // close the file and return the to the std out
			write(1, buff, 3); // prints first 3 symbols of buff to the stdout, i.e. "abc"
			write(fdo, buff, 10); // write to fdo the first 10 symbols of buff "abcdef\n012"
			/*
			ff =
			"abcdef
			012"
			*/
		}
		else {
			write(1, buff, broi); close(1); dup(k);
			write(1, "*\n", 2);
		}
		lseek(fdo, 0, 0); // return the pointer to the absolute 0 pointer.
		write(fdo, "*\n", 2); // overwrites the first two symbols of fdo with *\n
		/*
		ff =
		"*
		cdef
		012"
		*/
		close(fdi); close(fdo); // closes the file descriptors
	}
	else {
		wait(&status); // waits for the child process to complete
		close(1); dup(fdi); // close the std out, redirect the std out to fdi (file.txt)
		execlp("grep", "grep", "c", argv[1], 0); // write the result of "grep c ff" into file.txt (appends it to the end??) and end the program
		execlp("wc", "wc", "-l", "ff", 0);
	}

	/* At the end
	file.txt =
	"abcdef
	0123456789
	ABCD
	*****

	cdef"

	ff =
	"*
	cdef
	012"

	stdout:
	"abc"
	*/
}

main(int argc, char * argv[])
{
	july_2017(argv);
}