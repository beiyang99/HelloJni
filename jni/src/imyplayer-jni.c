#include <jni.h>
#include "malloc.h"
#include "fone_android_log.h"

#define TOTAL_MID_NUM   10

JavaVM *g_JavaVM;

void print_log(){
	LOGV("hello");
}

JNIEnv *Adapter_GetEnv()
{
	int status;
	JNIEnv *env = NULL;
	status = (*g_JavaVM)->GetEnv(g_JavaVM,(void **) &env, JNI_VERSION_1_4);
	if(status < 0)
	{
		/*
		status = (*g_JavaVM)->AttachCurrentThread(g_JavaVM,&env, NULL);
		if(status < 0)
		{
			return NULL;
		}
		LOGW("info:AttachCurrentThread***********************");
		*/
		printf("adapter_getenv() error\n");
	}
	return env;
}

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	LOGV("JNI_Onload()");
	JNIEnv *env = NULL;
	g_JavaVM = vm;

	if ((*vm)->GetEnv(vm,(void**) &env, JNI_VERSION_1_4) != JNI_OK)
	{
		return -1;
	}
	const char* class_core_name = "com/example/hellojni/MainActivity";

	if(!Reg_Core(env, class_core_name))
	{
        LOGE("error reg uim");
        goto ON_LOAD_ERROR;
	}


	LOGV("exit JNI_OnLoad ok 0");
	return JNI_VERSION_1_4;

ON_LOAD_ERROR:
   	(*env)->PopLocalFrame(env,0);
    return -1;
}

void JNI_OnUnload(JavaVM *vm, void *reserved)
{
}

