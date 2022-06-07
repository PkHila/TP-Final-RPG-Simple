#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    char nombre[50];
    int maxVida;
    int ataque;
    int defensa;
    int evasion;

} Personaje;

///Prototipados
void turnoIndividual(Personaje atacante, Personaje defensor,int *vidaDefensor);
void turnoCompleto(Personaje a, Personaje b);

int main()
{
    srand(time(NULL));
    //Personaje y CPU
    Personaje jugador, enemigo;

    strcpy(jugador.nombre,"Yuyin");
    jugador.ataque = 1;
    jugador.defensa = 2;
    jugador.evasion = 1;
    jugador.maxVida = 20;

    strcpy(enemigo.nombre,"Ogro");
    enemigo.ataque = 2;
    enemigo.defensa = 1;
    enemigo.evasion = 1;
    enemigo.maxVida = 15;

    turnoCompleto(jugador,enemigo);

    return 0;
}

void turnoIndividual(Personaje atacante, Personaje defensor,int *vidaDefensor)
{

    int dado1 = (rand() % 6 + 1);
    int dado2 = (rand() % 6 + 1);
    int suma = dado1 + dado2;

    printf("Tira %s:\n", atacante.nombre);
    printf("|%d| + |%d| = %d\n",dado1,dado2,suma);
    int atqTotal = suma + atacante.ataque;
    printf("+%d de atq del personaje\n",atacante.ataque);
    printf("Un total de %d!\n",atqTotal);

    dado1 = (rand() % 6 + 1);
    dado2 = (rand() % 6 + 1);
    suma = dado1 + dado2;
    printf("Tira %s:\n", defensor.nombre);
    printf("|%d| + |%d| = %d\n",dado1,dado2,suma);
    int defTotal = suma + defensor.defensa;
    printf("+%d de def del personaje\n",defensor.defensa);
    printf("Un total de %d!\n",defTotal);

    int resultado;
    if(atqTotal <= defTotal)
    {
        resultado = 0;
    }
    else
    {
        resultado = (atqTotal - defTotal);
    }
    printf("Resultado = %d\n\n",resultado);

}

void turnoCompleto(Personaje a, Personaje b)
{
    int vidaA = a.maxVida;
    int vidaB = b.maxVida;
    turnoIndividual(a,b,vidaB);
    printf("%d",vidaB);
    turnoIndividual(b,a,vidaA);
    printf("%d",vidaA);
}

