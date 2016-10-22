/**
 * Created by mamour on 18/10/16.
 */

#include "myfunctions.h"

/****************************************
 * @param file                          *
 * @param flags                         *
 * @param mode                          *
 * @return fd descripteur de fichier    *
 ****************************************/
int my_open(const char *file, int flags, mode_t mode) {
    int fd = open(file, flags, mode);
    if (fd == -1) {
        fprintf(stderr, "Erreur d'ouverture[my_open] de %s \n [Erreur]: %s\n", file, strerror(errno));
        exit(-1);
    } else
        return fd;
}

/**********************
 * @param file        *
 * @param buf         *
 **********************/
void my_fstat(int file, struct stat *buf) {
    if (fstat(file, buf) == -1) {
        fprintf(stderr, "Erreur my_fstat\n [Erreur]: %s\n", strerror(errno));
        exit(-1);
    }
}

/*****************************************
 * @param file                           *
 * @param buf                            *
 * @param size                           *
 * @return r ou 0                        *
 *****************************************/
ssize_t my_read(int file, char *buf, ssize_t size) {
    /*ici on utilise l'operateur de cast (size_t) size
     * pour respecter la signature de l'appel systeme read
     */
    ssize_t r = read(file, buf, (size_t) size);
    if (r == -1) {
        fprintf(stderr, "Erreur my_read\n [Erreur]: %s\n", strerror(errno));
        return 0;
    } else return r;

}


/*****************************
 * @param file               *
 * @param buf                *
 * @param size               *
 *****************************/
void my_write(int file, char *buf, ssize_t size) {
    while (size > 0) {
        /*ici aussi on utilise l'operateur de cast (size_t) size
         * pour respecter la signature de l'appel systeme write
         */
        ssize_t w = write(file, buf, (size_t) size);
        if (w == -1) {
            fprintf(stderr, "Erreur my_write\n [Erreur]: %s\n", strerror(errno));
            exit(-1);
        } else {
            size -= w;
            buf += w;
        }
    }
}
