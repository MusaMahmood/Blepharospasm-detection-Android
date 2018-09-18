//
// Created by mahmoodms on 4/3/2017.
//

#include "rt_nonfinite.h"
#include "ssvep_filter_f32.h"
#include "downsample_250Hz.h"
#include "ecg_bandstop_250Hz.h"
#include "ecg_filt_rescale.h"
#include "get_class_bleph.h"
#include "rearrange_4c.h"
#include "get_p2p.h"
#include "count_blinks.h"
#include "get_intensity.h"
#include "bleph_analyze_data.h"

/*Additional Includes*/
#include <jni.h>
#include <android/log.h>

#define  LOG_TAG "jniExecutor-cpp"
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" {
JNIEXPORT jdoubleArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jblephAnalyze(
        JNIEnv *env, jobject jobject1, jfloatArray data) {
    jfloat *X = env->GetFloatArrayElements(data, NULL);
    double Y[7];
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jdoubleArray m_result = env->NewDoubleArray(7);
    bleph_analyze_data(X, &Y[0], &Y[3]);
    env->SetDoubleArrayRegion(m_result, 0, 7, Y);
    return m_result;
}
}

extern "C" {
JNIEXPORT jfloatArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jecgFiltRescale(
        JNIEnv *env, jobject jobject1, jdoubleArray data) {
    jdouble *X = env->GetDoubleArrayElements(data, NULL);
    float Y[2000];
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jfloatArray m_result = env->NewFloatArray(2000);
    ecg_filt_rescale(X, Y);
    env->SetFloatArrayRegion(m_result, 0, 2000, Y);
    return m_result;
}
}

extern "C" {
JNIEXPORT jdouble JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jgetWaveletEnergy(
        JNIEnv *env, jobject jobject1, jfloatArray data) {
    jfloat *X = env->GetFloatArrayElements(data, NULL);
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    return get_intensity(X);
}
}

extern "C" {
JNIEXPORT jdouble JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jgetNumberBlinks(
        JNIEnv *env, jobject jobject1, jfloatArray data) {
    jfloat *X = env->GetFloatArrayElements(data, NULL);
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    return count_blinks(X);
}
}

extern "C" {
JNIEXPORT jdouble JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jgetp2p(
        JNIEnv *env, jobject jobject1, jdoubleArray data) {
    jdouble *X = env->GetDoubleArrayElements(data, NULL);
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    return get_p2p(X);
}
}

extern "C" {
JNIEXPORT jfloatArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jrearrange3c(
        JNIEnv *env, jobject jobject1, jfloatArray data) {
    jfloat *X = env->GetFloatArrayElements(data, NULL);
    float Y[6000];
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jfloatArray m_result = env->NewFloatArray(6000);
    rearrange_3c(X, Y);
    env->SetFloatArrayRegion(m_result, 0, 6000, Y);
    return m_result;
}
}

extern "C" {
JNIEXPORT jfloatArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jrearrange4c(
        JNIEnv *env, jobject jobject1, jfloatArray data) {
    jfloat *X = env->GetFloatArrayElements(data, NULL);
    float Y[8000];
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jfloatArray m_result = env->NewFloatArray(8000);
    rearrange_4c(X, Y);
    env->SetFloatArrayRegion(m_result, 0, 8000, Y);
    return m_result;
}
}

extern "C" {
JNIEXPORT jfloatArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jgetClassBleph3c(
        JNIEnv *env, jobject jobject1, jfloatArray data) {
    jfloat *X = env->GetFloatArrayElements(data, NULL);
    double y = 0;
    float Y[4];
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jfloatArray m_result = env->NewFloatArray(4);
    get_class_bleph_3c(X, &y, Y);
    Y[3] = (float) y;
    env->SetFloatArrayRegion(m_result, 0, 4, Y);
    return m_result;
}
}

extern "C" {
JNIEXPORT jfloatArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jgetClassBleph(
        JNIEnv *env, jobject jobject1, jfloatArray data) {
    jfloat *X = env->GetFloatArrayElements(data, NULL);
    double y = 0;
    float Y[5];
    if (X == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jfloatArray m_result = env->NewFloatArray(5);
    get_class_bleph(X, &y, Y);
    Y[4] = (float) y;
    env->SetFloatArrayRegion(m_result, 0, 5, Y);
    return m_result;
}
}

extern "C" {
JNIEXPORT jdoubleArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jecgBandStopFilter(
        JNIEnv *env, jobject jobject1, jdoubleArray data) {
    jdouble *X1 = env->GetDoubleArrayElements(data, NULL);
    double Y[1000]; // First two values = Y; last 499 = cPSD
    if (X1 == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jdoubleArray m_result = env->NewDoubleArray(1000);
    ecg_bandstop_250Hz(X1, Y);
    env->SetDoubleArrayRegion(m_result, 0, 1000, Y);
    return m_result;
}
}


extern "C" {
JNIEXPORT jdoubleArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jdownSample(
        JNIEnv *env, jobject jobject1, jdoubleArray data, jint Fs) {
    jdouble *X1 = env->GetDoubleArrayElements(data, NULL);
    int Xsize[1] = {Fs*4};
    double Y[1000]; // First two values = Y; last 499 = cPSD
    int Ysize[2]; // First two values = Y; last 499 = cPSD
    if (X1 == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jdoubleArray m_result = env->NewDoubleArray(1000);
    downsample_250Hz(X1, Xsize, Fs, &Y[0], Ysize);
    env->SetDoubleArrayRegion(m_result, 0, 1000, Y);
    return m_result;
}
}


extern "C" {
JNIEXPORT jfloatArray JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jSSVEPCfilter(
        JNIEnv *env, jobject jobject1, jdoubleArray data) {
    jdouble *X1 = env->GetDoubleArrayElements(data, NULL);
    float Y[1000]; // First two values = Y; last 499 = cPSD
    if (X1 == NULL) LOGE("ERROR - C_ARRAY IS NULL");
    jfloatArray m_result = env->NewFloatArray(1000);
    ssvep_filter_f32(X1, Y);
    env->SetFloatArrayRegion(m_result, 0, 1000, Y);
    return m_result;
}
}

extern "C" {
JNIEXPORT jdoubleArray JNICALL
/**
 *
 * @param env
 * @param jobject1
 * @return array of frequencies (Hz) corresponding to a raw input signal.
 */
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jLoadfPSD(
        JNIEnv *env, jobject jobject1, jint sampleRate) {
    jdoubleArray m_result = env->NewDoubleArray(sampleRate);
    double fPSD[sampleRate];
    for (int i = 0; i < sampleRate; i++) {
        fPSD[i] = (double) i * (double) sampleRate / (double) (sampleRate * 2);
    }
    env->SetDoubleArrayRegion(m_result, 0, sampleRate, fPSD);
    return m_result;
}
}

extern "C" {
JNIEXPORT jint JNICALL
Java_com_yeolabgt_mahmoodms_blepharospasmdemo_DeviceControlActivity_jmainInitialization(
        JNIEnv *env, jobject obj, jboolean initialize) {
    if (!(bool) initialize) {
        downsample_250Hz_initialize();
        ecg_bandstop_250Hz_initialize();
        return 0;
    } else {
        return -1;
    }
}
}
