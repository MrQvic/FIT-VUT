#include <stdio.h>
#include <stdlib.h>



int obsah_obdelniku(int sirka, int vyska)
{
    int vysledek = sirka * vyska;
    return vysledek;
}

int main(int argc, char** argv) {

int obsah = obsah_obdelniku(10, 20);
printf("Obsah obdélníku je: %d cm^2", obsah);
	return (EXIT_SUCCESS);
}
