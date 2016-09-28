//
//  fone_platform_player_util.h
//  MediaPlayer
//
//  Created by ZhouLiwei on 12-5-9.
//  Copyright (c) 2012年 100TV. All rights reserved.
//

//初始化播放数据

#ifndef MediaPlayer_fone_platform_player_util_h
#define MediaPlayer_fone_platform_player_util_h
#include "fone_std.h"
#include "fn_data_full_screen_player.h"

#ifdef __cplusplus
extern "C"
{
#endif

    FONE_IMPORT FN_VOID fone_player_get_item_by_local_video_data(FN_INT index, FN_VOID *array, fn_full_screen_player_item *player_item);
    
    FONE_IMPORT FN_VOID fone_player_get_item_by_local_audio_data(FN_INT index, FN_VOID *array, fn_full_screen_player_item *player_item);
    FONE_IMPORT FN_VOID fone_player_update_local_video_data(FN_INT index, FN_VOID *array, int player_time);
    
    FONE_IMPORT FN_VOID fone_player_update_local_audio_data(FN_INT index, FN_VOID *array, int player_time);
    
    FONE_IMPORT FN_VOID fone_player_get_item_by_local_cache_data(FN_INT index, FN_VOID *array, fn_full_screen_player_item *player_item);
    FONE_IMPORT FN_VOID fone_player_update_local_cache_data(FN_INT index, FN_VOID *array, int player_time );
    FONE_IMPORT FN_INT  fone_player_get_play_time_by_url(FN_CHAR *url);
#ifdef __cplusplus
}
#endif
    
#endif
