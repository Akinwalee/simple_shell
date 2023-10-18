#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#define BUFFSIZE 1024


/** Function Prototypes**/
char *read_input(void);
int execute(char **args, char **argv);
int execute_command(char **args, char **argv);
char *path(char *);
char **parseline(char **, char *, ssize_t);
int get_env(void);
extern char **environ;

#endif
