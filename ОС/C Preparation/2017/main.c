#include <stdio.h>
#include <fcntl.h>

int main( int argc, char * argv[])
{
    int fdi, fdo, k,broi, i = 0 , status;
    char buff [ 40 ], c ;
    if ( ( fdi = open ("file.txt", O_RDWR ) ) == -1 )    // Tries to open the file.txt for Read-Write. On failure exit the program
    { printf ("\n Cannot open \n" ); exit (1); }
    if ( ( fdo= open (argv[1], O_CREAT| O_TRUNC| O_RDWR, 0666) ) == -1 )    // Tries to create(and overwrite) file named as the argv[1] for Read-Write. On failure exit the program
    { printf ("\n Cannot open \n" ); exit (1); }
    if ( fork() == 0 ) {    // Start new process. We are in the child process
        k=dup(1); close(1); dup(fdi);    // Change the standard output to be the input file. Store the previous in k.
        broi = read ( fdi , buff, 40 );    // Try to read 40 symbols form the file
        c = buff[ i++];    // Get symbol buff[0]. Increment i afterwards.
        //printf("%c", c);
        if ( c <= '0' || c >= '9' ) {
            while ( buff [ i ++] != '\n' && i < broi )    // While we haven't reached a new line and there are still characters left to process
                write ( 1, "*", 1 );    // Write "*" number of characters until new line times to the output which is the fdi
            write ( 1, "\n", 1 );    // Write new line 
            close(1); dup(k);    // Close the current standard output and change it back
            write ( 1, buff, 3 );    // Print to the standard output the first 3 chars pointed by buff
            write ( fdo, buff, 10 );    // Write to the output file the first 10 chars pointed by buff
        }
        else { 
            write( 1, buff, broi ); close(1);dup(k);
            write ( 1, "*\n", 2 );
        }
        
        lseek( fdo,0, 0); // Return to the start of the output file
        write ( fdo, "*\n", 2 );    // Overwrite  2 chars - "*\n" in the output file starting from the current pointer(i.e. ab becomes *\n)
        close ( fdi); close (fdo);    // Close the file descriptors
    }
    else { 
        wait ( &status);    // Wait for the child process to exit
        close(1); dup(fdi);    // Close the standard output and move it to fdi
        execlp ("grep", "grep", "c", argv[1], 0 );    // Execute grep command on the param file and put the output of it in fdi, i.e. write cdef in the input file
        execlp ("wc", "wc", "-l", "ff" , 0 );
    }
    return 0;
}