#gcc -o mag-slash -ggdb mag-slash.c
# Makefile for MAG-SLASH 
# Douglas Berdeaux
# 2015 WeakNet Labs
mag-slash:src/mag-slash.c
	rm -rf bin
	mkdir bin
	gcc -std=gnu99 -o bin/mag-slash -ggdb src/mag-slash.c
install:
	cp mag-slash /usr/local/bin
uninstall:
	rm /usr/local/bin/mag-slash
clean:
	rm bin/mag-slash
