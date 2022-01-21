/*
 * @Author: SPeak Shen 
 * @Date: 2021-11-17 23:55:19 
 * @Last Modified by: SPeak Shen
 * @Last Modified time: 2021-11-18 00:43:10
 * 
 * resolved:
 *      1.cxx pure virtual function
 *          compilesArgs: -fno-rtti
 *      2.Global Var
 *  
 */

#ifndef __ICXXABI_HPP__
#define __ICXXABI_HPP__

/*      global variable(obj) in c++      */

#define ATEXIT_FUNC_MAX 128

extern "C" {

    typedef unsigned uarch_t;

    struct atexitFuncEntry_t {
        void (*destructorFunc) (void *);
        void *objPtr;
        void *dsoHandle;
    };

    extern void *__dso_handle;

    void __cxa_pure_virtual() {
        // Do Nothing
    }

    atexitFuncEntry_t __atexitFuncs[ATEXIT_FUNC_MAX];
    uarch_t __atexitFuncCount = 0;

    void *__dso_handle = 0;

    int __cxa_atexit(void (*f)(void *), void *objptr, void *dso){
        if(__atexitFuncCount >= ATEXIT_FUNC_MAX){
            return -1;
        }
        __atexitFuncs[__atexitFuncCount].destructorFunc = f;
        __atexitFuncs[__atexitFuncCount].objPtr = objptr;
        __atexitFuncs[__atexitFuncCount].dsoHandle = dso;
        __atexitFuncCount++;
        return 0;
    }

    void __cxa_finalize(void *f){
        signed i = __atexitFuncCount;
        if(!f){
            while(i--){
                if(__atexitFuncs[i].destructorFunc){
                    (*__atexitFuncs[i].destructorFunc)(__atexitFuncs[i].objPtr);
                }
            }
            return;
        }

        for(; i >= 0; i--){
            if(__atexitFuncs[i].destructorFunc == f){
                (*__atexitFuncs[i].destructorFunc)(__atexitFuncs[i].objPtr);
                __atexitFuncs[i].destructorFunc = 0;
            }
        }
    }

    void * _Unwind_Resume = 0;
    void *__gxx_personality_seh0 = 0;

};

#endif