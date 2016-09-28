#ifndef _FONE_ANDROID_LOG_H_
#define _FONE_ANDROID_LOG_H_

#include <jni.h>
#include <android/log.h> 
#include <stdio.h>

#ifndef LOG_TAG  
#define LOG_TAG    "MY_LOG_TAG"  
#endif 

#define FONE_LOG_ON 1

#ifdef FONE_LOG_ON
#define LOGV(...)  __android_log_print(ANDROID_LOG_VERBOSE,LOG_TAG,__VA_ARGS__)    
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)  
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)  
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG,__VA_ARGS__)  
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)  
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG,__VA_ARGS__)
#else
#define LOGV(fmt,args...)  printf(fmt"\n",##args)
#define LOGD(fmt,args...)  printf(fmt"\n",##args)
#define LOGI(fmt,args...)  printf(fmt"\n",##args)
#define LOGW(fmt,args...)  printf(fmt"\n",##args)
#define LOGE(fmt,args...)  printf(fmt"\n",##args)
#define LOGF(fmt,args...)  printf(fmt"\n",##args)

#endif

#endif
