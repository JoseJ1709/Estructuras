//
// Created by jose on 9/10/23.
//

#include "Dado.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Dado::LanzarDado() {
    srand (time(NULL));
    return rand()%6 + 1;
}
