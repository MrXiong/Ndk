#include <jni.h>
#include <string>
#include "stdlib.h"



//每个native方法都会有一个extern"C"

//Java_com_zx_ndk_MainActivity_stringFromJNI代表：Java包下面的com.zx.ndk.MainActivity的stringFromJNI方法
extern "C"
JNIEXPORT jstring

JNICALL
Java_com_zx_ndk_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


//const相当于java中的final
//方法放在updateNameFromCC方法的上面才可以被调用
jstring getFieldResult(JNIEnv *env, jobject instance,
                       char *fieldName, const char *sig) {

    jclass clz = env->GetObjectClass(instance);
    jfieldID fieldId = env->GetFieldID(clz, fieldName, sig);
    jstring result = (jstring) env->GetObjectField(instance, fieldId);
    return result;
}


jstring getMethodResult(JNIEnv *env, jobject instance,
                        char *methodName, const char *sig) {
    jclass clz = env->GetObjectClass(instance);
    jmethodID methodID = env->GetMethodID(clz, methodName, sig);
    jstring work = (jstring) env->CallObjectMethod(instance, methodID);
    return work;
}
jstring getStaticMethodResult(JNIEnv *env, jobject instance,
                        char *methodName, const char *sig) {
    jclass clz = env->GetObjectClass(instance);
    jmethodID methodID = env->GetStaticMethodID(clz, methodName, sig);
    jstring work = (jstring) env->CallStaticObjectMethod(clz, methodID);
    return work;
}
jint getIntMethodResult(JNIEnv *env, jobject instance,
                        char *methodName, const char *sig) {
    jclass clz = env->GetObjectClass(instance);
    jmethodID methodID = env->GetMethodID(clz, methodName, sig);
    jint age = env->CallIntMethod(instance, methodID);
    return age;
}


//字符串转换
jstring toString(JNIEnv *env, jstring str){
    //如何去转化成Java string
    char *string = (char *) env->GetStringUTFChars(str, NULL);
    //char text[10] = "susssss";
    //把两个字符串组合
    //char *returnValue = strcat(string, text);


    jstring results = env->NewStringUTF(string);
    return results;
}


//代表：Java包下面的com.zx.ndk.MainActivity的updateNameFromCC方法
extern "C"
JNIEXPORT jstring JNICALL
Java_com_zx_ndk_MainActivity_updateField(JNIEnv *env, jobject instance) {
    //jobobject代表的是什么？代表updateNameFromCC方法属于jobject（即MainActivity）
    //直接env.那么就会自动生成->(直接点出来,不用手输箭头)


    //调用Java属性（变量）
    jstring zxName = getFieldResult(env, instance, "zxname", "Ljava/lang/String;");
    return zxName;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_zx_ndk_MainActivity_updateMethodString(JNIEnv *env, jobject instance) {
    //调用方法
    jstring work = getMethodResult(env, instance, "getWork", "()Ljava/lang/String;");
    return work;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_zx_ndk_MainActivity_updateMethodStaticString(JNIEnv *env, jobject instance) {
    //调用静态方法
    jstring works = getStaticMethodResult(env, instance, "getWorks", "()Ljava/lang/String;");
    return works;
}



extern "C"
JNIEXPORT void JNICALL
Java_com_zx_ndk_MainActivity_getLocal(JNIEnv *env, jobject instance) {

   //模拟个循环
    for (int i = 0; i < 100; ++i) {
        jclass jclass1 = env->FindClass("java/util/Date");
        jobject jobject1 = env->NewObject(jclass1, env->GetMethodID(jclass1, "<init>", "()V"));
        //局部变量不会被Gc回收的，所以要delete
        env->DeleteLocalRef(jobject1);
    }

}


extern "C"
JNIEXPORT void JNICALL
Java_com_zx_ndk_MainActivity_exception(JNIEnv *env, jobject instance) {
//构建一个异常处理
    jclass _jclz = env->GetObjectClass(instance);

    int i = 0;
    int j = 20;
    int c = j/i;


}extern "C"
JNIEXPORT jstring JNICALL
Java_com_zx_ndk_MainActivity_cache(JNIEnv *env, jclass type) {

    // TODO


    const char *returnValue = "2";

    return env->NewStringUTF(returnValue);
}