#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <matheval.h>
#include <assert.h>

#define BUFFER_SIZE 256
#define NODES_NUM 10
#define EOS '\0'
#define WSPACE ' '

/* dom_vector, fun_vector are the vectors required to return the array of calculalted
 * data
 * count represent the length of the 2 arrays, if it's zero the count it's automaticcaly calculated
 * by array_length(), otherwise you can pass a default length
 */

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

int parse_eq(char *eq_str, double *dom_vector, double *fun_vector, int count);
int array_length (double *array);

/* creating variables for parser */
void            *f;
int             count,
                length;
char            **var_names;


#ifdef __cplusplus
}
#endif // __cplusplus
#endif
