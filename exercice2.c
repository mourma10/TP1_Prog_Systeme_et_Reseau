/**
 * Created by mamour on 20/10/16.
 */

#include "myfunctions.h"

int main(int argc, char **argv) {
    //Test du nombre d'arguments
    if (argc != 3) {
        printf("Erreur sur le mombre d'arguments\n");
        exit(-1);
    } else {
        int src, dst;
        struct stat src_stat, dst_stat;
        char buf[TAILLE_BUF];
        src = my_open(argv[1], O_RDONLY, 0644);
        my_fstat(src, &src_stat);
        if (S_ISDIR(src_stat.st_mode)) {
            printf("Impossible de copier un repertoire %s\n", strerror(errno));
            exit(-1);
        }
        //Si le fichier destination existe deja
        if (stat(argv[2], &dst_stat) == 0) {
            // On verifie que les fichiers source et destination sont differents
            if (src_stat.st_ino == dst_stat.st_ino && src_stat.st_dev == dst_stat.st_dev) {
                printf("Impossible de copier un fichier sur lui-meme\n [Erreur]: %s", strerror(errno));
                exit(-1);
            }
        }
        //Sinon on cree le fichier destination
        dst = my_open(argv[2], O_WRONLY | O_CREAT, 0644);
        //Test des nom et groupe utilisateur
        if (fchown(dst, src_stat.st_uid, src_stat.st_gid) == -1)
            printf("Impossible de changer l'utilisateur du fichier\n [Erreur]: %s", strerror(errno));
        //Test mode de l'utilisateur
        if (fchmod(dst, src_stat.st_mode) == -1)
            printf("Impossible de changer le mode de l'utilisateur\n [Erreur]: %s", strerror(errno));
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

