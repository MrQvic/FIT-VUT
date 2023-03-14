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
#include <math.h>

int main(int argc, char** argv) {

    printf("Zadejte postupně koeficienty a,b,c kvadratické rovnice ax^2+bx+c=0 : \n");
    double a;
    scanf(" %lf", &a);
    double b;
    scanf(" %lf", &b);
    double c;
    scanf(" %lf", &c);

    if (a != 0)
    {
        // výpočet diskriminantu
        double d = b * b - 4 * a * c;
        if (d < 0)
            printf("Neexistuje řešení v oblasti reálných čísel");
        else if (d == 0)
        {
            double x = -b / (2 * a);
            printf("Rovnice má jeden kořen x = %f", x);
        }
        else
        {
            double x1 = (-b + sqrt(d)) / (2 * a);
            double x2 = (-b - sqrt(d)) / (2 * a);
            printf("Rovnice má 2 reálné kořeny x1 = %f, x2 = %f", x1, x2);
        }
    }
    else
        printf("Není kvadratická rovnice \n"); // pro zjednodušení se komplexními kořeny nebudeme zabývat
    
    return (EXIT_SUCCESS);
}

