#include <stdio.h>
#include <stdlib.h>

char* parola(char* parola_initiala, char* parola_corecta){
    for(char i = '0'; i < '0' + 10; i++){
        parola_initiala[0] = i;
        if(parola_initiala[0] != parola_corecta[0])
            continue;
        else
            for(char j = '0'; j < '0' + 10; j++){
                parola_initiala[1] = j;
                if(parola_initiala[1] != parola_corecta[1])
                    continue;
                else
                    for(char k = '0'; k < '0' + 10; k++){
                        parola_initiala[2] = k;
                        printf("Parola incercata: %s\n", parola_initiala);
                        if(parola_initiala[2] != parola_corecta[2])
                            continue;
                        else
                            return parola_initiala;
                    }
            }
    }
    return NULL;
}

int main(){
    char parola_initiala[4] = {0};
    char parola_corecta[4] = "324";
    printf("Parola corecta: %s\n", parola(parola_initiala, parola_corecta));
    return 0;
}