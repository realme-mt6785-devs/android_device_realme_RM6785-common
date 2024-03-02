/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <condition_variable>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

namespace aidl {
namespace google {
namespace hardware {
namespace power {
namespace impl {
namespace pixel {

enum InteractionState {
    INTERACTION_STATE_UNINITIALIZED,
    INTERACTION_STATE_IDLE,
    INTERACTION_STATE_INTERACTION,
    INTERACTION_STATE_WAITING,
};

class InteractionHandler {
  public:
    InteractionHandler();
    ~InteractionHandler();
    bool Init();
    void Exit();
    void Acquire(int32_t duration);

  private:
    void Release();
    void WaitForIdle(int32_t wait_ms, int32_t timeout_ms);
    void AbortWaitLocked();
    void Routine();

    void PerfLock();
    void PerfRel();

    enum InteractionState mState;
    int mIdleFd;
    int mEventFd;
    int32_t mDurationMs;
    struct timespec mLastTimespec;
    std::unique_ptr<std::thread> mThread;
    std::mutex mLock;
    std::condition_variable mCond;
};

}  // namespace pixel
}  // namespace impl
}  // namespace power
}  // namespace hardware
}  // namespace google
}  // namespace aidl
