obj = ../../common.o cpu.o 
target = cpu
CC = gcc -I ../../

${target}: ${obj}
	${CC} ${obj} -o ${target}

$.o: %.c
	${CC} -c $< -o $@

.PHONY: clean  
clean:  
	rm -rf $(obj) $(target)