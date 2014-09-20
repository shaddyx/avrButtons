/*
 *
 *  Created on: Mar 21, 2014
 *      Author: shaddy
 */

#include <stdlib.h>
#include "util.h"

int makeRandom(int upper) {
		int val = rand();
		if (upper > RAND_MAX){
			return val + makeRandom(upper - RAND_MAX);
		}

		if (val > upper){
			return val % upper;
		}

		return val;
        //return (int)((double)rand() / ((double)RAND_MAX + 1) * upper);
}
