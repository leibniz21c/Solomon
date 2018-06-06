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
#include "sType.h"


void usetInit(struct uset* u){
    if(u == NULL){
        fprintf(stderr,"Invalid uset.\n");
        exit(INIT_ERR);
    }
    else{
        *(u -> u_name) = "NONAME";
        u -> g_cnt = 0;
    }
}
