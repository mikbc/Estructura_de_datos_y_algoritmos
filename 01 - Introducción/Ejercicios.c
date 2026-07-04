/* 
EJERCICIO 1:
Ingresar 10 números enteros y cargar un vector con aquellos números positivos. Mostralo si tiene elementos y sino mostrar leyenda. Si tiene elementos:
a) Insertar el consecutivo de aquellos números pares.
b) Ordenar el vector desde el elemento máximo hasta el elemento mínimo de mayor a menor y mostrarlo.
c) Eliminar él o los elementos máximos y desplazar los elementos hacia izquierda.*/

/* EJERCICIO 2:
Diseñar un algoritmo y luego codificarlo en C que permita:
Cargar un arreglo de n posiciones con las edades de personas a las que se le realizaron una encuesta (la carga se realiza ingresando los datos por teclado). 
Se pide:
a) Calcular el promedio de las edades e insertarlo al comienzo del arreglo.
b) Mostrar la edad mínima y en qué posición se encuentra esa edad.
c) Eliminar del arreglo la edades mayores a 50 años. 
d) Generar un nuevo arreglo con las edades pares ordenadas en sentido descendente. */

/*EJERCICIO 2:
Diseñar un algoritmo y luego codificarlo en C que permita:
Cargar un arreglo de n posiciones con las edades de personas a las que se le realizaron una encuesta (la carga se realiza ingresando los datos por teclado). 
Se pide:
a) Calcular el promedio de las edades e insertarlo al comienzo del arreglo.
b) Mostrar la edad mínima y en qué posición se encuentra esa edad.
c) Eliminar del arreglo la edades mayores a 50 años. 
d) Generar un nuevo arreglo con las edades pares ordenadas en sentido descendente. */

/*EJERCICIO 2:
Diseñar un algoritmo y luego codificarlo en C que permita:
Cargar un arreglo de n posiciones con las edades de personas a las que se le realizaron una encuesta (la carga se realiza ingresando los datos por teclado). 
Se pide:
a) Calcular el promedio de las edades e insertarlo al comienzo del arreglo.
b) Mostrar la edad mínima y en qué posición se encuentra esa edad.
c) Eliminar del arreglo la edades mayores a 50 años.
d) Generar un nuevo arreglo con las edades pares ordenadas en sentido descendente. */
#include <stdio.h>
int cargar(int[]);
void mostrar(int[], int);
int promedio(int[], int);
int insertar(int[], int, int);
void minima(int[], int);
int eliminar(int[], int);
int edadespares(int[], int, int[]);
void ordenar(int[], int);

int main() {
    int vec[100], dim=0, prom, vec1[100], dim1=0;
    printf("EDADES DE ENCUESTADOS:\n");
    dim = cargar(vec);
    if(dim==0){
        printf("Lo siento, no se ingresó ninguna edad...");
    } else {
        printf("EDADES: |");
        mostrar(vec, dim);
        // a)
        prom = promedio(vec, dim);
        printf("\nEl promedio de las edades da: %d", prom);
        dim=insertar(vec,dim,prom);
        printf("\nPROMEDIO+EDADES: |(Promedio)");
        mostrar(vec,dim);
        // b)
        minima(vec, dim);
        // c)
        dim=eliminar(vec,dim);
        printf("\nEDADES MENORES A 50: |(Promedio)");
        mostrar(vec,dim);
        // d) 
        dim1=edadespares(vec, dim, vec1);
        ordenar(vec1, dim1);
        printf("\n\nEDADES PARES: |");
        mostrar(vec1,dim1);
    }
    return 0;
}

int cargar(int vec[]){
    int edad, dim=0;
    printf("Para finalizar la carga, ingresar '0'.\n- Edad: ");
    scanf("%d", &edad);
    while(edad!=0){
        while(edad<0){
            printf("(No podes ingresar edades negativas...)\n- Edad: ");
            scanf("%d", &edad);
        }
        vec[dim]= edad;
        dim++;
        printf("- Edad: ");
        scanf("%d", &edad);
    }
    return dim;
}

void mostrar(int vec[], int dim){
    int i;
    for(i=0;i<dim;i++){
        printf("%d|", vec[i]);
    }
    return;
}

int promedio(int vec[], int dim){
    int i, prom=0;
    for(i=0;i<dim;i++){
        prom+=vec[i];
    }
    prom=prom/dim;
    return prom;
}

int insertar(int vec[], int dim, int prom){
    int i;
    for(i=dim+1;i>0;i--){
        vec[i]=vec[i-1];
    }
    vec[0]=prom;
    dim++;
    return dim;
}

void minima(int vec[], int dim){
    int min, i, posicion;
    min=vec[1];
    for(i=1;i<dim;i++){ // arranco en 1 para que no tenga en cuenta el promedio que insertamos en el punto anterior.
        if(vec[i]<min){
            min=vec[i];
            posicion=i;
        }
    }
    printf("\nLa edad mínima es %d, de la posición %d del vector", min, posicion);
    return;
}

int eliminar(int vec[], int dim){
    //Eliminar del arreglo la edades mayores a 50 años.
    int i, j;
    for(i=1;i<dim-1;i++){ // Empieza en 1 porque en la posición 0 está el promedio
        if(vec[i]>50){
            for(j=i;j<dim;j++){
                vec[j]=vec[j+1];
            }
            dim--;
            i--; // Volver a revisar la posición actual
        }
    }
    return dim;
}

int edadespares(int vec[], int dim, int vec1[]){
    int i, j=0, dim1=0;
    // Generar un nuevo arreglo con las edades pares ordenadas en sentido descendente
    for(i=1;i<dim;i++){
        if(vec[i]%2==0){
            vec1[j]=vec[i];
            j++;
            dim1++;
        }
    }
    return dim1;
}

void ordenar(int vec1[], int dim1){
    int i, aux=0, j;
    for (i=0;i<dim1;i++){
        if(vec1[i]<vec1[i+1]){
            aux=vec1[i];
            vec1[i]=vec1[i+1];
            vec1[i+1]=aux;
        }
    }
}

/* EJERCICIO 3:
Diseñar un algoritmo y luego codificarlo en C que permita:
a) Ingresar números enteros hasta cargar un arreglo con los tres primeros números positivos pares y los tres primeros números impares negativos en ese orden. Mostrarlo. 
b) Agregar el consecutivo de aquellos números múltiplos de 3. Mostrarlo */

/* EJERCICIO 4:
Leer números enteros y cargar un arreglo con los primeros 4 números negativos ingresados y con los 4 primeros números pares ingresados, en ese orden . Mostrarlo.
a) Después de cada número múltiplo de 4, agregar en el arreglo su doble. (si hay números múltiplos de 4)
b) Eliminar del arreglo los números múltiplos del 3. (si hay números múltiplos de 3)
c) Mostrar los dos números mas grandes negativos. */

/* EJERCICIO 5:
Leer números enteros y cargar un arreglo con dos números negativos, luego dos números impares y así sucesivamente hasta llenar un arreglo de 12 elementos.
a) Ordenar sólo los números negativos de menor a mayor (en el mismo arreglo). 
b) Generar otro arreglo con el valor máximo y mínimo de los números negativos y con el valor máximo y mínimo de los números impares.
c) En este último arreglo, agregar el consecutivo de cada valor. */

/* EJERCICIO 6:
Invertir un número entero ingresado por teclado.
*/
