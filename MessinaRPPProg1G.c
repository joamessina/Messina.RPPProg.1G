//ejercicio 1
//Crear una función llamada calcularIVA que reciba como primer parámetro el precio bruto de un producto y como segundo parámetro la dirección de memoria de una variable donde debe escribir el valor del impuesto(el IVA es 21%). La función retorna 1 si salió todo bien o 0 si hubo algún error. Realizar la llamada desde main.

#include <stdio.h>
#include <stdlib.h>

int calcularIVA(float precio, float *iva){
    if(precio<0){
        return 0;
    }
    *iva=precio*0.21;
    return 1;
}

int main()
{
    float precio, iva;
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);
    if(calcularIVA(precio, &iva)==1){
        printf("El precio del producto es: %.2f y el IVA es: %.2f", precio, iva);
    }else{
        printf("El precio ingresado es incorrecto");
    }
    return 0;
}

//ejercicio2
//Crear una función que se llame subibaja que reciba una cadena de caracteres y que los caracteres en minúscula los pase a mayúscula y los que están en mayúscula los pase a minúscula retorna 1 si esta todo bien o 0 si hubo algún error.

#include <stdio.h>
#include <stdlib.h>

int subibaja(char *cadena){
    int i=0;
    while(cadena[i]!='\0'){
        if(cadena[i]>='a' && cadena[i]<='z'){
            cadena[i]=cadena[i]-32;
        }else if(cadena[i]>='A' && cadena[i]<='Z'){
            cadena[i]=cadena[i]+32;
        }else{
            return 0;
        }
        i++;
    }
    return 1;
}

int main()
{
    char cadena[100];
    printf("Ingrese una cadena de caracteres: ");
    gets(cadena);
    if(subibaja(cadena)==1){
        printf("La cadena de caracteres es: %s",cadena);
    }else{
        printf("La cadena de caracteres tiene caracteres que no son letras");
    }
    return 0;
}

//ejercicio 3

//Dada la estructura Notebook(id, procesador, marca, precio) generar una función que permita ordenar un array de dicha estructura por marca ascendente Ante igualdad de marca deberá ordenarse por precio descendente. Hardcodear datos y mostrarlos desde el main.

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
}Notebook;

void ordenarNotebooks(Notebook* notebooks, int tam);

int main()
{
    Notebook notebooks[5] = {{1, "Intel", "HP", 10000}, {2, "AMD", "Lenovo", 15000}, {3, "Intel", "Lenovo", 20000}, {4, "AMD", "HP", 25000}, {5, "Intel", "Lenovo", 30000}};

    ordenarNotebooks(notebooks, 5);

    for(int i = 0; i < 5; i++)
    {
        printf("%d %s %s %.2f \n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
    }

    return 0;
}

void ordenarNotebooks(Notebook* notebooks, int tam)
{
    Notebook aux;

    for(int i = 0; i < tam - 1; i++)
    {
        for(int j = i + 1; j < tam; j++)
        {
            if(strcmp(notebooks[i].marca, notebooks[j].marca) > 0)
            {
                aux = notebooks[i];
                notebooks[i] = notebooks[j];
                notebooks[j] = aux;
            }
            else if(strcmp(notebooks[i].marca, notebooks[j].marca) == 0)
            {
                if(notebooks[i].precio < notebooks[j].precio)
                {
                    aux = notebooks[i];
                    notebooks[i] = notebooks[j];
                    notebooks[j] = aux;
                }
            }
        }
    }
}