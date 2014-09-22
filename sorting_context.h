#ifndef _SORTING_CONTEXT_H
#define _SORTING_CONTEXT_H

// struct pixel_sorting_context;

enum orientation_e { COLUMN, ROW, BOTH };
enum run_type_e { ALL, DARK, LIGHT };
enum comparison_e { AVG, MUL, MAX, MIN, XOR };
enum sort_direction_e { ASC, DESC };

typedef struct pixel_sorting_context {
    enum orientation_e orientation;
    enum comparison_e comparison;
    enum sort_direction_e sort_direction;
    enum run_type_e run_type;
    long threshold;
} pixel_sorting_context_t;

#endif
