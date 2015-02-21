CC=gcc
DEST=/usr/local/bin

.PHONY: install uninstall clean

bincat:
	$(CC) -o bincat bincat.c

install: bincat
	install bincat $(DEST)

uninstall:
	rm $(DEST)/bincat

clean:
	rm bincat
