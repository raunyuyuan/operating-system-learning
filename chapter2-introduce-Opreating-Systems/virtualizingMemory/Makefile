obj = ../../common.o mem.o 
target = mem
CC = gcc -I ../../

${target}: ${obj}
	${CC} ${obj} -o ${target}

$.o: %.c
	${CC} -c $< -o $@

# ../../common.o: ../../common.c
# 	gcc -c ../../common.c -o ../../common.o

# cpu.o: cpu.c
# 		gcc -I ../../ -c cpu.c -o cpu.o


	
		
		
.PHONY: clean  
clean:  
	rm -rf $(obj) $(target)