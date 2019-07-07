#ifndef _LINUX_KFIFO_H
#define _LINUX_KFIFO_H

struct __kfifo {
    unsigned int in;
    unsigned int out;
    unsigned int mask;
    unsigned int esize;
    void    *data;
};

#define __STRUCT_KFIFO_COMMON(datatype, recsize, ptrtype) \
    union { \
        struct __kfifo kfifo; \
        datatype *type; \
        const datatype *const_type; \
        char (*rectype)[recsize]; \
        ptrtype *ptr; \
        ptrtype const *ptr_const; \
    }

#define __STRUCT_FIFO(type, size, recsize, ptrtype) \
{ \
    __STRUCT_KFIFO_COMMON(type, recsize, ptrtype); \
    type buf[((size < 2 || (size & (size - 1))))? -1 : size]; \
}

#define STRUCT_KFIFO(type, size) \
    struct __STRUCT_KFIFO(type, size, 0, type)

#define __STRUCT_KFIFO_PTR(type, recsize, ptrtype) \
{ \
        __STRUCT_KFIFO_COMMON(type, recsize, ptrtype); \
        type buf[0]; \
}

#define STRUCT_KFIFO_PTR(type) \
    struct __STRUCT_KFIFO_PTR(type, 0, type)


#define DECLARE_KFIFO_PTR(fifo, type) STRUCT_FIFO_PTR(type) fifo
#endif
