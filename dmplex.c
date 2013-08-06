/*
 * simple dzen multiplexer
 *
 * Copyright (C) 2013 by qbbr <r2 dot kenny at gmail dot com>
 * Copyright (C) 2008 by Robert Manea  <rob dot manea at gmail dot com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * compile-command: "gcc -Wall dmplex.c -o dmplex"
 *
 * use:
 *   mkfifo pipe
 *   tail -f pipe | dmplex | dzen2
 *   echo "1 foo" > pipe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IN_LEN   8192
#define MAX_SECTIONS 1024
#define SEPARATOR    " "

char tbuf[MAX_IN_LEN];
char nbuf[MAX_IN_LEN];
char *section[MAX_SECTIONS];

int main(int argc, char *argv[])
{
	int i, snr, slen, prev;

	while (fgets(tbuf, MAX_IN_LEN, stdin)) {
		for (i = 0; i < MAX_IN_LEN && tbuf[i] != ' '; i++) {
			nbuf[i] = tbuf[i];
		}
		nbuf[i] = 0;
		snr = atoi(nbuf);

		if (snr < MAX_SECTIONS) {
			if (section[snr])
				free(section[snr]); slen = strlen(tbuf + i);
			section[snr] = calloc(slen, sizeof(char));

			if (tbuf[i + slen - 1] == '\n')
				tbuf[i + slen - 1] = 0; strncpy(section[snr], tbuf + i + 1, slen);

			prev = 0;
			for (i = 0; i < MAX_SECTIONS; i++) {
				if (section[i]) {
					if (i > 0 && prev) {
						printf(SEPARATOR);
					}
					prev = 1;
					printf("%s", section[i]);
				}
			}
			printf("\n");
			fflush(stdout);
		}
	}

	return EXIT_SUCCESS;
}
