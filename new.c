/*
* 2012-6-5 PIONEER CORPORATION 
*
* This file is copied from bionic/libstdc++/src/new.cpp
*
*/

#if defined(ANDROID)
#if defined(DYNAMIC_LIB)
/* Android bionic libstdc++.so new/delete functions call malloc/free */
#else	/* DYNAMIC_LIB */
#include <stdlib.h>

struct nothrow_t {};
extern const struct nothrow_t _ZSt7nothrow;

const struct nothrow_t _ZSt7nothrow = {};

//void* operator new(std::size_t size)
void*_Znwj(size_t size)
{
    void* p = malloc(size);
    if (p == NULL) {
        // abort();
    }
    return p;
}

//void* operator new[](std::size_t size)
void* _Znaj(size_t size)
{
    void* p = malloc(size);
    if (p == NULL) {
        // abort();
    }
    return p;
}

//void  operator delete(void* ptr)
void  _ZdlPv(void* ptr)
{
    free(ptr);
}

//void  operator delete[](void* ptr)
void  _ZdaPv(void* ptr)
{
    free(ptr);
}

//void* operator new(std::size_t size, const std::nothrow_t&)
void* _ZnwjRKSt9nothrow_t(size_t size, const struct nothrow_t *p)
{
    return malloc(size);
}

//void* operator new[](std::size_t size, const std::nothrow_t&)
void* _ZnajRKSt9nothrow_t(size_t size, const struct nothrow_t *p)
{
    return malloc(size);
}

//void  operator delete(void* ptr, const std::nothrow_t&)
void  _ZdlPvRKSt9nothrow_t(void* ptr, const struct nothrow_t *p)
{
    free(ptr);
}

//void  operator delete[](void* ptr, const std::nothrow_t&)
void  _ZdaPvRKSt9nothrow_t(void* ptr, const struct nothrow_t *p)
{
    free(ptr);
}

//void* operator new(std::size_t, void* p) { return p; }
inline void* _ZnwjPv(size_t size, void* p) { return p; }
//void* operator new[](std::size_t, void* p) { return p; }
inline void* _ZnajPv(size_t size, void* p) { return p; }

// these next two are not really required, since exceptions are off
//inline void  operator delete(void*, void*) { }
inline void  _ZdlPvS_(void* p1, void* p2) { }
//inline void  operator delete[](void*, void*) { }
inline void  _ZdaPvS_(void* p1, void* p2) { }
#endif	/* DYNAMIC_LIB */
#endif	/* ANDROID */
