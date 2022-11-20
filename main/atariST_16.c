/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ATARIST_16
#define ATARIST_16 1
#endif

#if ATARIST_16

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0000 "\u0000" */
    0xaa, 0x2, 0x8, 0x8, 0x20, 0x20, 0x80, 0x82,
    0x2, 0xa8,

    /* U+0001 "\u0001" */
    0x10, 0x71, 0xf7, 0xff, 0xef, 0x8e, 0x8,

    /* U+0002 "\u0002" */
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55,
    0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55,

    /* U+0003 "\u0003" */
    0x92, 0x4f, 0x24, 0x90, 0x7, 0xc4, 0x10, 0x41,
    0x0,

    /* U+0004 "\u0004" */
    0xf2, 0xe, 0x20, 0x80, 0x3, 0xc8, 0x38, 0x82,
    0x0,

    /* U+0005 "\u0005" */
    0x72, 0x8, 0x20, 0x70, 0x3, 0x89, 0x38, 0xa2,
    0x40,

    /* U+0006 "\u0006" */
    0x82, 0x8, 0x20, 0xf0, 0x3, 0xc8, 0x38, 0x82,
    0x0,

    /* U+0007 "\u0007" */
    0x76, 0xe3, 0xb7, 0x0,

    /* U+0008 "\b" */
    0x30, 0xc3, 0x3f, 0xfc, 0xc3, 0xc, 0x3, 0xff,
    0xc0,

    /* U+0009 "\t" */
    0xc2, 0x8a, 0x28, 0xa0, 0x2, 0x8, 0x20, 0x83,
    0xc0,

    /* U+000A "\n" */
    0x8a, 0x25, 0x14, 0x20, 0x7, 0xc4, 0x10, 0x41,
    0x0,

    /* U+000B "\u000b" */
    0x18, 0xc6, 0x31, 0x8c, 0x7f, 0xf8,

    /* U+000C "\f" */
    0xff, 0xc6, 0x31, 0x8c, 0x63, 0x18,

    /* U+000D "\r" */
    0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc0,

    /* U+000E "\u000e" */
    0xc6, 0x31, 0x8c, 0x63, 0x1f, 0xf8,

    /* U+000F "\u000f" */
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff,
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+0010 "\u0010" */
    0xff, 0xff,

    /* U+0011 "\u0011" */
    0xff, 0xff,

    /* U+0012 "\u0012" */
    0xff, 0xff,

    /* U+0013 "\u0013" */
    0xff, 0xff,

    /* U+0014 "\u0014" */
    0xff, 0xff,

    /* U+0015 "\u0015" */
    0xc6, 0x31, 0x8c, 0x63, 0x1f, 0xfe, 0x31, 0x8c,
    0x63, 0x18,

    /* U+0016 "\u0016" */
    0x18, 0xc6, 0x31, 0x8c, 0x7f, 0xf8, 0xc6, 0x31,
    0x8c, 0x63,

    /* U+0017 "\u0017" */
    0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff,
    0xff,

    /* U+0018 "\u0018" */
    0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18,

    /* U+0019 "\u0019" */
    0xff, 0xff, 0xff, 0xff,

    /* U+001A "\u001a" */
    0xe, 0x38, 0xe3, 0x8e, 0xe, 0xe, 0xe, 0xe,
    0x3, 0xff, 0xf0,

    /* U+001B "\u001b" */
    0xe0, 0x70, 0x38, 0x1c, 0xe, 0x1c, 0x38, 0x70,
    0xe0, 0x0, 0xff, 0xff,

    /* U+001C "\u001c" */
    0xff, 0xfd, 0xb3, 0x66, 0xcd, 0x9b, 0x36, 0x6c,

    /* U+001D "\u001d" */
    0xc, 0x31, 0xbf, 0xfc, 0x0, 0x3f, 0xfd, 0x8c,
    0x30,

    /* U+001E "\u001e" */
    0xe, 0x1e, 0x38, 0x30, 0x30, 0x30, 0x30, 0xfe,
    0x30, 0x30, 0x30, 0x7f, 0xff,

    /* U+001F "\u001f" */
    0x6f, 0xf6,

    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xf,

    /* U+0022 "\"" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0023 "#" */
    0x66, 0x66, 0xff, 0xff, 0x66, 0x66, 0xff, 0xff,
    0x66, 0x66,

    /* U+0024 "$" */
    0x30, 0xc7, 0xff, 0xc3, 0xf, 0x9f, 0xc, 0x3f,
    0xfe, 0x30, 0xc0,

    /* U+0025 "%" */
    0xcf, 0x3d, 0x86, 0x30, 0xc6, 0x1b, 0xcf, 0x30,

    /* U+0026 "&" */
    0x38, 0xf9, 0xb3, 0x63, 0x87, 0x1c, 0x38, 0xdf,
    0xbf, 0x36, 0x6f, 0xee, 0xc0,

    /* U+0027 "'" */
    0xff, 0xf0,

    /* U+0028 "(" */
    0x36, 0xec, 0xcc, 0xcc, 0xce, 0x63,

    /* U+0029 ")" */
    0xc6, 0x73, 0x33, 0x33, 0x37, 0x6c,

    /* U+002A "*" */
    0x66, 0x66, 0x3c, 0x3c, 0xff, 0xff, 0x3c, 0x3c,
    0x66, 0x66,

    /* U+002B "+" */
    0x30, 0xc3, 0x3f, 0xfc, 0xc3, 0xc,

    /* U+002C "," */
    0x6d, 0xbd, 0x0,

    /* U+002D "-" */
    0xff, 0xf0,

    /* U+002E "." */
    0xff,

    /* U+002F "/" */
    0xc, 0x30, 0xc6, 0x18, 0xc3, 0x18, 0x63, 0xc,
    0x30,

    /* U+0030 "0" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x7e, 0xf3, 0xcf, 0x3f,
    0xde,

    /* U+0031 "1" */
    0x30, 0xc7, 0x1c, 0x30, 0xc3, 0xc, 0x30, 0xcf,
    0xff,

    /* U+0032 "2" */
    0x7b, 0xfc, 0xf3, 0x18, 0x63, 0xc, 0x61, 0x8f,
    0xff,

    /* U+0033 "3" */
    0xff, 0xf1, 0x86, 0x30, 0xc1, 0x86, 0xcf, 0x3f,
    0xde,

    /* U+0034 "4" */
    0x18, 0x63, 0x8e, 0x79, 0xed, 0xb6, 0xff, 0xf1,
    0x86,

    /* U+0035 "5" */
    0xff, 0xfc, 0x30, 0xfb, 0xf0, 0xc3, 0xf, 0x3f,
    0xde,

    /* U+0036 "6" */
    0x39, 0xee, 0x30, 0xc3, 0xef, 0xf3, 0xcf, 0x3f,
    0xde,

    /* U+0037 "7" */
    0xff, 0xf0, 0xc3, 0x18, 0x63, 0xc, 0x61, 0x86,
    0x18,

    /* U+0038 "8" */
    0x7b, 0xfc, 0xf3, 0x79, 0xec, 0xf3, 0xcf, 0x3f,
    0xde,

    /* U+0039 "9" */
    0x7b, 0xfc, 0xf3, 0xfd, 0xf0, 0xc3, 0xc, 0x77,
    0x9c,

    /* U+003A ":" */
    0xff, 0xf, 0xf0,

    /* U+003B ";" */
    0x6d, 0xb0, 0x1b, 0x6f, 0x40,

    /* U+003C "<" */
    0xe, 0x38, 0xe3, 0x8e, 0xe, 0xe, 0xe, 0xe,

    /* U+003D "=" */
    0xff, 0xf0, 0x0, 0xff, 0xf0,

    /* U+003E ">" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xe3, 0x8e, 0x38, 0xe0,

    /* U+003F "?" */
    0x7b, 0xfc, 0xf3, 0x18, 0x63, 0xc, 0x30, 0x3,
    0xc,

    /* U+0040 "@" */
    0x38, 0xfb, 0x9e, 0x1d, 0xba, 0xf5, 0xee, 0xc1,
    0xc5, 0xf9, 0xe0,

    /* U+0041 "A" */
    0x31, 0xef, 0xf3, 0xcf, 0x3f, 0xff, 0xcf, 0x3c,
    0xf3,

    /* U+0042 "B" */
    0xfb, 0xfc, 0xf3, 0xff, 0xec, 0xf3, 0xcf, 0x3f,
    0xfe,

    /* U+0043 "C" */
    0x7b, 0xfc, 0xf3, 0xc3, 0xc, 0x30, 0xcf, 0x3f,
    0xde,

    /* U+0044 "D" */
    0xf3, 0xed, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x7f,
    0xbc,

    /* U+0045 "E" */
    0xff, 0xfc, 0x30, 0xfb, 0xec, 0x30, 0xc3, 0xf,
    0xff,

    /* U+0046 "F" */
    0xff, 0xfc, 0x30, 0xfb, 0xec, 0x30, 0xc3, 0xc,
    0x30,

    /* U+0047 "G" */
    0x7f, 0xfc, 0x30, 0xdf, 0x7c, 0xf3, 0xcf, 0x3f,
    0xde,

    /* U+0048 "H" */
    0xcf, 0x3c, 0xf3, 0xff, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3,

    /* U+0049 "I" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xcf,
    0xff,

    /* U+004A "J" */
    0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xcf, 0x3f,
    0xde,

    /* U+004B "K" */
    0xcd, 0x9b, 0x66, 0xcf, 0x1e, 0x36, 0x6c, 0xcd,
    0x9b, 0x1e, 0x30,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf,
    0xff,

    /* U+004D "M" */
    0xc7, 0x8f, 0xbf, 0x7f, 0xfa, 0xf5, 0xe3, 0xc7,
    0x8f, 0x1e, 0x30,

    /* U+004E "N" */
    0xcf, 0x3c, 0xfb, 0xef, 0xff, 0xf7, 0xdf, 0x3c,
    0xf3,

    /* U+004F "O" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3f,
    0xde,

    /* U+0050 "P" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3f, 0xfe, 0xc3, 0xc,
    0x30,

    /* U+0051 "Q" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x5f,
    0x9b,

    /* U+0052 "R" */
    0xf9, 0xfb, 0x36, 0x6c, 0xdf, 0xbe, 0x6c, 0xcd,
    0x9b, 0x1e, 0x30,

    /* U+0053 "S" */
    0x7f, 0xfc, 0x30, 0xe1, 0xc3, 0x87, 0xc, 0x3f,
    0xfe,

    /* U+0054 "T" */
    0xff, 0xf3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc,

    /* U+0055 "U" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcf, 0x3f,
    0xde,

    /* U+0056 "V" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x79, 0xe3,
    0xc,

    /* U+0057 "W" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x7a, 0xf5, 0xff, 0xff,
    0xdf, 0x1c, 0x10,

    /* U+0058 "X" */
    0xcf, 0x3c, 0xde, 0x78, 0xc3, 0x1e, 0x7b, 0x3c,
    0xf3,

    /* U+0059 "Y" */
    0xcf, 0x3c, 0xf3, 0x79, 0xe3, 0xc, 0x30, 0xc3,
    0xc,

    /* U+005A "Z" */
    0xff, 0xf1, 0x86, 0x30, 0xc6, 0x18, 0xc3, 0xf,
    0xff,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xff,

    /* U+005C "\\" */
    0xc3, 0xc, 0x18, 0x60, 0xc3, 0x6, 0x18, 0x30,
    0xc3,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0xff,

    /* U+005E "^" */
    0x10, 0x20, 0xe1, 0xc6, 0xcd, 0xb1, 0xe3,

    /* U+005F "_" */
    0xff, 0xfc,

    /* U+0060 "`" */
    0x86, 0x38, 0xe3, 0x8c, 0x20,

    /* U+0061 "a" */
    0x79, 0xf0, 0xdf, 0xff, 0x3c, 0xff, 0x7c,

    /* U+0062 "b" */
    0xc3, 0xc, 0x3e, 0xff, 0x3c, 0xf3, 0xcf, 0x3f,
    0xfe,

    /* U+0063 "c" */
    0x7b, 0xec, 0x30, 0xc3, 0xc, 0x3f, 0x7c,

    /* U+0064 "d" */
    0xc, 0x30, 0xdf, 0xff, 0x3c, 0xf3, 0xcf, 0x3f,
    0xdf,

    /* U+0065 "e" */
    0x7b, 0xfc, 0xf3, 0xff, 0xc, 0x3f, 0x7c,

    /* U+0066 "f" */
    0x1c, 0xf3, 0xc, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc,

    /* U+0067 "g" */
    0x7f, 0xfc, 0xf3, 0xcf, 0x3f, 0xdf, 0xf, 0xff,
    0x80,

    /* U+0068 "h" */
    0xc3, 0xc, 0x3e, 0xff, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3,

    /* U+0069 "i" */
    0x66, 0xe, 0xe6, 0x66, 0x66, 0xff,

    /* U+006A "j" */
    0x18, 0xc0, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x3f,
    0xf8,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0x6d, 0xdf, 0x3c, 0x7c, 0xd9,
    0x9b, 0x3e, 0x30,

    /* U+006C "l" */
    0xee, 0x66, 0x66, 0x66, 0x66, 0xff,

    /* U+006D "m" */
    0x6d, 0xff, 0xfe, 0xbd, 0x7a, 0xf1, 0xe3, 0xc6,

    /* U+006E "n" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xf3, 0xcc,

    /* U+006F "o" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0x78,

    /* U+0070 "p" */
    0xfb, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0xfb, 0xc,
    0x0,

    /* U+0071 "q" */
    0x7f, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0x7c, 0x30,
    0xc0,

    /* U+0072 "r" */
    0xfb, 0xfc, 0xf0, 0xc3, 0xc, 0x30, 0xc0,

    /* U+0073 "s" */
    0x7f, 0xfc, 0x38, 0x78, 0x70, 0xff, 0xf8,

    /* U+0074 "t" */
    0x30, 0xcf, 0xff, 0x30, 0xc3, 0xc, 0x30, 0xf1,
    0xc0,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xff, 0x7c,

    /* U+0076 "v" */
    0xcf, 0x3c, 0xf3, 0xcd, 0xe7, 0x8c, 0x30,

    /* U+0077 "w" */
    0xc7, 0x8f, 0x5e, 0xbf, 0xff, 0xfb, 0xe3, 0x82,

    /* U+0078 "x" */
    0xcf, 0x37, 0x9e, 0x31, 0xe7, 0xb3, 0xcc,

    /* U+0079 "y" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3f, 0xdf, 0xf, 0xff,
    0x80,

    /* U+007A "z" */
    0xff, 0xf1, 0x8c, 0x31, 0x86, 0x3f, 0xfc,

    /* U+007B "{" */
    0xe, 0x30, 0x60, 0xc1, 0x87, 0x3c, 0x78, 0x38,
    0x30, 0x60, 0xc1, 0x81, 0xc0,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xf0,

    /* U+007D "}" */
    0xe0, 0x60, 0xc1, 0x83, 0x7, 0x7, 0x8f, 0x38,
    0x60, 0xc1, 0x83, 0x1c, 0x0,

    /* U+007E "~" */
    0x63, 0xe6, 0xfc, 0xe0,

    /* U+007F "" */
    0x18, 0x18, 0x3c, 0x24, 0x66, 0x42, 0xc3, 0xff,

    /* U+0080 "" */
    0xff, 0xfc,

    /* U+0081 "" */
    0x18, 0x3c, 0x66, 0xc3, 0x81, 0xe7, 0x24, 0x24,
    0x24, 0x3c,

    /* U+0082 "" */
    0x3c, 0x24, 0x24, 0x24, 0xe7, 0x81, 0xc3, 0x66,
    0x3c, 0x18,

    /* U+0083 "" */
    0x30, 0x38, 0x2c, 0xe6, 0x83, 0x83, 0xe6, 0x2c,
    0x38, 0x30,

    /* U+0084 "" */
    0xc, 0x1c, 0x34, 0x67, 0xc1, 0xc1, 0x67, 0x34,
    0x1c, 0xc,

    /* U+0085 "" */
    0x7c, 0x72, 0xec, 0x9d, 0x78, 0xf5, 0xc9, 0xba,
    0x71, 0xf0,

    /* U+0086 "" */
    0xff, 0xff, 0xff, 0xef, 0xdf, 0x3e, 0xf9, 0xf7,
    0xcf, 0xb8,

    /* U+0087 "" */
    0xef, 0x8f, 0x5c, 0x9b, 0xa7, 0x2e, 0xc9, 0xd7,
    0x8f, 0xb8,

    /* U+0088 "" */
    0x1, 0x1, 0x3, 0x3, 0x6, 0x6, 0x8c, 0x8c,
    0xd8, 0x58, 0x70, 0x30, 0x20,

    /* U+0089 "" */
    0x3c, 0x66, 0xc3, 0x91, 0x91, 0x9d, 0x81, 0xc3,
    0x66, 0x3c,

    /* U+008A "" */
    0x18, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x7e, 0xff,
    0x10, 0x38, 0x10,

    /* U+008B "" */
    0x8, 0xe, 0xf, 0x9, 0x8, 0x8, 0x78, 0xf8,
    0x70,

    /* U+008C "" */
    0xf2, 0xe, 0x20, 0x80, 0x3, 0xc8, 0x38, 0x82,
    0x0,

    /* U+008D "" */
    0x72, 0x8, 0x20, 0x70, 0x3, 0x89, 0x38, 0xa2,
    0x40,

    /* U+008E "" */
    0x0,

    /* U+008F "" */
    0x0,

    /* U+0090 "" */
    0x7d, 0x77, 0x1e, 0x3c, 0x70, 0x40, 0x41, 0xc7,
    0x8f, 0x1d, 0xd7, 0xc0,

    /* U+0091 "" */
    0x7f, 0x47, 0xf4,

    /* U+0092 "" */
    0x7c, 0x74, 0x18, 0x30, 0x67, 0x5f, 0x5c, 0xc1,
    0x83, 0x5, 0xc7, 0xc0,

    /* U+0093 "" */
    0xf9, 0xd0, 0xc3, 0xd, 0xdf, 0x9d, 0xc, 0x30,
    0xdd, 0xf8,

    /* U+0094 "" */
    0x83, 0x8f, 0x1e, 0x3b, 0xaf, 0x8e, 0x83, 0x6,
    0xc, 0x8,

    /* U+0095 "" */
    0x7d, 0x73, 0x6, 0xc, 0x17, 0x1f, 0x1d, 0x6,
    0xc, 0x19, 0xd7, 0xc0,

    /* U+0096 "" */
    0x7d, 0x73, 0x6, 0xc, 0x17, 0x1f, 0x5d, 0xc7,
    0x8f, 0x1d, 0xd7, 0xc0,

    /* U+0097 "" */
    0x7d, 0x77, 0x1e, 0x3c, 0x70, 0x40, 0x1, 0x6,
    0xc, 0x18, 0x10,

    /* U+0098 "" */
    0x7d, 0x77, 0x1e, 0x3c, 0x77, 0x5f, 0x5d, 0xc7,
    0x8f, 0x1d, 0xd7, 0xc0,

    /* U+0099 "" */
    0x7d, 0x77, 0x1e, 0x3c, 0x77, 0x5f, 0x1d, 0x6,
    0xc, 0x19, 0xd7, 0xc0,

    /* U+009A "" */
    0xfb, 0xf0, 0xc3, 0xff, 0x3c, 0xff, 0x78,

    /* U+009B "" */
    0xf2, 0xe, 0x20, 0xf0, 0x1, 0xc8, 0x18, 0x13,
    0x80,

    /* U+009C "" */
    0x0,

    /* U+009D "" */
    0x0,

    /* U+009E "" */
    0x0,

    /* U+009F "" */
    0x1c, 0xf3, 0xc, 0x33, 0xf3, 0xc, 0x30, 0xc3,
    0x38, 0xc0,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xf3, 0xff, 0xff,

    /* U+00A2 "¢" */
    0x30, 0xc7, 0xbf, 0xcf, 0xc, 0x33, 0xfd, 0xe3,
    0xc,

    /* U+00A3 "£" */
    0xe, 0x1e, 0x38, 0x30, 0x30, 0x30, 0x30, 0xfe,
    0x30, 0x30, 0x30, 0x7f, 0xff,

    /* U+00A5 "¥" */
    0xcf, 0x3c, 0xf3, 0xfd, 0xe3, 0x3f, 0x30, 0xc3,
    0xc,

    /* U+00A7 "§" */
    0x39, 0xb6, 0x4c, 0x7b, 0x3c, 0xde, 0x32, 0x6d,
    0x9c,

    /* U+00A9 "©" */
    0x7d, 0x8e, 0xd, 0xda, 0x34, 0x68, 0xdd, 0x83,
    0x8d, 0xf0,

    /* U+00AA "ª" */
    0x79, 0xf0, 0xdf, 0xff, 0x3c, 0xff, 0x7c, 0xf,
    0xc0,

    /* U+00AB "«" */
    0x1a, 0x6d, 0xb6, 0xc6, 0xc6, 0xc6, 0x80,

    /* U+00AC "¬" */
    0xff, 0xf0, 0xc3, 0xc,

    /* U+00AD "­" */
    0xff,

    /* U+00AE "®" */
    0x7d, 0x8e, 0xd, 0xda, 0xb6, 0x6e, 0xd5, 0x83,
    0x8d, 0xf0,

    /* U+00AF "¯" */
    0xff, 0xfc,

    /* U+00B0 "°" */
    0x76, 0xe3, 0xb7, 0x0,

    /* U+00B1 "±" */
    0x30, 0xc3, 0x3f, 0xfc, 0xc3, 0xc, 0x3, 0xff,
    0xc0,

    /* U+00B2 "²" */
    0x69, 0x36, 0xcf,

    /* U+00B3 "³" */
    0xf3, 0x63, 0x96,

    /* U+00B5 "µ" */
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7f, 0x5d,
    0xc0, 0x80,

    /* U+00B6 "¶" */
    0x7b, 0x97, 0x2e, 0x5c, 0xb9, 0x5e, 0x85, 0xa,
    0x14, 0x28, 0x50,

    /* U+00B7 "·" */
    0x6f, 0xf6,

    /* U+00B9 "¹" */
    0xd5, 0x50,

    /* U+00BA "º" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xff, 0x78, 0xf,
    0xc0,

    /* U+00BB "»" */
    0xb1, 0xb1, 0xb1, 0xb6, 0xdb, 0x2c, 0x0,

    /* U+00BF "¿" */
    0x30, 0xc0, 0xc, 0x30, 0xc6, 0x18, 0xcf, 0x3f,
    0xde,

    /* U+00C0 "À" */
    0xc1, 0x83, 0x0, 0x7b, 0xfc, 0xf3, 0xff, 0xfc,
    0xf3, 0xcf, 0x30,

    /* U+00C1 "Á" */
    0xc, 0x63, 0x0, 0x7b, 0xfc, 0xf3, 0xff, 0xfc,
    0xf3, 0xcf, 0x30,

    /* U+00C2 "Â" */
    0x31, 0xec, 0xc0, 0x7b, 0xfc, 0xf3, 0xff, 0xfc,
    0xf3, 0xcf, 0x30,

    /* U+00C3 "Ã" */
    0x67, 0xd9, 0x80, 0x7b, 0xfc, 0xf3, 0xff, 0xfc,
    0xf3, 0xcf, 0x30,

    /* U+00C4 "Ä" */
    0xcf, 0x33, 0x1e, 0xff, 0x3c, 0xff, 0xff, 0x3c,
    0xf3, 0xcc,

    /* U+00C5 "Å" */
    0x7b, 0x37, 0x8c, 0x7b, 0xfc, 0xf3, 0xff, 0xfc,
    0xf3, 0xcf, 0x30,

    /* U+00C6 "Æ" */
    0x3e, 0xff, 0xe6, 0xcd, 0x9b, 0xf7, 0xfc, 0xf9,
    0xb3, 0x66, 0xfd, 0xe0,

    /* U+00C7 "Ç" */
    0x7b, 0xfc, 0xf3, 0xc3, 0xc, 0x30, 0xcf, 0x3f,
    0xde, 0x19, 0xc0,

    /* U+00C8 "È" */
    0xc1, 0x83, 0x0, 0xff, 0xfc, 0x3e, 0xfb, 0xc,
    0x30, 0xff, 0xf0,

    /* U+00C9 "É" */
    0xc, 0x63, 0x0, 0xff, 0xfc, 0x3e, 0xfb, 0xc,
    0x30, 0xff, 0xf0,

    /* U+00CA "Ê" */
    0x31, 0xec, 0xc0, 0xff, 0xfc, 0x3e, 0xfb, 0xc,
    0x30, 0xff, 0xf0,

    /* U+00CB "Ë" */
    0xcf, 0x30, 0x3f, 0xff, 0xf, 0xbe, 0xc3, 0xc,
    0x3f, 0xfc,

    /* U+00CC "Ì" */
    0xc1, 0x83, 0x0, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc, 0xff, 0xf0,

    /* U+00CD "Í" */
    0xc, 0x63, 0x0, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc, 0xff, 0xf0,

    /* U+00CE "Î" */
    0x31, 0xec, 0xc0, 0xff, 0xf3, 0xc, 0x30, 0xc3,
    0xc, 0xff, 0xf0,

    /* U+00CF "Ï" */
    0xcf, 0x30, 0x3f, 0xfc, 0xc3, 0xc, 0x30, 0xc3,
    0x3f, 0xfc,

    /* U+00D0 "Ð" */
    0x78, 0xf9, 0xbb, 0x36, 0x7e, 0xfd, 0xb3, 0x66,
    0xdd, 0xf3, 0xc0,

    /* U+00D1 "Ñ" */
    0x67, 0xd9, 0x80, 0xcf, 0x3e, 0xff, 0xff, 0x7c,
    0xf3, 0xcc,

    /* U+00D2 "Ò" */
    0xc1, 0x83, 0x0, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+00D3 "Ó" */
    0xc, 0x63, 0x0, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+00D4 "Ô" */
    0x31, 0xec, 0xc0, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+00D5 "Õ" */
    0x67, 0xd9, 0x80, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+00D6 "Ö" */
    0xcf, 0x30, 0x1e, 0xff, 0x3c, 0xf3, 0xcf, 0x3c,
    0xff, 0x78,

    /* U+00D7 "×" */
    0xcd, 0xe3, 0x1e, 0xcc,

    /* U+00D8 "Ø" */
    0x1, 0x3d, 0x7e, 0x66, 0x66, 0x6e, 0x6e, 0x76,
    0x76, 0x66, 0x66, 0x7e, 0xbc, 0x80,

    /* U+00D9 "Ù" */
    0xc1, 0x83, 0x0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+00DA "Ú" */
    0xc, 0x63, 0x0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+00DB "Û" */
    0x31, 0xec, 0xc0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0xfd, 0xe0,

    /* U+00DC "Ü" */
    0xcf, 0x30, 0x33, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xff, 0x78,

    /* U+00DD "Ý" */
    0xc, 0x63, 0x0, 0xcf, 0x3c, 0xf3, 0x79, 0xe3,
    0xc, 0x30, 0xc0,

    /* U+00DE "Þ" */
    0xc3, 0xf, 0xbf, 0xcf, 0x3c, 0xff, 0xfb, 0xc,
    0x30,

    /* U+00DF "ß" */
    0x31, 0xec, 0xf3, 0xcf, 0xec, 0xf3, 0xcf, 0xed,
    0xb0, 0x80,

    /* U+00E0 "à" */
    0xc1, 0x83, 0x0, 0x79, 0xf0, 0xdf, 0xff, 0x3c,
    0xff, 0x7c,

    /* U+00E1 "á" */
    0xc, 0x63, 0x0, 0x79, 0xf0, 0xdf, 0xff, 0x3c,
    0xff, 0x7c,

    /* U+00E2 "â" */
    0x31, 0xec, 0xc0, 0x79, 0xf0, 0xdf, 0xff, 0x3c,
    0xff, 0x7c,

    /* U+00E3 "ã" */
    0x67, 0xd9, 0x80, 0x79, 0xf0, 0xdf, 0xff, 0x3c,
    0xff, 0x7c,

    /* U+00E4 "ä" */
    0xcf, 0x30, 0x1e, 0x7c, 0x37, 0xff, 0xcf, 0x3f,
    0xdf,

    /* U+00E5 "å" */
    0x39, 0xb3, 0x80, 0x79, 0xf0, 0xdf, 0xff, 0x3c,
    0xff, 0x7c,

    /* U+00E6 "æ" */
    0x76, 0x7f, 0x1b, 0x7b, 0xff, 0xd8, 0xd8, 0xff,
    0x7f,

    /* U+00E7 "ç" */
    0x7b, 0xec, 0x30, 0xc3, 0xc, 0x3f, 0x7c, 0x67,
    0x0,

    /* U+00E8 "è" */
    0xc1, 0x83, 0x0, 0x7b, 0xfc, 0xf3, 0xff, 0xc,
    0x3f, 0x7c,

    /* U+00E9 "é" */
    0xc, 0x63, 0x0, 0x7b, 0xfc, 0xf3, 0xff, 0xc,
    0x3f, 0x7c,

    /* U+00EA "ê" */
    0x31, 0xec, 0xc0, 0x7b, 0xfc, 0xf3, 0xff, 0xc,
    0x3f, 0x7c,

    /* U+00EB "ë" */
    0xcf, 0x30, 0x1e, 0xff, 0x3c, 0xff, 0xc3, 0xf,
    0xdf,

    /* U+00EC "ì" */
    0xc3, 0xc, 0x7, 0x38, 0xc6, 0x31, 0x8c, 0xf7,
    0x80,

    /* U+00ED "í" */
    0x19, 0x98, 0xe, 0x71, 0x8c, 0x63, 0x19, 0xef,
    0x0,

    /* U+00EE "î" */
    0x31, 0xec, 0xc0, 0x71, 0xc3, 0xc, 0x30, 0xc3,
    0x1e, 0x78,

    /* U+00EF "ï" */
    0xcf, 0x30, 0x1c, 0x70, 0xc3, 0xc, 0x30, 0xc7,
    0x9e,

    /* U+00F0 "ð" */
    0x78, 0xc7, 0x86, 0x7f, 0xfc, 0xf3, 0xcf, 0x3c,
    0xff, 0x78,

    /* U+00F1 "ñ" */
    0x67, 0xd9, 0x80, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xf3, 0xcc,

    /* U+00F2 "ò" */
    0xc1, 0x83, 0x0, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xff, 0x78,

    /* U+00F3 "ó" */
    0xc, 0x63, 0x0, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xff, 0x78,

    /* U+00F4 "ô" */
    0x31, 0xec, 0xc0, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xff, 0x78,

    /* U+00F5 "õ" */
    0x67, 0xd9, 0x80, 0x7b, 0xfc, 0xf3, 0xcf, 0x3c,
    0xff, 0x78,

    /* U+00F6 "ö" */
    0xcf, 0x30, 0x1e, 0xff, 0x3c, 0xf3, 0xcf, 0x3f,
    0xde,

    /* U+00F7 "÷" */
    0x30, 0xc0, 0x3f, 0xfc, 0x3, 0xc,

    /* U+00F8 "ø" */
    0x1, 0x3d, 0x7e, 0x66, 0x6e, 0x7e, 0x76, 0x66,
    0x7e, 0xbc, 0x80,

    /* U+00F9 "ù" */
    0xc1, 0x83, 0x0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xff, 0x7c,

    /* U+00FA "ú" */
    0xc, 0x63, 0x0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xff, 0x7c,

    /* U+00FB "û" */
    0x31, 0xec, 0xc0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xff, 0x7c,

    /* U+00FC "ü" */
    0xcf, 0x30, 0x33, 0xcf, 0x3c, 0xf3, 0xcf, 0x3f,
    0xdf,

    /* U+00FD "ý" */
    0xc, 0x63, 0x0, 0xcf, 0x3c, 0xf3, 0xcf, 0x3f,
    0xdf, 0xf, 0xff, 0x80,

    /* U+00FE "þ" */
    0xc3, 0xc, 0x3e, 0xff, 0x3c, 0xf3, 0xcf, 0x3f,
    0xfe, 0xc3, 0x0,

    /* U+00FF "ÿ" */
    0xcf, 0x30, 0x33, 0xcf, 0x3c, 0xf3, 0xcf, 0xf7,
    0xc3, 0xff, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 17, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 33, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 42, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 51, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 60, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 69, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 73, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 91, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 100, .adv_w = 128, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 106, .adv_w = 128, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 112, .adv_w = 128, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 118, .adv_w = 128, .box_w = 5, .box_h = 9, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 124, .adv_w = 128, .box_w = 8, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 140, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 142, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 8},
    {.bitmap_index = 144, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 146, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 148, .adv_w = 128, .box_w = 8, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 150, .adv_w = 128, .box_w = 5, .box_h = 16, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 160, .adv_w = 128, .box_w = 5, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 170, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 179, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 188, .adv_w = 128, .box_w = 2, .box_h = 16, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 192, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 128, .box_w = 8, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 223, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 232, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 247, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 128, .box_w = 2, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 256, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 266, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 285, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 298, .adv_w = 128, .box_w = 2, .box_h = 6, .ofs_x = 3, .ofs_y = 6},
    {.bitmap_index = 300, .adv_w = 128, .box_w = 4, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 306, .adv_w = 128, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 322, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 328, .adv_w = 128, .box_w = 3, .box_h = 6, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 331, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 333, .adv_w = 128, .box_w = 2, .box_h = 4, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 343, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 361, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 388, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 415, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 128, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 128, .box_w = 3, .box_h = 12, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 441, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 449, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 454, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 462, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 471, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 500, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 563, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 572, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 630, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 668, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 697, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 715, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 724, .adv_w = 128, .box_w = 4, .box_h = 12, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 730, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 739, .adv_w = 128, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 745, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 752, .adv_w = 128, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 754, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 759, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 766, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 791, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 798, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 807, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 816, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 825, .adv_w = 128, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 128, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 840, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 851, .adv_w = 128, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 857, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 865, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 872, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 888, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 897, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 904, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 920, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 927, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 934, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 942, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 949, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 958, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 965, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 978, .adv_w = 128, .box_w = 2, .box_h = 14, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 982, .adv_w = 128, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 995, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 999, .adv_w = 128, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1007, .adv_w = 128, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 1009, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1019, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1029, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1039, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1049, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1059, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1069, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1079, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1092, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1102, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1113, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1122, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1131, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1140, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1141, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1142, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1154, .adv_w = 128, .box_w = 2, .box_h = 11, .ofs_x = 5, .ofs_y = 1},
    {.bitmap_index = 1157, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1169, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1179, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1189, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1201, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1213, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1224, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1236, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1248, .adv_w = 128, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1255, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1264, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1265, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1266, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1267, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1277, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1278, .adv_w = 128, .box_w = 2, .box_h = 12, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 1281, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1290, .adv_w = 128, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1303, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1312, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1321, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1331, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1340, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1347, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1351, .adv_w = 128, .box_w = 4, .box_h = 2, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 1352, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1362, .adv_w = 128, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 1364, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 1368, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1377, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 1380, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 1383, .adv_w = 128, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1393, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1404, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 1406, .adv_w = 128, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 1408, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1417, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1424, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1433, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1444, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1455, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1466, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1477, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1487, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1498, .adv_w = 128, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1510, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1521, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1532, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1543, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1554, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1564, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1575, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1586, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1597, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1607, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1618, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1628, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1639, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1650, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1661, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1672, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1682, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1686, .adv_w = 128, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1700, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1711, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1722, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1733, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1743, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1754, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1763, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1773, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1783, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1793, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1803, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1813, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1822, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1832, .adv_w = 128, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1841, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1850, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1860, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1870, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1880, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1889, .adv_w = 128, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1898, .adv_w = 128, .box_w = 5, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1907, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1917, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1926, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1936, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1946, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1956, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1966, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1976, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1986, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1995, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 2001, .adv_w = 128, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2012, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2022, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2032, .adv_w = 128, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2042, .adv_w = 128, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2051, .adv_w = 128, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2063, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2074, .adv_w = 128, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_1[] = {
    0, 0, 1, 0, 2, 3, 4, 5,
    6, 7, 8, 9, 10, 11, 12, 0,
    13, 14, 15, 0, 16, 17, 18
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 0, .range_length = 164, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 165, .range_length = 23, .glyph_id_start = 165,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_1, .list_length = 23, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 191, .range_length = 65, .glyph_id_start = 184,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t atariST_16 = {
#else
lv_font_t atariST_16 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if ATARIST_16*/

