#include "malloc.h"
#include "fn_core.h"
#include "fone_jni.h"
#include "fn_data_download.h"
#include "fn_data_recommend.h"
#include "fn_data_online_search.h"
#include "fn_data_full_screen_player.h"
#include "android_adapter_jni.h"
#include "fn_data_report.h"
#include "fn_data_online_detail.h"
#include "fn_data_user_feedback.h"
#include "fn_data_online.h"
#include "fn_data_original_web.h"
#include "fn_data_online_drama.h"
#include "fn_data_my_fav.h"
#include "fn_data_notification.h"

#define FN_UNCOLICITED 0x3300

typedef void (*pFunc)(fn_page_type_e page_id, fn_page_evt_type_e page_action, void *core_data, void *ui_data);

static pFunc action_handler_callback;

extern JavaVM* g_JavaVM;
extern jclass g_java_string;

jstring stoJstring(JNIEnv* env, const char* pat,int nlen)
{
	jstring encoding = (*env)->NewStringUTF(env, "GBK");

	static jmethodID cid = NULL;
	if(NULL == cid)
	{
		cid = (*env)->GetMethodID(env,g_java_string, "<init>", "([BLjava/lang/String;)V");
		if(NULL == cid)
		{
			(*env)->DeleteLocalRef(env, encoding);
			return NULL;
		}
	}
	jstring jsret = NULL;
	jbyteArray bytes = (*env)->NewByteArray(env,nlen);
	if(NULL != bytes)
	{
		(*env)->SetByteArrayRegion(env,bytes, 0, nlen, (jbyte*)pat);
		jsret = (jstring)(*env)->NewObject(env,g_java_string, cid, bytes, encoding);
	}
	else
	{
		jsret = NULL;
	}
	(*env)->DeleteLocalRef(env, bytes);
	(*env)->DeleteLocalRef(env, encoding);
	return jsret;
}

char* jstringToChar(JNIEnv* env, jstring jstr)
{
	return (char*)(*env)->GetStringUTFChars(env,jstr,NULL);
}

char* jstringTostring(JNIEnv* env, jstring jstr)
{
	char* rtn = NULL;
	static jmethodID mid = NULL;

	jstring strencode = (*env)->NewStringUTF(env,"utf-8");

	if(NULL == mid)
	{
		jclass j_string = (*env)->FindClass(env, "java/lang/String");
		if(NULL == j_string)
		{
			LOGE("cannot find class java/lang/String");
			return NULL;
		}
		mid = (*env)->GetMethodID(env, j_string, "getBytes",	"(Ljava/lang/String;)[B");
		if(mid == NULL)return NULL;
	}

	jbyteArray barr= (jbyteArray)(*env)->CallObjectMethod(env,jstr, mid, strencode);
    (*env)->DeleteLocalRef(env, strencode);

	jsize alen = (*env)->GetArrayLength(env,barr);
	jbyte* ba = (*env)->GetByteArrayElements(env,barr, JNI_FALSE);
	if (alen > 0)
	{
		rtn = (char*)malloc(alen + 1);
        if (!rtn)
            return rtn;

		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	(*env)->ReleaseByteArrayElements(env,barr,ba,0);
    (*env)->DeleteLocalRef(env, barr);
	return rtn;
}



void fn_setting_set_value(int type, int value)
{

}

int fn_stack_page_get_top_page_id()
{
	return 1;
}

void reg_jvm(JavaVM* jvm)
{
	g_JavaVM = jvm;
}
