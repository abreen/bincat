#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define LNIBBLE(x) x & 0xf
#define HNIBBLE(x) x >> 4

int main(int argc, char *argv[])
{
	int fd;
	int rv;
	int r, c;
	char b;

	if (argc < 2) {
		fprintf(stderr, "error: specify a file\n");
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	r = 0, c = 0;
	while (1) {
		printf("%d:\t", r);

		for (c = 0; c < 8; c++) {
			rv = read(fd, &b, 1);

			if (rv <= 0)
				goto done;

			printf("%x%x ", HNIBBLE(b), LNIBBLE(b));
		}

		r += 8;
		printf("\n");
	}

done:
	printf("\n");
	close(fd);
	return 0;
}
