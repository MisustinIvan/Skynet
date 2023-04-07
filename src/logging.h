#include <stdio.h>
#include <stdlib.h>

#include "network.h"

#ifndef LOGGING_H
#define LOGGING_H
void logNetworkFile(struct Network*nw);
void logNetworkStdin(struct Network*nw);
#endif
