/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbonvin <qbonvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:28:14 by qbonvin           #+#    #+#             */
/*   Updated: 2022/06/10 13:44:19 by qbonvin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool mustExit = false;

// La fonction sur laquelle vont démarrer nos deux threads
int threadMain( void * data ) {
    const char * threadName = (const char *) data;
    while( ! mustExit ) {
        printf( "%s\n", threadName );
    }
    printf( "%s terminé !\n", threadName );
    return thrd_success;
}


int main() {

    // On crée un premier thread.
    thrd_t thread1;
    void * threadName1 = (void *) "Mon premier thread";
    if ( thrd_create( &thread1, threadMain, threadName1 ) != thrd_success ) {
        fprintf( stderr, "Impossible de créer le premier thread\n" );
        return EXIT_FAILURE;
    }

    // On crée un second thread.
    thrd_t thread2;
    void * threadName2 = (void *) "Mon second thread";
    if ( thrd_create( &thread2, threadMain, threadName2 ) != thrd_success ) {
        fprintf( stderr, "Impossible de créer le second thread\n" );
        return EXIT_FAILURE;
    }

    // Appuyez sur la touche <ENTER> pour stopper le programme.
    char ch;
    scanf( "%c", &ch );
    
    // Tous les threads d'un même processus partagent la même zone de mémoire.
    // Les deux threads doivent donc voir cette variable et se suspendrent
    // quand cela sera nécessaire.
    mustExit = true;

    // On sort du programme.
    printf( "Le thread initial/principal s'arrête.\n" );
    return EXIT_SUCCESS;
}