//
//  main.c
//  te
//
//  Created by knuprime093 on 2018. 6. 4..
//  Copyright © 2018년 knuprime093. All rights reserved.
//

#include "uset.h"
#include <stdio.h>
#include <stdlib.h>

void usetInit(struct uset* u){
    if(u == NULL){
        printf("Invalid uset.\n");
        exit(-1);
    }
    else{
        *(u -> u_name) = "NONAME";
        u -> g_cnt = 0;
    }
}
