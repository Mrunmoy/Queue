# Queue
Queue data structure static library. Can be used in Embedded Systems with static memory model.

Support for custom data types:

DataType_t doesn't support custom data types such as structures, etc but the uint32 type can be used to store a pointer to dynamically/statically allocated structure and used as custom data type.

For example: 

create static array of small int:

static uint8_t array[18] = {0};

[This section of README is TBD....]

Build:
```make```

Run:
```.\bin\QueueTest```



