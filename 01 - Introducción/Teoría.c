// ESTRUCTURA PRINCIPAL
#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Hello world!\n");
    return 0;
}

// VECTORES Y FUNCIONES
#include <stdio.h>
#include <stdlib.h>
// Se declaran las funciones en el orden que se deseen ejecutar
void generar(int [], int);
void mostrar(int [], int);
int sumatoria(int [], int);    // Siempre se manda el vector y su dimensión
void promedio(int [], int);
int generarvector(int [], int, int []);
void ordenar(int [], int);

int main() {
  int vec[100], vec1[100], n, s, dim;
  printf("Ingrese dimension del vector \n");
  scanf("%d",&n);
    
  generar(vec,n);
  printf("Tu primer vector es: ");
  mostrar(vec,n);
    
  s = sumatoria(vec,n); // El resultado de la Función 'sumatoria' se almacena en la variable s
  printf("La sumatoria de los números de tu vector da: %d \n", s);
    
  promedio(vec,n);
  dim = generarvector(vec,n,vec1);
  printf("\n");
    
  mostrar(vec1,dim);
  ordenar(vec,n);
  printf("\n");
    
  mostrar(vec,n);
  return 0;
}

void generar(int vec[],int n) {
    int i;
    for(i=0;i<n;i++){
        printf("ingrese numero \n");
        scanf("%d",&vec[i]);
    }
 return;
}

void mostrar(int vec[],int n) {
   int i;
    for(i=0;i<n;i++){
        printf("%d \n",vec[i]);
    }
}

int sumatoria(int vec[],int n){
    int i, f=0;
    for(i=0;i<n;i=i+2){
        f=f+vec[i];
    }
 return f;
}

void promedio(int vec[],int n){
  int i,suma=0,cont=0;
  for(i=1;i<n;i=i+2){
      if (vec[i]%2==0){
          suma=suma+vec[i];
          cont++;
      }
  }
  if (cont!=0){
      printf("El promedio es: %d",suma/cont);
  }
  else{
      printf("No hay pares en esas posiciones");
  }
}

int generarvector(int vec[],int n,int vec1[]){
    int i, j=0;
    for (i=0; i<n; i++){
        if (vec[i]%vec[0]==0){
            vec1[j]=vec[i];
            j++;
        }
    }
    return j;
}

void ordenar(int vec[],int n){
    int i,j,aux;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if (vec[i]>vec[j]){
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }
    }
}
