#ifndef __ASSERT_HPP__
#define __ASSERT_HPP__

using DPrintType = int (*)(const char *);

static DPrintType dprint { nullptr };

// assert(x) will generate a run-time error if 'x' is false.
#define ASSERT(x)                                       \
    if (!(x)) {                                         \
        if (nullptr != dprint) {                        \
            dprint("\nassert: failed ");                \
            dprint(#x);                                 \
            dprint("\n");                               \
        }                                               \
        asm volatile ("cli");                           \
        asm volatile ("hlt");                           \
    }                                                   \

// static_assert(x) will generate a compiler-time error if 'x' is false.
#define STATIC_ASEERT(x)                                \
    switch (x) {                                        \
        case 0:  case (x): ;                            \
    }

#endif // __ASSERT_HPP__