// ESTRUCTURA PRINCIPAL
#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Hello world!\n");
    return 0;
}

// VECTORES 
a = |3|5|8|6|0|4|3|
     0 1 2 3 4 5 6 <-- posición 

// 1. Cargar
#include <stdio.h>
#include <stdlib.h>
void generar(int[], int);
int main(){
  int vec[100], n;
  printf("- Ingrese dimension del vector: \n");
  scanf("%d",&n);
  generar(vec,n);
}
void generar(int vec[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("- Ingrese numero: \n");
        scanf("%d",&vec[i]);
    }
 return;
}

// 2. Mostrar
#include <stdio.h>
#include <stdlib.h>
void mostrar(int[], int);
int main(){
  int vec[100], n;
  printf("El vector quedó: \n");
  mostrar(vec,n);
}
void mostrar(int vec[], int n){
   int i;
    for(i=0; i<n; i++){
        printf("%d \n",vec[i]);
    }
}

// 3. Buscar un elemento
n=0;
while (vec[n]!= 10 && n<n1){
  n++;
  if (n == n1){
    printf ("El valor 10 no se encuentra");
  } else {
  printf ("El valor 10 está en la %d posición", n);
  }
}

// 4. Desplazar


// 5. Intercambiar

// 6. Ordenar
void ordenar(int vec[], int dim){
int i, j, aux;
for (i=0; i<n1-1; i++){
    for ( j=i+1; j<n1; j++){
        if ( vec[i] > vec[j]){
            aux = vec [i];
            vec [i] = vec [j];
            vec [j] = aux;
        }
    }
}

// Insertar consecutivos (siguiente posición el acutal + 1)
int insertarConsecutivos(int vec[], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=n; j>i+1; j--){
            vec[j] = vec[j-1];
        }
        vec[i+1] = vec[i] + 1;
        n++;
        i++;
    }
}
