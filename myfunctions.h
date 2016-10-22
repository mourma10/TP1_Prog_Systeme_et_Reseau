/**
 * Created by mamour on 18/10/16.
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_BUF 65536 // 64 * 1024 octets

#ifndef TP1_PROG_SYSTEME_ET_RESEAU_MYFUNCTIONS_H
#define TP1_PROG_SYSTEME_ET_RESEAU_MYFUNCTIONS_H

int my_open(const char *file, int flags, mode_t mode);

void my_fstat(int file, struct stat *buf);

ssize_t my_read(int file, char *buf, ssize_t size);

void my_write(int file, char *buf, ssize_t size);

#endif //TP1_PROG_SYSTEME_ET_RESEAU_MYFUNCTIONS_H
