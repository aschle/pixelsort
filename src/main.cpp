#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "../include/read_write.h"
#include "../include/sorting_context.h"
#include "../include/sorting.h"

#define ARG_ROW "row"
#define ARG_COLUMN "col"
#define ARG_BOTH "both"

#define ARG_DARK "dark"
#define ARG_LIGHT "light"
#define ARG_ALL "all"

#define ARG_AVG "avg"
#define ARG_MUL "mul"
#define ARG_MAX "max"
#define ARG_MIN "min"
#define ARG_XOR "xor"

using namespace std;

int main(const int argc, const char* argv[]) {
	if(argc < 6) {
		printf("usage: pixelsort [orientation] [method] [comparator] <in.png> <out.png>\n");
		printf("\n");
		printf("orientation:\n");
		printf("  row\n");
		printf("  col\n");
		printf("  both\n");
		printf("\n");
		printf("method:\n");
		printf("  all\n");
		printf("  dark\n");
		printf("  threshold\n");
		printf("\n");
		printf("comparator:\n");
		printf("  avg\n");
		printf("  mul\n");
		printf("  max\n");
		printf("  min\n");
		printf("  xor\n");
		printf("\n");
		return 1;
	}

	// Set up the argument strings
	const char * orientation = argv[1];
	const char * method = argv[2];
	const char * comparator = argv[3];
	const char * source = argv[4];
	const char * destination = argv[5];

	// printf("Using orientation: %s\n", orientation);
	// printf("Using method: %s\n", method);
	// printf("Using comparator: %s\n", comparator);
	// printf("Using source: %s\n", source);
	// printf("Using destination: %s\n", destination);

	struct Image * image = read_image(source);
	struct PixelSortingContext * ctx = create_context();

	set_sort_direction(ctx, ASC);

	if(0 == strcmp(ARG_ROW, orientation)) {
		set_orientation(ctx, ROW);
	} else if(0 == strcmp(ARG_COLUMN, orientation)) {
		set_orientation(ctx, ROW);
	} else {
		set_orientation(ctx, BOTH);
	}

	if(0 == strcmp(ARG_DARK, method)) {
		set_run_type(ctx, DARK);
		set_threshold(ctx, /*DARK,*/ 45);
	} else if(0 == strcmp(ARG_LIGHT, method)) {
		set_run_type(ctx, LIGHT);
		set_threshold(ctx, /*LIGHT,*/ 210);
	} else {
		set_run_type(ctx, ALL);
	}

	if(0 == strcmp(ARG_AVG, comparator)) {
		set_comparison(ctx, AVG);
	} else if(0 == strcmp(ARG_MUL, comparator)) {
		set_comparison(ctx, MUL);
	} else if(0 == strcmp(ARG_MAX, comparator)) {
		set_comparison(ctx, MAX);
	} else if(0 == strcmp(ARG_MIN, comparator)) {
		set_comparison(ctx, MIN);
	} else {
		set_comparison(ctx, XOR);
	}

	sort(image, ctx);

	write_image(image, destination);
}
