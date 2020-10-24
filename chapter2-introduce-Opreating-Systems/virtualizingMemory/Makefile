obj = ../../common.o mem.o 
target = mem
CC = gcc  

${target}: ${obj}
	${CC} ${obj} -o ${target} -Wall -Wl,-no_pie

../../common.o: ../../common.c
	${CC} -c $< -o $@

mem.o: mem.c
	${CC} -c -I ../../ $< -o $@

		
.PHONY: clean  
clean:  
	rm -rf $(obj) $(target)