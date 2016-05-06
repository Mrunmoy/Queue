/*
 * test.c
 *
 *  Created on: 05-May-2016
 *      Author: Mrunmoy Samal
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2016 Mrunmoy Samal
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall
 *  be included in all copies or substantial portions of the
 *  Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 *  OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */
#include "queue.h"




/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/
#define QUEUE_SIZE		(5)
/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Variables (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Constants
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Constants (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Function Prototypes (static)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/
int main(int argc, char *argv[])
{
	Queue_t myQueue;
#ifndef __USE_DYNAMIC_MEMORY
	INT32 myQueueData[QUEUE_SIZE];
#endif
	INT32 var;

	myQueue.Datatype 	= DT_INT32;
	myQueue.MaxNumberOfElements = QUEUE_SIZE;
#ifndef __USE_DYNAMIC_MEMORY
	myQueue.Ptr 		= myQueueData;
#endif

	printf("\n--- Initialize Test ---\n");
	if ( Qu_OK == Initialize(&myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Empty Test ---\n");
	if ( Qu_EMPTY == Empty(&myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Enqueue Test ---\n");
	var = 5;
	printf("\nEnqueue %d\n", var);
	if ( Qu_OK == Enqueue(&var, &myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 10;
	printf("\nEnqueue %d\n", var);
	if ( Qu_OK == Enqueue(&var, &myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 15;
	printf("\nEnqueue %d\n", var);
	if ( Qu_OK == Enqueue(&var, &myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 20;
	printf("\nEnqueue %d\n", var);
	if ( Qu_OK == Enqueue(&var, &myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 25;
	printf("\nEnqueue %d\n", var);
	if ( Qu_OK == Enqueue(&var, &myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	var = 30;
	printf("\nEnqueue %d\n", var);
	if ( Qu_OK == Enqueue(&var, &myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\nQueue.Count = %d\n", myQueue.Current);

	printf("\n--- Full Test ---\n");
	if ( Qu_FULL == Full(&myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- Dequeue Test ---\n");
	if ( Qu_OK == Dequeue(&var, &myQueue))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Qu_OK == Dequeue(&var, &myQueue))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Qu_OK == Dequeue(&var, &myQueue))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Qu_OK == Dequeue(&var, &myQueue))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Qu_OK == Dequeue(&var, &myQueue))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	if ( Qu_OK == Dequeue(&var, &myQueue))
	{
		printf("Passed\n");
		printf("Popped %d\n\n", var);
	}
	else
	{
		printf("Failed\n");
	}

	printf("\nQueue.Count = %d\n", myQueue.Current);

	printf("\n--- Empty Test ---\n");
	if ( Qu_EMPTY == Empty(&myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	printf("\n--- DeInit Test ---\n");
	if ( Qu_OK == DeInitialize(&myQueue))
	{
		printf("Passed\n");
	}
	else
	{
		printf("Failed\n");
	}

	return 0;
}


/*
*----------------------------------------------------------------------
*   Export Functions Definitions
*----------------------------------------------------------------------
*/
