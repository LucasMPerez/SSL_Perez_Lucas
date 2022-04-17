#include <stdio.h>
#include <stdlib.h>
/*0xFF,127,0159,0xaBb1,0Xx,0,010,09,127A,120*/
char *archSalida = "salida.txt";
char *archEntrada = "entrada.txt";

int main(){

    int TamMayor = 0, cant=0;
    int tam = 0;
    FILE *f;
    if(f = fopen("entrada.txt", "r") == NULL){
        printf("\nError al abrir el archivo...");
    }
    else{
        while(!feof(f)){
            if(fgetc(f) != ",")
                tam++;
            else{
                if(tam > TamMayor)
                    TamMayor = tam;
                cant++;
            }
        }
    }

    printf("\nLa cant de palabras es: %d y el tamanio de la mayor es: %d\n", cant, TamMayor);
    
    system("pause");
    return 0;
}

