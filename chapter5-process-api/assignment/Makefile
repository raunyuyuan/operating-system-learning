target = 2
source = ${target}.c
oSoucre = ${target}.o


${target}: ${oSoucre}
	gcc ${oSoucre} -o ${target}
	chmod 765 ${target}

${oSoucre}: ${source}
	gcc -c ${source}

clean:  
	rm -rf ${oSoucre} ${target}