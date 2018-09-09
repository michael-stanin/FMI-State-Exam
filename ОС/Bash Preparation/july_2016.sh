br=1 # br = 1
br=`expr $br \* $2` # br = br * 3, i.e. br=3
a=$3 # a=5
set ab bc cd de # we set new env vars ab bc cd de, makes them as new positional arguments
shift # shift the env vars (remove the 1st parameter)  so we have only bc cd de
while true
do echo $* # prints the positional parameters
    for j # for every of the positional parameter, i.e. (bc, cd, de)
    do if test $# -lt $br # test if the number of positional parameters (3) is less than br=3 - it is not true
        then br=`expr $br / 2` # update br - br=br/2 => br=1
        echo $br $j >> file  # 1 bc >> appended to file
    else
        br=`expr $br + $a` # br = br+5=8
        echo $br $j >> file # 8 bc\n appended to the file
        fi
    done
    # at the end in the file we will have:
    # "8 bc
    # 4 cd
    # 2 de
    # 
    # "
break
done
read a1 a2 # we read the symbols 'c' and 'd' from the stdin
while cat file | grep $a1 # concatenate(print) the contents of file with CR(with a new line at the end)
                          #|- means to use the output of the previous command as input for the next one, i.e. the printed text from the file
# prints every line containing 'c' with new line after each one:
#"8 bc
#4 cd
#"
do echo $a $a2 # prints 5 and 'd' 
    #"5 d
    #"
    wc -l file # reads the lines in file, i.e. 3 and prints them
    tail -5c file # prints the last 5 characters (-5c), i.e. '2 de\n'
    exit # finishes the program
    echo FIN
done
echo $a $a1
wc -c file
tail -2l file