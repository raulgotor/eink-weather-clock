/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef FLIPCLOCK_24
#define FLIPCLOCK_24 1
#endif

#if FLIPCLOCK_24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002D "-" */
    0xff, 0xff, 0xc0,

    /* U+002E "." */
    0xff, 0x80,

    /* U+0030 "0" */
    0x3f, 0x1f, 0xef, 0x3f, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xf8, 0x7e, 0x1f, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0xcf, 0x7f, 0x8f, 0xc0,

    /* U+0031 "1" */
    0x6, 0x1c, 0x7f, 0xff, 0xe1, 0xc3, 0x87, 0xe,
    0x1c, 0x38, 0x70, 0xe1, 0xc3, 0x87, 0xe, 0x1c,

    /* U+0032 "2" */
    0x3f, 0x1f, 0xef, 0x3f, 0x87, 0xe1, 0xf8, 0x70,
    0x3c, 0xe, 0x7, 0x83, 0xc1, 0xe0, 0xf0, 0x78,
    0x1c, 0xf, 0x3, 0x80, 0xff, 0xff, 0xf0,

    /* U+0033 "3" */
    0x3f, 0x1f, 0xee, 0x3f, 0x87, 0xe1, 0xc0, 0x70,
    0x3c, 0x7e, 0x1f, 0x80, 0xf0, 0x1c, 0x7, 0xe1,
    0xf8, 0x7e, 0x1f, 0xce, 0x7f, 0x8f, 0xc0,

    /* U+0034 "4" */
    0x7, 0x80, 0xf0, 0x3e, 0x7, 0xc0, 0xf8, 0x37,
    0x6, 0xe1, 0xdc, 0x33, 0x8e, 0x71, 0x8e, 0x71,
    0xcf, 0xff, 0xff, 0xc0, 0xe0, 0x1c, 0x3, 0x80,
    0x70,

    /* U+0035 "5" */
    0xff, 0xbf, 0xee, 0x3, 0x80, 0xe0, 0x38, 0xf,
    0xf3, 0xfe, 0xf3, 0x80, 0x70, 0x1c, 0x7, 0xe1,
    0xf8, 0x7e, 0x1f, 0xce, 0x7f, 0x8f, 0xc0,

    /* U+0036 "6" */
    0x1f, 0x1f, 0xe7, 0x1f, 0x87, 0xe0, 0x38, 0xe,
    0xf3, 0xfe, 0xf3, 0xf8, 0x7e, 0x1f, 0x87, 0xe1,
    0xf8, 0x7e, 0x1d, 0xce, 0x7f, 0x87, 0xc0,

    /* U+0037 "7" */
    0xff, 0xff, 0xf0, 0x1c, 0xe, 0x3, 0x81, 0xc0,
    0x70, 0x1c, 0xe, 0x3, 0x80, 0xe0, 0x78, 0x1c,
    0x7, 0x1, 0xc0, 0xf0, 0x3c, 0xf, 0x0,

    /* U+0038 "8" */
    0x3f, 0x1f, 0xef, 0x3f, 0x87, 0xe1, 0xf8, 0x7f,
    0x3d, 0xfe, 0x7f, 0xbc, 0xfe, 0x1f, 0x87, 0xe1,
    0xf8, 0x7e, 0x1f, 0xce, 0x7f, 0x8f, 0xc0,

    /* U+0039 "9" */
    0x3f, 0x1f, 0xe7, 0x3b, 0x87, 0xe1, 0xf8, 0x7e,
    0x1f, 0x87, 0xe1, 0xfc, 0xf7, 0xfc, 0xf7, 0x1,
    0xc0, 0x7e, 0x1f, 0xce, 0x7f, 0x8f, 0x80,

    /* U+0043 "C" */
    0x1f, 0x8f, 0xf9, 0xc7, 0xf0, 0x7e, 0xf, 0xc1,
    0xf8, 0x7, 0x0, 0xe0, 0x1c, 0x3, 0x80, 0x70,
    0x7e, 0xf, 0xc1, 0xf8, 0x3b, 0x8e, 0x7f, 0xc3,
    0xf0,

    /* U+00BA "º" */
    0x7b, 0xfc, 0xf3, 0xcf, 0x3c, 0xde
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 6, .box_h = 3, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 3, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 192, .box_w = 7, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 192, .box_w = 11, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 161, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 192, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 214, .box_w = 11, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 255, .adv_w = 115, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 10}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x1, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8,
    0x9, 0xa, 0xb, 0xc, 0x16, 0x8d
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 45, .range_length = 142, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 14, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    .cmap_num = 1,
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
const lv_font_t flipclock_24 = {
#else
lv_font_t flipclock_24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 18,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if FLIPCLOCK_24*/

