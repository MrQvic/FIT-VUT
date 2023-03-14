/*  _____ _______         _                      _
 * |_   _|__   __|       | |                    | |
 *   | |    | |_ __   ___| |___      _____  _ __| | __  ___ ____
 *   | |    | | '_ \ / _ \ __\ \ /\ / / _ \| '__| |/ / / __|_  /
 *  _| |_   | | | | |  __/ |_ \ V  V / (_) | |  |   < | (__ / /
 * |_____|  |_|_| |_|\___|\__| \_/\_/ \___/|_|  |_|\_(_)___/___|
 *                                _
 *              ___ ___ ___ _____|_|_ _ _____
 *             | . |  _| -_|     | | | |     |  LICENCE
 *             |  _|_| |___|_|_|_|_|___|_|_|_|
 *             |_|
 *
 * IT ZPRAVODAJSTVÍ  <>  PROGRAMOVÁNÍ  <>  HW A SW  <>  KOMUNITA
 *
 * Tento zdrojový kód je součástí výukových seriálů na
 * IT sociální síti WWW.ITNETWORK.CZ
 *
 * Kód spadá pod licenci prémiového obsahu a vznikl díky podpoře
 * našich členů. Je určen pouze pro osobní užití a nesmí být šířen.
 * 
*/
#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char odp;
    printf("Vítej v mém kvízu... \n");
    printf("-------------------------------------- \n");
    printf("\n1. Kdo založil Microsoft? \n");
    printf("a) Steve Jobs \n");
    printf("b) Tim Cook \n");
    printf("c) Bill Gates \n");
    printf("d) Mark Zuckerberg \n");
    scanf(" %c", &odp);
    if(odp == 'c' || odp == 'C')
    {
        printf("Správně");
        printf("\n2. Kdo vlastní MySQL?  \n");
        printf("a) Microsoft \n");
        printf("b) Apple \n");
        printf("c) Google \n");
        printf("d) Oracle \n");
        scanf(" %c", &odp);
        if(odp == 'd' || odp == 'D')
        {
            printf("Správně");
            printf("\n3. Jaký je code name pro Android 5? \n");
            printf("a) Kit Kat \n");
            printf("b) Lollipop \n");
            printf("c) Cupcake \n");
            printf("d) Jelly bean \n");
            scanf(" %c", &odp);
            if(odp == 'b' || odp == 'B')
                printf("Správně");
            else
                printf("Špatně, skončil jsi");
        }
        else
            printf("Špatně, skončil jsi");
    }
    else
        printf("Špatně, skončil jsi");
    return (EXIT_SUCCESS);
}

