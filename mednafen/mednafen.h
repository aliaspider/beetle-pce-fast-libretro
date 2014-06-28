#ifndef _MEDNAFEN_H
#define _MEDNAFEN_H

#include "mednafen-types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _(String) (String)

#include "math_ops.h"
#include "git.h"

#ifdef _WIN32
#define strcasecmp _stricmp
#endif

#ifdef __LIBRETRO__
#define GET_FDATA(fp) (fp.f_data)
#define GET_FSIZE(fp) (fp.f_size)
#define GET_FEXTS(fp) (fp.f_ext)
#define GET_FDATA_PTR(fp) (fp->f_data)
#define GET_FSIZE_PTR(fp) (fp->f_size)
#define GET_FEXTS_PTR(fp) (fp->f_ext)
#define gzopen(a, b) fopen(a, b)
#define gzread(a, b, c) fread(b, c, 1, a)
#define gzclose(a) fclose(a)
#define gzgetc(a) fgetc(a)
#define gzseek(a,b,c) fseek(a,b,c)
#else
#define GET_FDATA(fp) (fp.Data())
#define GET_FSIZE(fp) (fp.Size())
#define GET_FDATA_PTR(fp) (fp->data)
#define GET_FSIZE_PTR(fp) (fp->size)
#define GET_FEXTS_PTR(fp) (fp->ext)
#define gzread(a, b, c) gzread(a, b, c)
#define gzclose(a) gzclose(a)
#define gzgetc(a) gzgetc(a)
#define gzseek(a,b,c) gzseek(a,b,c)
#endif

#ifdef PSP
#include <pspkernel.h>
#include <pspgu.h>
#include <pspdisplay.h>

#define PSP_VRAM_TOP       ((void*)0x04200000)
#define VDC_TEXTURE_WIDTH  (512)
#define VDC_TEXTURE_HEIGHT (242)
#define VDC_TEXTURE_SIZE   (VDC_TEXTURE_WIDTH * VDC_TEXTURE_HEIGHT)
#define VDC_BG_TEXTURE     (((uint8_t*)PSP_VRAM_TOP)     - VDC_TEXTURE_SIZE)
#define VDC_SPR_TEXTURE    (((uint16_t*)VDC_BG_TEXTURE)   - VDC_TEXTURE_SIZE)
#define VDC_FRAME_TEXTURE  (((uint16_t*)VDC_SPR_TEXTURE) - VDC_TEXTURE_SIZE)
#endif

#ifndef gettext_noop
#define gettext_noop(a) (a)
#endif

extern MDFNGI *MDFNGameInfo;

#include "settings.h"

void MDFN_PrintError(const char *format, ...);
void MDFN_printf(const char *format, ...);
void MDFN_DispMessage(const char *format, ...);

void MDFN_DebugPrintReal(const char *file, const int line, const char *format, ...);

void MDFN_LoadGameCheats(void *override);
void MDFN_FlushGameCheats(int nosave);

void MDFN_MidSync(EmulateSpecStruct *espec);
void MDFN_MidLineUpdate(EmulateSpecStruct *espec, int y);

#include "mednafen-driver.h"

#include "mednafen-endian.h"
#include "mednafen-memory.h"

#endif
