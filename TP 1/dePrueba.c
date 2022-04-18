#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*0xFF,127,0159,0xaBb1,0Xx,0,010,09,127A,120*/
char *archSalida = "salida.txt";
char *archEntrada = "entrada.txt";

/*void MostrarToken(char *token, int i){
    printf("\nToken %d es de tipo--> %s", i, AFD_Constantes(token));
}*/
char *AFD_Constantes(char *token){
    int tam = strlen(token);
    char *tipo;
    int estados[tam];
    estados[0] = 0;
    if(token[0] == 0){      //OCTAL o HEXADECIMAL
        estados[1] = 1;
        if(token[1]>=0 && token[1]<=7){
            estados[2] = 5;
            for(int i=2; i<tam; i++){
                if(token[i]>=0 && token[i]<=7){
                    estados[i] = 5;
                    if(i==(tam-1)){
                        strcpy(tipo, "OCTAL");
                        return tipo;
                    }
                }
                else{
                    estados[i] = 6;
                    if(i==(tam-1)){
                        strcpy(tipo, "No Reconoce");
                        return tipo;
                    }
                }
            }
        }
        else if(token[1]=='x' || token[1]=='X'){
            estados[2] = 3;
            for(int i=2; i<tam; i++){
                switch(token[i]){
                    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
                    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
                    estados[i] = 5;
                    estados[2] = 3;
                    if(i==(tam-1)){
                        strcpy(tipo, "HEXADECIMAL");
                        return tipo;
                    }
                    break; 
                    default:
                    estados[i] = 6;
                    if(i==(tam-1)){
                        strcpy(tipo, "No Reconoce");
                        return tipo;
                    }
                }
            }
        }
        else{
            for(int i=2; i<tam; i++){
                estados[i] = 6;
                if(i==(tam-1)){
                    strcpy(tipo, "No Reconoce");
                    return tipo;
                }
            }
        }
    }
    else if(token[0]>=1 && token[0]<=9){        //DECIMAL
        estados[1] = 2;
        for(int i=1; i<tam; i++){   
            if(token[i]>=1 && token[i]<=9){
                estados[i] = 2;
                if(i==(tam-1)){
                    strcpy(tipo, "DECIMAL");
                    return tipo;
                }
            }
            else{
                estados[i] = 6;
                if(i==(tam-1)){    
                    strcpy(tipo, "No Reconoce");
                    return tipo;
                }
            }
        }
    }
    else{                       //NO RECONOCE
        strcpy(tipo, "No Reconoce");
        return tipo;
    }               
}


int main(){
    
    FILE *g;
    const char centinela[2] = ",";
    char *token;
    /*char word[45] = "0xFF,127,0159,0xaBb1,0Xx,0,010,09,127A,120";
    g = fopen("test.txt", "a");
    fwrite(word, sizeof(char [57]), 1, g);
    
    fclose(g);*/
    char word2[57]; 
    int i=1;
    g = fopen("test.txt", "r");
    fread(word2, sizeof(char [57]), 1, g);
    printf("\n%s", word2);
    
    /* get the first token */
    token = strtok(word2, centinela);
    
    /* walk through other tokens */
    while( token != NULL ) {
        printf("\nToken %d es de tipo--> %s", i, AFD_Constantes(token));
        i++;
        token = strtok(NULL, centinela);
    }
    
    fclose(g);

    printf("\n\n");
    system("pause");
    return 0;
}

