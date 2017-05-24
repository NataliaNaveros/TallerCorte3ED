#include <stdio.h>
#include <stdlib.h>
#define reservar_memoria (Nodo*)malloc(sizeof(Nodo))
struct Nodo {
    int dato;
    Nodo *derecha;
    Nodo *izquierda;
};
Nodo *arbol=NULL;
/*Nodo crearNodo(int n){
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo->dato=n;
    nuevo_nodo->derecha=NULL;
    nuevo_nodo->izquierda=NULL;
    return *nuevo_nodo;
}*/
void insertarNodo(Nodo *&, int);
void insertarNodo_derecha(Nodo *&, int);
void insertarNodo_izquierda(Nodo *&, int);
void imprimirNodo(Nodo *,int);
bool buscarNodo(Nodo *,int);
void inOrden(Nodo *arbol);
void postOrden(Nodo *arbol);
void preOrden(Nodo *arbol);
void menu();
int main(){
    menu();
    return 0;
}
void menu (){
    int opcion, n, num;
    int contador=0;
    do{
        printf("\n*****Menu******\n\n");
        printf("\n1.Insertar");
        printf("\n2.Insertar derecha");
        printf("\n3.Insertar izquierda");
        printf("\n4.Editar");
        printf("\n5.Buscar");
        printf("\n6.Eliminar");
        printf("\n7.Mostrar");
        printf("\n8.PreOrden");
        printf("\n9.PostOrden");
        printf("\n10.InOrden");
        printf("\n0.Salir");
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                printf("Ingrese un numero: ");
                scanf("%d ",&num);
                printf("\n");
                for(int i=0;i<=n;i++){
                    //printf("Nodo %d: ",i+1);
                    scanf("%d", &n);
                    insertarNodo(arbol,n);
                }
            break;
            case 2:
                printf("Ingrese el dato a implementar a la derecha: ");
                scanf("%d",&n);
                insertarNodo_derecha(arbol,n);
            break;
            case 3:
                printf("Ingrese el dato a implementar a la izquierda: ");
                scanf("%d",&n);
                insertarNodo_derecha(arbol,n);
            break;
            case 4:
                printf("\nIngrese dato a buscar: ");
                scanf("%d",&num);
                buscarNodo(arbol,num);
            break;
            case 5:

            break;
            case 6:

            break;
            case 7:
                imprimirNodo(arbol,contador);
            break;
            case 8:
                preOrden(arbol);
            break;
            case 9:
                postOrden(arbol);
            break;
            case 10:
                inOrden(arbol);
            break;
            case 0:
                exit(0);
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
        menu();
    }while(opcion!=0);
}

void insertarNodo(Nodo *&arbol, int n){
    if(arbol==NULL){
        Nodo *nuevo_nodo = reservar_memoria;
        arbol=nuevo_nodo;
        nuevo_nodo->dato=n;
        nuevo_nodo->izquierda=NULL;
        nuevo_nodo->derecha=NULL;
    }else{
        int valorRaiz=arbol->dato;
        if(n<valorRaiz){
            insertarNodo(arbol->izquierda,n);
        }else{
            insertarNodo(arbol->derecha,n);
        }
    }
}
void insertarNodo_derecha(Nodo *&arbol,int n){
    if(arbol==NULL){
        Nodo *nuevo_nodo = reservar_memoria;
        arbol=nuevo_nodo;
        nuevo_nodo->dato=n;
        nuevo_nodo->izquierda=NULL;
        nuevo_nodo->derecha=NULL;
    }else{
        int valorRaiz=arbol->dato;
        if(n<valorRaiz){
            insertarNodo(arbol->derecha,n);
        }
    }
}
void insertarNodo_izquierda(Nodo *&arbol, int n){
    if(arbol==NULL){
        Nodo *nuevo_nodo = reservar_memoria;
        arbol=nuevo_nodo;
        nuevo_nodo->dato=n;
        nuevo_nodo->izquierda=NULL;
        nuevo_nodo->derecha=NULL;
    }else{
        int valorRaiz=arbol->dato;
        if(n<valorRaiz){
            insertarNodo(arbol->izquierda,n);
        }
    }
}
void imprimirNodo(Nodo *arbol, int contador){
    if(arbol==NULL){
        return;
    }else{
        imprimirNodo(arbol->derecha,contador+1);
        for(int i=0;i<contador;i++){
            printf("    ");
        }
        printf("%d\n",arbol->dato);
        imprimirNodo(arbol->izquierda,contador+1);
    }
}
bool buscarNodo(Nodo *arbol, int n){
    if(arbol==NULL){
        return false;
    }else if(arbol->dato==n){
        return true;
    }else if(n<arbol->dato){
        return buscarNodo(arbol->izquierda, n);
    }else{
        return buscarNodo(arbol->derecha, n);
    }
}
void inOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        inOrden(arbol->izquierda);
        printf("%d - ",arbol->dato);
        inOrden(arbol->derecha);
    }
}
void postOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        postOrden(arbol->izquierda);
        postOrden(arbol->derecha);
        printf("%d - ",arbol->dato);
    }
}
void preOrden(Nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        printf("%d - ",arbol->dato);
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}
