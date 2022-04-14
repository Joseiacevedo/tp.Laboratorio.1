#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BTC 4606954.55


float PedirEntero(char mensaje[])
{
	char numeroEntero[50];
	int N;
	int numeroValidado;

	do{

	  printf("%s", mensaje);
	  scanf("%s", numeroEntero);
	  N = ValidarEntero(numeroEntero);
	}while(N==1);

	numeroValidado = atof(numeroEntero);



	  return numeroValidado;

}
float ValidarEntero(char numero[])
{
	int i;
	int retorno;
	retorno = 0;

	for(i = 0; i < strlen(numero); i++)
	{

		if(!(isdigit(numero[i])))
			{
			printf("\nERROR, INGRESA SOLO NUMEROS\n");
			retorno = 1;
			}

	}
	return retorno;
}
int ValidarOpcion(int numeroIngresado)
{
	int retorno;
	retorno = 0;

	if(numeroIngresado < 1 || numeroIngresado > 6)
		{

			printf(">>>>Error al ingresar una opcion, intente nuevamente<<<<\n");
			retorno = 1;
		}
	return retorno;
}
float Debito(float num1)
{

	float resultado;

	resultado = num1 - ((num1 * 10)/100);

	return resultado;
}

float Credito(float num1)
{

	float resultado;

	resultado = num1 + ((num1 * 25)/100);

	return resultado;
}


float Bitcoin(float num1)
{
	float resultado;

	resultado = num1 / BTC;

	return resultado;
}
float Unitario(float num1, float num2)
{

	float resultado;

	resultado = num1 / num2;

	return resultado;
}

int CalcularDiferencia(float num1, float num2)
{
	float resultado;

	if(num1 > num2)
	{
	resultado = num1 - num2;
	} else {
	resultado = num2 - num1;
	}
	return resultado;

}
