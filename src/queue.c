/*
 * queue.c
 *
 *  Created on: 04-May-2016
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




/*
 *----------------------------------------------------------------------
 *   Include Files
 *----------------------------------------------------------------------
 */
#include "queue.h"

/*
 *----------------------------------------------------------------------
 *   Private Defines
 *----------------------------------------------------------------------
 */

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



/*
 *----------------------------------------------------------------------
 *   Export Functions Definitions
 *----------------------------------------------------------------------
 */
Queue_RetCode_t Initialize(PQueue_t pQueue)
{
	Queue_RetCode_t result = Qu_INVALIDQUEUE;
	size_t dataSize = 0;

	if (pQueue)
	{
		pQueue->Current = 0;
		pQueue->First = 0;
		pQueue->Last = 0;
		result = Qu_OK;
		switch(pQueue->Datatype)
		{
		case DT_BOOL:
			dataSize = pQueue->MaxNumberOfElements*sizeof(BOOL);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: Boolean datatype Queue\n");
#endif
			break;
		case DT_UINT8:
			dataSize = pQueue->MaxNumberOfElements*sizeof(UINT8);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: UINT8 datatype Queue\n");
#endif
			break;
		case DT_INT8:
			dataSize = pQueue->MaxNumberOfElements*sizeof(INT8);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: INT8 datatype Queue\n");
#endif
			break;
		case DT_UINT16:
			dataSize = pQueue->MaxNumberOfElements*sizeof(UINT16);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: UINT16 datatype Queue\n");
#endif
			break;
		case DT_INT16:
			dataSize = pQueue->MaxNumberOfElements*sizeof(INT16);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: INT16 datatype Queue\n");
#endif
			break;
		case DT_UINT32:
			dataSize = pQueue->MaxNumberOfElements*sizeof(UINT32);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: UINT32 datatype Queue\n");
#endif
			break;
		case DT_INT32:
			dataSize = pQueue->MaxNumberOfElements*sizeof(INT32);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: INT32 datatype Queue\n");
#endif
			break;
		case DT_FLOAT:
			dataSize = pQueue->MaxNumberOfElements*sizeof(FLOAT32);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: Float datatype Queue\n");
#endif
			break;
		case DT_DOUBLE:
			dataSize = pQueue->MaxNumberOfElements*sizeof(FLOAT64);
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: Double datatype Queue\n");
#endif
			break;
		default:
			dataSize = 0;
			result = Qu_INVALIDDATATYPE;
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_ERR: Invalid Datatype\n");
#endif
			break;
		}

		if (result == Qu_OK)
		{
#ifdef __USE_DYNAMIC_MEMORY
			if ( (pQueue->Ptr = (PQueue_t)malloc(dataSize)) == NULL)
			{
				printf("\nQUEUE_ERR: Allocation Failure\n");
				result = Qu_INVALIDALLOCATION;
			}
			else
			{
#endif
				memset(pQueue->Ptr, 0, dataSize);
#ifdef __USE_DYNAMIC_MEMORY
			}
#endif
		}
	}
#ifdef DEBUG_QUEUE
	else
	{
		printf("\nQUEUE_ERR: NULL Queue\n");
	}
#endif
	return result;
}


/*
 *----------------------------------------------------------------------
 *  Function: Queue_RetCode_t Enqueue(void *itemToEnqueue, PQueue_t pQueue)
 *
 *  Summary : This function Adds an Element from Queue End
 *
 *  Input	: pQueue - Pointer to Queue, itemToEnqueue - pointer to Element
 *            to be inserted
 *
 *  Output	: Result of Queue Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Queue_RetCode_t Enqueue(void *itemToEnqueue, PQueue_t pQueue)
{
	Queue_RetCode_t result = Qu_INVALIDQUEUE;
	if (pQueue)
	{
		result = Qu_OK;
		if (pQueue->Current >= pQueue->MaxNumberOfElements)
		{
			result = Qu_FULL;
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_ERR: Queue Full\n");
#endif
		}
		else
		{
			switch(pQueue->Datatype)
			{
			case DT_BOOL:
				((BOOL *)pQueue->Ptr)[pQueue->Last] = (BOOL)*((BOOL *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> %d\n", (BOOL)*((BOOL *)itemToEnqueue));
#endif
				break;
			case DT_UINT8:
				((UINT8 *)pQueue->Ptr)[pQueue->Last] = (UINT8)*((UINT8 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> 0x%02x\n", (UINT8)*((UINT8 *)itemToEnqueue));
#endif
				break;
			case DT_INT8:
				((INT8 *)pQueue->Ptr)[pQueue->Last] = (INT8)*((INT8 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> %d\n", (INT8)*((INT8 *)itemToEnqueue));
#endif
				break;
			case DT_UINT16:
				((UINT16 *)pQueue->Ptr)[pQueue->Last] = (UINT16)*((UINT16 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> 0x%04x\n", (UINT16)*((UINT16 *)itemToEnqueue));
#endif
				break;
			case DT_INT16:
				((INT16 *)pQueue->Ptr)[pQueue->Last] = (INT16)*((INT16 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> %d\n", (INT16)*((INT16 *)itemToEnqueue));
#endif
				break;
			case DT_UINT32:
				((UINT32 *)pQueue->Ptr)[pQueue->Last] = (UINT32)*((UINT32 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> 0x%08x\n", (UINT32)*((UINT32 *)itemToEnqueue));
#endif
				break;
			case DT_INT32:
				((INT32 *)pQueue->Ptr)[pQueue->Last] = (INT32)*((INT32 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> %d\n", (INT32)*((INT32 *)itemToEnqueue));
#endif
				break;
			case DT_FLOAT:
				((FLOAT32 *)pQueue->Ptr)[pQueue->Last] = (FLOAT32)*((FLOAT32 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> %f\n", (FLOAT32)*((FLOAT32 *)itemToEnqueue));
#endif
				break;
			case DT_DOUBLE:
				((FLOAT64 *)pQueue->Ptr)[pQueue->Last] = (FLOAT64)*((FLOAT64 *)itemToEnqueue);
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Enqueue -> %f\n", (FLOAT64)*((FLOAT64 *)itemToEnqueue));
#endif
				break;
			default:
				result = Qu_INVALIDDATATYPE;
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_ERR: Invalid Datatype\n");
#endif
				break;
			}
			if (pQueue->Datatype < DT_MAX)
			{
				pQueue->Last = (pQueue->Last+1) % pQueue->MaxNumberOfElements;
				pQueue->Current++;
			}
		}
	}
#ifdef DEBUG_QUEUE
	else
	{
		printf("\nQUEUE_ERR: NULL Queue\n");
	}
#endif
	return result;
}


/*
 *----------------------------------------------------------------------
 *  Function: Queue_RetCode_t Dequeue(void *dequeuedItem, PQueue_t pQueue)
 *
 *  Summary : This function removes an item from the Queue Front
 *
 *  Input	: pQueue - Pointer to Queue, dequeuedItem - container to store
 *            removed item
 *
 *  Output	: Result of Queue Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Queue_RetCode_t Dequeue(void *dequeuedItem, PQueue_t pQueue)
{
	Queue_RetCode_t result = Qu_INVALIDQUEUE;
	if (pQueue)
	{
		result = Qu_OK;
		if (pQueue->Current == 0)
		{
			result = Qu_EMPTY;
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_ERR: Queue Empty\n");
#endif
		}
		else
		{
			switch(pQueue->Datatype)
			{
			case DT_BOOL:
				*((BOOL *)dequeuedItem) = (BOOL)((BOOL *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> %d\n", *((BOOL *)dequeuedItem));
#endif
				break;
			case DT_UINT8:
				*((UINT8 *)dequeuedItem) = (UINT8)((UINT8 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> 0x%02x\n", *((UINT8 *)dequeuedItem));
#endif
				break;
			case DT_INT8:
				*((INT8 *)dequeuedItem) = (INT8)((INT8 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> %d\n", *((INT8 *)dequeuedItem));
#endif
				break;
			case DT_UINT16:
				*((UINT16 *)dequeuedItem) = (UINT16)((UINT16 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> 0x%04x\n", *((UINT16 *)dequeuedItem));
#endif
				break;
			case DT_INT16:
				*((INT16 *)dequeuedItem) = (INT16)((INT16 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> %d\n", *((INT16 *)dequeuedItem));
#endif
				break;
			case DT_UINT32:
				*((UINT32 *)dequeuedItem) = (UINT32)((UINT32 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> 0x%08x\n", *((UINT32 *)dequeuedItem));
#endif
				break;
			case DT_INT32:
				*((INT32 *)dequeuedItem) = (INT32)((INT32 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> %d\n", *((INT32 *)dequeuedItem));
#endif
				break;
			case DT_FLOAT:
				*((FLOAT32 *)dequeuedItem) = (FLOAT32)((FLOAT32 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> %f\n", *((FLOAT32 *)dequeuedItem));
#endif
				break;
			case DT_DOUBLE:
				*((FLOAT64 *)dequeuedItem) = (FLOAT64)((FLOAT64 *)pQueue->Ptr)[pQueue->First];
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_INFO: Dequeue -> %f\n", *((FLOAT64 *)dequeuedItem));
#endif
				break;
			default:
				result = Qu_INVALIDDATATYPE;
#ifdef DEBUG_QUEUE
				printf("\nQUEUE_ERR: Invalid Datatype\n");
#endif
				break;
			}
			if (pQueue->Datatype < DT_MAX)
			{
				pQueue->First = (pQueue->First+1) % pQueue->MaxNumberOfElements;
				pQueue->Current--;
			}
		}
	}
#ifdef DEBUG_QUEUE
	else
	{
		printf("\nQUEUE_ERR: NULL Queue\n");
	}
#endif
	return result;
}


/*
 *----------------------------------------------------------------------
 *  Function: Queue_RetCode_t Full(PQueue_t pQueue)
 *
 *  Summary : This function Checks for Queue Full
 *
 *  Input	: pQueue - Pointer to Queue
 *
 *  Output	: Result of Queue Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Queue_RetCode_t Full(PQueue_t pQueue)
{
	Queue_RetCode_t result = Qu_INVALIDQUEUE;
	if (pQueue)
	{
		result = Qu_OK;
		if (pQueue->Current >= pQueue->MaxNumberOfElements)
		{
			result = Qu_FULL;
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: Queue Full\n");
#endif
		}
#ifdef DEBUG_QUEUE
		else
		{
			printf("\nQUEUE_INFO: Queue not full\n");
		}
#endif

	}
#ifdef DEBUG_QUEUE
	else
	{
		printf("\nQUEUE_ERR: NULL Queue\n");
	}
#endif
	return result;
}


/*
 *----------------------------------------------------------------------
 *  Function: Queue_RetCode_t Empty(PQueue_t pQueue)
 *
 *  Summary : This function Checks for Queue Empty
 *
 *  Input	: pQueue - Pointer to Queue
 *
 *  Output	: Result of Queue Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Queue_RetCode_t Empty(PQueue_t pQueue)
{
	Queue_RetCode_t result = Qu_INVALIDQUEUE;
	if (pQueue)
	{
		result = Qu_OK;
		if (pQueue->Current == 0)
		{
			result = Qu_EMPTY;
#ifdef DEBUG_QUEUE
			printf("\nQUEUE_INFO: Queue Empty\n");
#endif
		}
#ifdef DEBUG_QUEUE
		else
		{
			printf("\nQUEUE_INFO: Queue not empty\n");
		}
#endif
	}
#ifdef DEBUG_QUEUE
	else
	{
		printf("\nQUEUE_ERR: NULL Queue\n");
	}
#endif
	return result;
}



/*
 *----------------------------------------------------------------------
 *  Function: Queue_RetCode_t DeInitialize(PQueue_t pQueue)
 *
 *  Summary	: This function un-initializes the Queue data structure
 *
 *  Input	: pQueue - Pointer to Queue
 *
 *  Output	: Result of Queue Operation as Enum
 *
 *  Notes	:
 *
 *----------------------------------------------------------------------
 */
Queue_RetCode_t DeInitialize(PQueue_t pQueue)
{
	Queue_RetCode_t result = Qu_INVALIDQUEUE;

	if (pQueue)
	{
		result = Qu_OK;
#ifdef __USE_DYNAMIC_MEMORY
		free(pQueue->Ptr);
#ifdef DEBUG_QUEUE
		printf("\nQUEUE_INFO: Memory is Free'd\n");
#endif
#endif
	}
#ifdef DEBUG_QUEUE
	else
	{
		printf("\nQUEUE_ERR: NULL Queue\n");
	}
#endif
	return result;
}
