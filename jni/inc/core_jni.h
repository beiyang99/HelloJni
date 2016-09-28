#ifndef __CORE_JNI_H__
#define __CORE_JNI_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "fone_android_log.h"

jboolean Reg_Core(JNIEnv* env, const char* classname);
JNIEXPORT void JNICALL foo(JNIEnv* env,jobject thiz, jint index);

#ifdef __cplusplus
extern "C" {
#endif
#endif

