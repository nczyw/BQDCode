#include "bqdcode.h"
int streaming = 0 ;
struct Barcode_Item *BQDBarcode_Create(char *text){
    return Barcode_Create(text);
}

int BQDBarcode_Delete(struct Barcode_Item *bc){
    return Barcode_Delete(bc);
}

int BQDBarcode_Encode(struct Barcode_Item *bc, int flags){
    return Barcode_Encode(bc, flags);
}

int BQDBarcode_Print(struct Barcode_Item *bc, FILE *f, int flags){
    return Barcode_Print(bc, f, flags);
}
int BQDBarcode_Position(struct Barcode_Item *bc, int wid, int hei,int xoff, int yoff, double scalef){
    return Barcode_Position(bc, wid, hei, xoff, yoff, scalef);
}
int BQDBarcode_Encode_and_Print(char *text, FILE *f, int wid, int hei,int xoff, int yoff, int flags){
    return Barcode_Encode_and_Print(text, f, wid, hei, xoff, yoff, flags);
}
int BQDBarcode_Version(char *versionname){
    return Barcode_Version(versionname);
}