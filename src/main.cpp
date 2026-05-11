#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include "dobby.h"

int (*old_func)(void* instance);
int new_func(void* instance) {
    return 999999;
}

void static_init() {
    void* handle = dlopen("libil2cpp.so", RTLD_LAZY);
    if (!handle) return;
    
    void* target = (void*)((uintptr_t)handle + 0x123456);
    DobbyHook(target, (void*)new_func, (void**)&old_func);
}

__attribute__((constructor))
void entry() {
    static_init();
}
