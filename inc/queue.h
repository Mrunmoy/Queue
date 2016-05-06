/*
 * queue.h
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

#ifndef INC_QUEUE_H_
#define INC_QUEUE_H_

#include "cmn_header.h"


//! DEBUG_QUEUE.
/*!
		      uncomment to see queue debug msgs.
 */
//#define DEBUG_QUEUE


//! __USE_DYNAMIC_MEMORY.
/*!
		      uncomment to use dynamic memory allocation.
 */
//#define __USE_DYNAMIC_MEMORY


/*! \struct Queue_t
    \brief  Queue Data Structure Definition.

   Queue Data Structure Definition
   used for all queue operations.
*/
struct Queue_t
{
	//! Datatype.
	/*!
		      The Data Type used in the stack.
	 */
	DataType_t Datatype;

	//! Ptr.
	/*!
		      Pointer to the Queue Data.
	 */
	void *Ptr;

	//! MaxNumberOfElements.
	/*!
		      total number of elements in the stack.
	 */
	size_t MaxNumberOfElements;

	//! Current.
	/*!
		      stack element count.
	 */
	int Current;

	//! First.
	/*!
      	  	  First queue element.
	 */
	int First;

	//! Last.
	/*!
      	  	  Last queue element.
	 */
	int Last;
}__ATTRIBUTE__(packed);
typedef struct Queue_t Queue_t;
typedef struct Queue_t * PQueue_t;



//! Queue_RetCode_t enum.
/*! Queue Operation Return Code Definition. */
typedef enum Queue_RetCode_t
{
	Qu_OK	= 0,			/**< enum value Qu_OK = 0. Indicates stack operation was successful. */
	Qu_INVALIDQUEUE,		/**< enum value Qu_INVALIDSTACK = 1. Indicates a NULL Queue Pointer. */
	Qu_INVALIDDATATYPE,		/**< enum value Qu_INVALIDDATATYPE = 2. Indicates invalid stack data type. */
	Qu_INVALIDELEMENT,		/**< enum value Qu_INVALIDELEMENT = 3. Indicates invalid element container. */
#ifdef __USE_DYNAMIC_MEMORY
	Qu_INVALIDALLOCATION,	/**< enum value Qu_INVALIDALLOCATION = 4. Indicates invalid memory allocation. */
#endif
	Qu_EMPTY,				/**< enum value Qu_EMPTY = 4. Indicates stack is empty. */
	Qu_FULL,				/**< enum value Qu_FULL = 5. Indicates stack is full. */
	Qu_MAX					/**< enum value Qu_MAX = 6. Max counter. */
}Queue_RetCode_t;


/*! \fn Stack_RetCode_t Initialize(PQueue_t pQueue)

    \brief This function initializes the Queue for all further operations.

    \param pQueue is of type PQueue_t. It is the Queue Data Structure pointer.
*/
Queue_RetCode_t Initialize(PQueue_t pQueue);


/*! \fn Stack_RetCode_t Push(void *itemToPush, PQueue_t pQueue)

    \brief This function pushes an element on to the Queue top.

    \param itemToPush is of type void. It is pointer to the actual data to be pushed.
    \param pQueue is of type PQueue_t. It is the Queue Data Structure pointer.
*/
Queue_RetCode_t Enqueue(void *itemToPush, PQueue_t pQueue);


/*! \fn Stack_RetCode_t Pop(void *poppedItem, PQueue_t pQueue)

    \brief This function pops an element from the Queue top.

    \param poppedItem is of type void. It is pointer to the data container to store the popped item.
    \param pQueue is of type PQueue_t. It is the Queue Data Structure pointer.
*/
Queue_RetCode_t Dequeue(void *poppedItem, PQueue_t pQueue);


/*! \fn Stack_RetCode_t Full(PQueue_t pQueue)

    \brief This function checks if the Queue is Full.

    \param pQueue is of type PQueue_t. It is the Queue Data Structure pointer.
*/
Queue_RetCode_t Full(PQueue_t pQueue);


/*! \fn Stack_RetCode_t Empty(PQueue_t pQueue)

    \brief This function checks for Empty Queue.

    \param pQueue is of type PQueue_t. It is the Queue Data Structure pointer.
*/
Queue_RetCode_t Empty(PQueue_t pQueue);


/*! \fn Stack_RetCode_t DeInitialize(PQueue_t pQueue)

    \brief This function un-initializes the Queue for all further operations.

    \param pQueue is of type PQueue_t. It is the Queue Data Structure pointer.
*/
Queue_RetCode_t DeInitialize(PQueue_t pQueue);

#endif /* INC_QUEUE_H_ */
