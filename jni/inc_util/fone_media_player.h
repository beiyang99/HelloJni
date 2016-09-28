
/*************************************************

  Copyright (C), 2001-2010, Fone Net Info �C Tech Co., Ltd

  File name:      fone_media_player.h

  Description:

  Others:

*************************************************/

#ifndef _FONE_MEDIA_PLAYER_H_
#define _FONE_MEDIA_PLAYER_H_

#include "fone_std.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct tagFoneVideoDesc
{
	FN_CodecID                   eVideoSurfaceFmt;
	FN_UINT                                  nWidth;
	FN_UINT                                  nHeight;

	FN_UINT                                  nBitRate;
	FN_UINT                                  nFrameRate;
	FN_UINT                                  nSizeImage ;
}FoneVideoDesc_t;

typedef struct tagFoneAudioDesc
{
	FN_CodecID                       eAudioSampleFmt;
	FN_INT							eChannelCount;
	FN_INT                     		euiFreq;
	FN_UINT                                    uiBitCount;
	FN_UINT                                    uiBitsPerSample;
	FN_CHAR                                    strSongName[32]; 
	FN_CHAR                                    strSpecialName[32];
	FN_CHAR                                    strSingerName[32];
	FN_UINT                                    uiKbps;
}FoneAudioDesc_t;

typedef struct tagFoneMediaMuxerDesc
{
	FN_CodecID                       eVideoSurfaceFmt;
	FN_CodecID                       eAudioSampleFmt;
	FN_UINT                                    uiVideoSurfaceCount;
	FN_UINT                                    uiAudioSampleCount;
	FN_64                                   duration;
	FN_BOOL									is_network_media;
	FN_BOOL									is_live_media;
    FN_UINT                                 have_av; // 0:av, 1:a, 2:v
}FoneMediaMuxerDesc_t;


typedef enum tagFone_player_ui_message
{
	FN_PLAYER_MESSAGE_NONE = 0,
	FN_PLAYER_MESSAGE_OPEN_SUCCESS,         
	FN_PLAYER_MESSAGE_OPEN_FAILED,
	FN_PLAYER_MESSAGE_PAUSE_RESULT,
	FN_PLAYER_MESSAGE_BUFFERING_START,
	FN_PLAYER_MESSAGE_BUFFERING_PERCENT,           
	FN_PLAYER_MESSAGE_READY_TO_PLAY,
	FN_PLAYER_MESSAGE_SEEK_THUMBNAIL,
	FN_PLAYER_MESSAGE_END_OF_FILE,          
	FN_PLAYER_MESSAGE_MEDIA_CURRENT_POS,
	FN_PLAYER_MESSAGE_MEDIA_CACHED_POS,
	FN_PLAYER_MESSAGE_NOTIFICATION,
	FN_PLAYER_MESSAGE_DISPLAY_FRAME,
	FN_PLAYER_MESSAGE_END,
}Fone_player_message_e;

typedef enum tagFone_player_open_error_code
{
	FN_PLAYER_OPEN_ERR_NONE = 0,
	FN_PLAYER_OPEN_ERR_FORMAT,
	FN_PLAYER_OPEN_ERR_IO,
	FN_PLAYER_OPEN_ERR_TIMEOUT,
	FN_PLAYER_OPEN_ERR_UNKNOWN,
} Fone_player_open_error_code;

FN_BOOL fone_media_player_init(int screenW, int screenH);
FN_BOOL fone_media_player_uninit(FN_VOID);

FN_BOOL fone_media_player_open(FN_CONST FN_UTF8* a_pszUrlOrPathname);
FN_BOOL fone_media_player_close(FN_VOID);
FN_BOOL fone_media_player_start(FN_VOID);
FN_BOOL fone_media_player_stop(FN_VOID);
FN_BOOL fone_media_player_pause(FN_VOID);
FN_INT  fone_media_player_seek_to(FN_SIZE a_SeekPos);
FN_BOOL fone_media_player_play(FN_VOID);
FN_INT  fone_media_player_set_audio_volume(FN_SIZE a_nVolume);
FN_INT  fone_media_player_get_audio_volume();

FN_BOOL fone_media_player_get_description(OUT FoneMediaMuxerDesc_t *aMediaMuxerDesc, OUT FoneVideoDesc_t *aVideoDesc, OUT FoneAudioDesc_t *aAudioDesc);

typedef void (* fn_ui_message_receiver_func_t)(int nMessage, void* wParam,void* lParam);

typedef struct __fn_dynamic_reference_table_t__
{
	fn_ui_message_receiver_func_t fn_ui_message_receiver_func;
}fn_dynamic_reference_table_t;

extern FN_VOID fone_media_player_set_dynamic_reference_table(fn_dynamic_reference_table_t tbl);

extern void yuv420_2_rgb565_compatible(uint8_t  *dst_rgb_ptr, const uint8_t  *src_yuv_ptr,
                     int32_t pic_width, int32_t pic_height, int32_t dst_stride);

extern void yuv420_2_rgb888_compatible(uint8_t  *dst_rgb_ptr, const uint8_t  *src_yuv_ptr,
                     int32_t pic_width, int32_t pic_height);


// seek preview, return 1 for success, 0 for failure
int fone_media_player_seek_preview(int thumbWidth, int thumbHeight, FN_BYTE* pBitmapBuffer, int bytesPP);

typedef enum tagFonePlayerPlayRate
{
	FN_PLAYER_LOW = 0,
	FN_PLAYER_NORMAL,
	FN_PLAYER_HIGH,
	FN_PLAYER_EXTREME,
	FN_PLAYER_TWO,
} FonePlayerPlayRate;

FN_BOOL fone_media_player_set_play_rate(FonePlayerPlayRate rate);

//subtitle
typedef enum tagFone_player_lyric_subtitle
{
	FN_PLAYER_LYRIC = 0,         
	FN_PLAYER_EXTERNAL_SUBTITLE,
	FN_PLAYER_BUILT_IN_SUBTITLE,
}Fone_player_lyric_subtitle_e;
typedef struct tagFone_lyric_node
{
	FN_BYTE* str;
	FN_64	 ts;
}FoneLyricNode_t;
typedef struct tagFone_player_lyric
{
	FoneLyricNode_t* node;
	FN_INT	 		 nu;
}FonePlayerLyric_t;

typedef enum {
    FONE_LYRIC_SUBTITLE_CHARSET_NONE = -1,
    FONE_LYRIC_SUBTITLE_CHARSET_GB = 0,
    FONE_LYRIC_SUBTITLE_CHARSET_UTF8 = 1,
	FONE_LYRIC_SUBTITLE_CHARSET_UTF16 = 2,
} FoneLSCharset_t;
FN_BOOL fone_media_player_lyric_subtitle_open(Fone_player_lyric_subtitle_e a_type, const FN_CHAR *file);
FN_VOID fone_media_player_lyric_subtitle_close();
FoneLSCharset_t fone_media_player_get_lyric_subtitle_charset();
FoneLSCharset_t string_char_detect(const char* buf, int len);

/**
type==FN_PLAYER_LYRIC : ts is Invalid
*/
FN_VOID* fone_media_player_get_lyric_subtitle(FN_UINT ts); // in ms

//thumbnail
FN_VOID fone_media_thumbnail_init();
FN_VOID fone_media_thumbnail_uninit();
FN_VOID fone_media_player_thumbnail_stop();
FN_INT fone_media_player_get_thumbnail_from_video
    (IN FN_CONST FN_UTF8* a_pfilename, OUT FN_UTF8* a_pbitmapbuf, IN FN_INT a_width, IN FN_INT a_height, IN FN_INT a_pos, OUT FN_INT* a_isHd, OUT FN_INT* a_Duration, OUT FN_INT bpp);

FN_INT fone_media_player_get_audio_info
    (IN FN_CONST FN_UTF8* a_pfilename, OUT FN_UTF8* a_psinger, IN FN_INT a_singerlen, OUT FN_INT* a_stereo, OUT FN_INT* a_duration);

FN_INT fone_get_audio_info_ext(IN FN_CONST FN_UTF8* a_pfilename, OUT FN_UTF8* a_psinger, int a_singerlen,
                               OUT FN_UTF8* album, int album_buf_len, OUT int* pIsStereo, OUT int* a_pDuration);

// audio channel routines
int fone_get_audio_channel_count();
const char* fone_get_audio_channel_desc(int index);
int fone_get_cur_audio_channel();
void fone_set_cur_audio_channel(int index);

// subtitle channel routines
int fone_get_sub_channel_count();
const char* fone_get_sub_channel_desc(int index);
int fone_get_cur_sub_channel();
void fone_set_cur_sub_channel(int index);
int fone_get_audio_info(const char* filename, char* pArtistName, int buf_len, int* pIsStereo, int* pDuration);

#ifdef __cplusplus
}
#endif

#endif  // _FONE_MEDIA_PLAYER_H_

