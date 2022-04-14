/*
Programación I – Laboratorio I

UTN FRA – Tecnicatura Superior en Programación. http://www.sistemas-utnfra.com.ar 3
1 Enunciado
Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas
para ofrecerlos a sus clientes.
Se deberá ingresar por cada vuelo los km totales y el precio total del mismo.
El objetivo de la aplicación es mostrar las diferentes opciones de pagos a sus clientes.
Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar Kilómetros: ( km=x)
2. Ingresar Precio de Vuelos: (Aerolíneas=y, Latam=z)
- Precio vuelo Aerolíneas:
- Precio vuelo Latam:
3. Calcular todos los costos:
a) Tarjeta de débito (descuento 10%)
b) Tarjeta de crédito (interés 25%)
c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
d) Mostrar precio por km (precio unitario)
e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)
4. Informar Resultados
“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es : r “
5. Carga forzada de datos
6. Salir

Aclaraciones del funcionamiento:
El menú se tiene que ver tal cual está descrito en la consigna. Los resultados se tienen que
mostrar con el mismo formato. Se puede realizar un submenú para ingresar los km y los
precios.
Los resultados se tienen que ver con el formato presentado en el menú. De la siguiente
manera.
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main(void) {
    setbuf(stdout, NULL);

    float kilometros;
    int flagKm;
    flagKm = 0;
    float precioAerolineas;
    float precioLatam;
    int flagPrecioAerolineas;
    flagPrecioAerolineas = 0;
    int flagPrecioLatam;
    flagPrecioLatam = 0;
    float debitoLatam;
    float creditoLatam;
    float bitcoinLatam;
    float unitarioLatam;
    float debitoAerolineas;
    float creditoAerolineas;
    float bitcoinAerolineas;
    float unitarioAerolineas;
    float diferencia;
    int flagCalculos;
    flagCalculos = 0;
    int opcion;
    int flagCase5;
    flagCase5 = 0;

    do {

      if (flagKm != 0) {
        printf("\n1: Ingresar Kilometros: (Km = %f km)\n", kilometros);
      } else {
        printf("\n1: Ingresar Kilometros: (Km = x)\n");
      }
      if (flagPrecioLatam != 0 && flagPrecioAerolineas != 0) {
        printf("2: Ingresar precio de Vuelos: (Aerolíneas = %.2f, Latam = %.2f)\n", precioAerolineas, precioLatam);
      } else {
        printf("2: Ingresar precio de Vuelos: (Aerolíneas = Y, Latam = Z)\n");
      }

      printf("3: Calcular todos los costos:\n");
      printf("4: Informar Resultados: \n");
      printf("5: Carga forzada de datos \n");
      printf("6: Salir \n");
      printf("Ingrese la opcion: \n");
      scanf("%d", & opcion);
      fflush(stdin);
      ValidarOpcion(opcion);

      switch (opcion) {
      case 1:

        kilometros = PedirEntero("Ingresar Kilometros: \n");
        fflush(stdin);
        flagKm = 1;
        break;

      case 2:

    	precioLatam = PedirEntero("Precio vuelo Latam: \n");
        fflush(stdin);
        flagPrecioLatam = 1;
        precioAerolineas = PedirEntero("Precio vuelo Aerolíneas: \n");
        fflush(stdin);
        flagPrecioAerolineas = 1;
        break;

      case 3:

        if (flagKm != 0 && flagPrecioLatam != 0 && flagPrecioAerolineas != 0) {
          debitoLatam = Debito(precioLatam);
          debitoAerolineas = Debito(precioAerolineas);
          creditoLatam = Credito(precioLatam);
          creditoAerolineas = Credito(precioAerolineas);
          bitcoinLatam = Bitcoin(precioLatam);
		  bitcoinAerolineas = Bitcoin(precioAerolineas);
          unitarioLatam = Unitario(precioLatam, kilometros);
          unitarioAerolineas = Unitario(precioAerolineas, kilometros);
          diferencia = CalcularDiferencia(precioLatam, precioAerolineas);

          printf("\n>>>>LOS NUMEROS YA HAN SIDO CALCULADOS<<<<\n");
          flagCalculos = 1;
        } else {
          printf("\n>>>>ERROR, para realizar los calculos primero debe ingresar los operadores<<<<\n");
        }
        break;

      case 4:

        if (flagKm != 0 && flagPrecioLatam != 0 && flagCalculos != 0) {
          printf("KMs Ingresados: %f km\n", kilometros);
          printf("\nLatam: \n");
          printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoLatam);
          printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoLatam);
          printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinLatam);
          printf("d) Precio unitario: $ %.2f\n", unitarioLatam);
          printf("\nAerolineas: \n");
          printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoAerolineas);
          printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoAerolineas);
          printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinAerolineas);
          printf("d) Precio unitario: $ %.2f\n", unitarioAerolineas);
          printf("\nLa diferencia de precios es: $ %.2f\n",diferencia);

          break;
        } else {
          printf("\n>>>>ERROR, para conocer los resultados primero debe cargar los operadores, luego calcularlos y ahi podra mostrar los resultados<<<<\n");
        }
        break;
      case 5:

    	  kilometros = 7090;
		  precioAerolineas = 162965;
		  precioLatam = 159339;

		  debitoLatam = Debito(precioLatam);
		  debitoAerolineas = Debito(precioAerolineas);
		  creditoLatam = Credito(precioLatam);
		  creditoAerolineas = Credito(precioAerolineas);
		  bitcoinLatam = Bitcoin(precioLatam);
		  bitcoinAerolineas = Bitcoin(precioAerolineas);
		  unitarioLatam = Unitario(precioLatam, kilometros);
		  unitarioAerolineas = Unitario(precioAerolineas, kilometros);
		  diferencia = CalcularDiferencia(precioLatam, precioAerolineas);
		  flagCase5 = 1;

		  if(flagCase5 != 0)
		  {
			  printf("\nKMs Ingresados: %.2f km\n", kilometros);
			  printf("\nLatam: $ %.2f\n",precioLatam);
			  printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoLatam);
			  printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoLatam);
			  printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinLatam);
			  printf("d) Precio unitario: $ %.2f\n", unitarioLatam);
			  printf("\nAerolineas: $ %.2f\n",precioAerolineas);
			  printf("a) Precio con tarjeta de débito: $ %.2f\n", debitoAerolineas);
			  printf("b) Precio con tarjeta de crédito: $ %.2f\n", creditoAerolineas);
			  printf("c) Precio pagando con bitcoin : %.2f BTC\n", bitcoinAerolineas);
			  printf("d) Precio unitario: $ %.2f\n", unitarioAerolineas);
			  printf("\nLa diferencia de precios es: $ %.2f\n",diferencia);

		  }

    	break;
      case 6:
        printf("Salida\n");
        break;
      }

    } while (opcion != 6);

    return 0;
}
