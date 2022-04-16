#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BTC 4606954.55

/// \brief Recibe un mensaje, con el cual se pide un numero y se guarda en formato char, luego llama a la funcion ValidarEntero para validar,
/// que se haya guardado un numero y no una cadena de texto, y luego con la funcion atof se convierte de formato cadena a formato float, y se lo retorna.
/// \param char mensaje /Es el mensaje que recibe.
/// \return float /Retorna el numero ya validado en formato float.
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
/// \brief Recibe una cadena de texto, para recorrarla con la funcion strlen y verificar con la funcion isdigit que sean digitos.
/// \param char numero /La cadena que recibe para recorrer y validar.
/// \return int /Retorna 0 si es son digitos, y 1 si contiene algo que no sea un digito.
int ValidarEntero(char numero[])
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

/// \brief Recibe un numero para que valide, si esta dentro de un rango.
/// \param int numeroIngresado /El numero que recibe para validar.
/// \return int /Retorna 0 si la comprobacion esta dentro del rango, y 1 si no esta dentro del rango y debe ingresar un nuevo numero.
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

/// \brief Recibe una variable de tipo float, para luego realizar un calculo, en el cual se le resta a este numero un resto del porcentaje de dicho numero.
/// \param float num1 \El numero que recibe para calcular.
/// \return float resultado \Retorna el producto que se obtiene luego del calculo.
float Debito(float num1)
{

	float resultado;

	resultado = num1 - ((num1 * 10)/100);

	return resultado;
}

/// \brief Recibe una variable de tipo float, para luego realizar un calculo, en el cual se le suma a este numero, un porcentaje del mismo.
/// \param float num1 \El numero que recibe para calcular.
/// \return float resultado \Retorna el producto que se obtiene luego del calculo.
float Credito(float num1)
{

	float resultado;

	resultado = num1 + ((num1 * 25)/100);

	return resultado;
}

/// \brief Recibe una variable de tipo float, para luego realizar un calculo, en el cual se divide este numero que se recibe
/// por un define que se declaro "BTC" en la parte superior.
/// \param float num1 \El numero que recibe para calcular.
/// \return float resultado \Retorna el producto que se obtiene luego del calculo.
float Bitcoin(float num1)
{
	float resultado;

	resultado = num1 / BTC;

	return resultado;
}

/// \brief Recibe dos variables de tipo float, el primero el ese dividendo y el segundo el divisor.
/// \param float num1 \El numero que actua como dividendo.
/// \param float num2 \El numero que actua como divisor.
/// \return float resultado \Retorna el producto que se obtiene luego del calculo.
float Unitario(float num1, float num2)
{

	float resultado;

	resultado = num1 / num2;

	return resultado;
}

/// \brief Recibe dos variables de tipo float, primero se evalua cual de ambas es mayor a la otra, para luego realizar una diferencia entre ambas,
/// para el numero de mayor valor actue como un "Minuendo" y el menor como un "Sustraendo", y se pueda obtener una diferencia positiva.
/// \param float num1 \Primer valor que recibe.
/// \param float num2 \Segundo valor que recibe.
/// \return float resultado \Retorna el producto que se obtiene luego del calculo.
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
