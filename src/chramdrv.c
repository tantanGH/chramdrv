#include <stdio.h>
#include <stdint.h>
#include <doslib.h>

int32_t main(int32_t argc, uint8_t* argv[]) {

  int32_t rc = 1;

  struct DPBPTR dpb;

  for (int16_t i = 1; i <= 26; i++) {
    if (GETDPB(i, &dpb) >= 0) {
      //printf("drive %d ... id = %d\n", i, dpb.id);
      if (dpb.id == 249) {
        CHGDRV( i - 1 );
        printf("RAMDISK Drive ... %c:\n", 'A' + i - 1);
        rc = 0;
        break;
      }
    }
  }

  return rc;
}