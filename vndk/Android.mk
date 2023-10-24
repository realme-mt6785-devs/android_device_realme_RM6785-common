ifeq ($(LINEAGE_BUILD),)
include $(CLEAR_VARS)
LOCAL_MODULE := android.hardware.graphics.common-V2-ndk_platform
LOCAL_SHARED_LIBRARIES := android.hardware.graphics.common-V2-ndk
LOCAL_MODULE_CLASS := SHARED_LIBRARIES
LOCAL_MODULE_TAGS := optional
LOCAL_VENDOR_MODULE := true
include $(BUILD_SHARED_LIBRARY)
endif
