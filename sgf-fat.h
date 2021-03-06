
#ifndef __SGF_FAT__
#define __SGF_FAT__


/**********************************************************************
 *
 *  ROUTINES DE MANIPULATION DE LA FAT (File Allocation Table)
 *
 *********************************************************************/

#define FAT_FREE                (-1)
#define FAT_RESERVED            (-2)
#define FAT_INODE               (-3)
#define FAT_EOF                 (-4)


/**********************************************************************
 Rechercher un bloc libre sur le disque en parcourant la FAT. Cette
 fonction renvoie 0 en cas d'erreur.
 *********************************************************************/

    int alloc_block (void);

/**********************************************************************
 Lire/Ecrire l'entr�e num�ro "n" dans la FAT du disque.
 Ces fonctions ne g�n�rent aucune erreur.
 *********************************************************************/

    int get_fat (int n);
    void set_fat (int n, int valeur);

/**********************************************************************
 Charger la FAT d'un disque en m�moire pour que ce disque soit
 utilisable (mont�).
 *********************************************************************/

    void init_sgf_fat (void);

/**********************************************************************
 Formater le disque en �crivant une FAT vide sur disque.
 Ces fonctions ne g�n�re aucune erreur.
 *********************************************************************/

    void create_empty_fat (void);

/*
*
*/
    unsigned get_free_fat_blocks_count();

    struct DiskStats getDiskStats();

    void displayFatMap();

    struct DiskStats{
    unsigned nb_free_blocks;
    unsigned nb_reserved_blocks;
    unsigned nb_eof_blocks;
    unsigned nb_inode_blocks;
    unsigned nb_data_blocks;
    unsigned nb_free_bytes;
	};


#endif
