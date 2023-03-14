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
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    char odp;
    printf("Vyber si nějakou postavu ze Simpsonových \n");
    
    printf("a) Homer \n");
    printf("b) Bart \n");
    printf("c) Marge \n");
    printf("d) Líza \n");
    printf("e) Maggie \n");
    
    scanf(" %c", &odp);
    switch(odp)
    {
        case 'a':
            printf("Jméno: Homer Simpson \n");
            printf("Věk: 39 \n");
            printf("Zaměstnání: bezpečnostní technik ve springfieldské jaderné elektrárně  \n");
            break;
        case 'b':
            printf("Jméno: Bart Simpson \n");
            printf("Věk: 10 \n");
            printf("Zaměstnání: student  \n");
            break;
        case 'c':
            printf("Jméno: Marge Simpson \n");
            printf("Věk: 34 \n");
            printf("Zaměstnání: v domácnosti  \n");
            break;
        case 'd':
            printf("Jméno: Líza Simpson \n");
            printf("Věk: 8 \n");
            printf("Zaměstnání: student  \n");
            break;
        case 'e':
            printf("Jméno: Maggie Simpson \n");
            printf("Věk: 1 \n");
            printf("Zaměstnání: žadný  \n");
            break;
    }
    return (EXIT_SUCCESS);
}

