/**
 * Created by mamour on 18/10/16.
 */

#include "myfunctions.h"


int main(int argc, char **argv) {
    // Test sur le nombre d'arguents
    if (argc != 3) {
        printf("Erreur sur le mombre d'arguments\n");
        exit(-1);
    } else {
        int src, dst;
        char buf[TAILLE_BUF];
        src = my_open(argv[1], O_RDONLY, 0644);
        dst = open(argv[2], O_WRONLY | O_CREAT, 0644);
        //Boucle de copie
        while (1) {
            ssize_t nboctet_read = my_read(src, buf, sizeof(buf));
            if (nboctet_read == 0) break;
            my_write(dst, buf, nboctet_read);
        }
        close(src);
        close(dst);
        printf("Copie du fichier : OK\n");
        return 0;
    }
}