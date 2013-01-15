LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := Zadanie1
LOCAL_SRC_FILES := android_main.cpp \
				Vector2.cpp \
				Vector3.cpp \
				Vector4.cpp \
				Matrix3.cpp \
				Matrix4.cpp \
				AndroidDevice.cpp \
				AssetManager.cpp \
				Shader.cpp \
				Zad1Rend.cpp

LOCAL_LDLIBS    := -llog -landroid -lEGL -lGLESv2
LOCAL_WHOLE_STATIC_LIBRARIES := android_native_app_glue

include $(BUILD_SHARED_LIBRARY)

$(call import-module,android/native_app_glue)
