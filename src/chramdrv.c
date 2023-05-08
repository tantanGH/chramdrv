#include <stdio.h>
#include <stdint.h>
#include <doslib.h>

#define ENV_VAR "RAMDISK_DRIVE"

int32_t main(int32_t argc, uint8_t* argv[]) {

  int32_t rc = 1;

  struct DPBPTR dpb;

  for (int16_t i = 0; i < 26; i++) {
    if (GETDPB(i + 1, &dpb) >= 0) {
      //printf("drive %d ... id = %d\n", i + 1, dpb.id);
      if (dpb.id == 249) {
        uint8_t drive_letter[] = " :";
        drive_letter[0] = 'A' + i;
        printf("Found RAMDISK ... %s\n", drive_letter);
        if (SETENV(ENV_VAR, NULL, drive_letter) >= 0) {
          printf("Set environment variable RAMDISK_DRIVE=%s\n", drive_letter);
        }
        CHGDRV(i);
        rc = 0;
        break;
      }
    }
  }

  if (rc != 0) {
    SETENV(ENV_VAR, NULL, NULL);
  }

  return rc;
}