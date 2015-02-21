#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/errno.h>

#include "bincat.h"

void print_file(char *filename)
{
	int rv, c, fd;
	char b;

	fd = open(filename, O_RDONLY);

	while (1) {
		rv = read(fd, &b, 1);

		if (rv <= 0) {
			printf("\n");
			close(fd);
			return;
		}

		print_bin(&b);
	}

	printf("\n");
}

int main(int argc, char *argv[])
{
	int i, errors = 0;

	if (argc >= 2) {
		for (i = 1; i < argc; i++) {
			if (access(argv[i], R_OK) < 0) {
				fprintf(stderr, "%s: %s\n", argv[i], strerror(errno));
				errors = 1;
			}
		}

		if (errors)
			return 1;

		for (i = 1; i < argc; i++)
			print_file(argv[i]);

	} else {
		fprintf(stderr, "error: specify one or more files\n");
		fprintf(stderr, "usage: %s file1 [file2 ...]\n", argv[0]);
		return 1;
	}
}
