//
//  list.c
//  assignment7_chaining
//
//  Created by Sandor Doroteea on 5/20/20.
//  Copyright © 2020 Doroteea Sandor. All rights reserved.
//

#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT l, char * content)
{
    //! add last
}
