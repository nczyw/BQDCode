#ifndef BQDCODE_H
#define BQDCODE_H
#include "barcode.h"
#include "qrencode.h"
#include "dmtx.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
    #define BQDCODE_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
    #define BQDCODE_EXPORT __attribute__ ((visibility("default")))
#elif defined(__clang__)
    #define BQDCODE_EXPORT __attribute__ ((visibility("default")))
//#elif defined(__INTEL_COMPILER)
    // ICC 编译器特定的代码
#else
    #error "Unsupported system"
#endif
/*
 * Create and destroy barcode structures
 */
BQDCODE_EXPORT struct Barcode_Item *BQDBarcode_Create(char *text);
BQDCODE_EXPORT int                  BQDBarcode_Delete(struct Barcode_Item *bc);

/*
 * Encode and print
 */
BQDCODE_EXPORT int BQDBarcode_Encode(struct Barcode_Item *bc, int flags);
BQDCODE_EXPORT int BQDBarcode_Print(struct Barcode_Item *bc, FILE *f, int flags);

/*
 * Choose the position
 */
BQDCODE_EXPORT int BQDBarcode_Position(struct Barcode_Item *bc, int wid, int hei,
			    int xoff, int yoff, double scalef);

/*
 * Do it all in one step
 */
BQDCODE_EXPORT int BQDBarcode_Encode_and_Print(char *text, FILE *f, int wid, int hei,
				    int xoff, int yoff, int flags);

/*
 * Return current version (integer and string)
 */
BQDCODE_EXPORT int BQDBarcode_Version(char *versionname);

#ifdef __cplusplus
}
#endif

#endif