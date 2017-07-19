// frt_options.cpp
/*
 * FRT - A Godot platform targeting single board computers
 * Copyright (c) 2017  Emanuele Fornara
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "frt.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

namespace frt {

void usage(const char *program_name, int code = 1) {
	printf("\n"
		   "usage: %s [godot args] [--frt [options]]\n"
		   "\n"
		   "options:\n"
		   "  -v                  show version and exit\n"
		   "  -h                  show this page and exit\n"
		   "\n",
		   program_name);
	exit(code);
}

void parse_frt_args(int argc, char **argv) {
	const char *program_name = argv[0];
	for (int i = 1; i < argc; i++) {
		const char *s = argv[i];
		if (!strcmp(s, "-v")) {
			printf("frt 0.9.1\n");
			exit(0);
		} else if (!strcmp(s, "-h")) {
			usage(program_name, 0);
		} else {
			usage(program_name);
		}
	}
}

void App::parse_args(int *argc, char ***argv) {
	for (int i = 1; i < *argc; i++)
		if (!strcmp((*argv)[i], "--frt")) {
			(*argv)[i] = (*argv)[0];
			int frt_argc = *argc - i;
			char **frt_argv = &(*argv)[i];
			parse_frt_args(frt_argc, frt_argv);
			*argc = i;
			break;
		}
}

} // namespace frt