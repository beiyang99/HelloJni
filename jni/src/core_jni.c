#define LOG_TAG "JNI"

#include "core_jni.h"

jclass g_core_class;

extern char* jstringTostring(JNIEnv* env, jstring jstr);
extern jstring stoJstring(JNIEnv* env, const char* pat,int nlen);
extern jclass g_class_local_media_click_cell_t;
extern jclass g_fn_full_screen_audio_and_subtitle;
extern jclass g_fn_download_request_list_t;
extern jclass g_fn_full_player_media_info;
extern jclass g_cls_integer_pair;
extern jclass g_cls_fn_myCollect_t;
extern jclass g_cls_notification_100tv_1dot2;
extern jclass g_fn_data_original_web_t;
extern jclass g_online_search_uidata_t;
extern jclass g_java_integer;

extern jclass g_class_airone_server_t;


static JNINativeMethod method[] = {
    	{"foo", "(I)V", (void*)foo}
};



jboolean Reg_Core(JNIEnv* env, const char* classname)
{
    jclass strClass  = (*env)->FindClass(env, classname);
    if (strClass == NULL)
    {
        LOGE("error:Reg_Core, strclass not found");
        return JNI_FALSE;
    }
	g_core_class = (*env)->NewGlobalRef(env,strClass);

	if ((*env)->RegisterNatives(env, g_core_class, method, (sizeof(method)) / sizeof(method[0])) < 0)
	{
		LOGE("error:Reg_Core, register natives failed for class'%s'", (char*)strClass);
		return JNI_FALSE;
	}

    return JNI_TRUE;
}


JNIEXPORT void JNICALL foo(JNIEnv* env,jobject thiz, jint index)
{
	LOGE("index=%d",index);
}

