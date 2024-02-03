#pragma once

#include <ll/api/plugin/NativePlugin.h>

namespace myTest {

class myTest {
    myTest();

public:
    myTest(myTest&&)                 = delete;
    myTest(const myTest&)            = delete;
    myTest& operator=(myTest&&)      = delete;
    myTest& operator=(const myTest&) = delete;

    static myTest& getInstance();

    [[nodiscard]] ll::plugin::NativePlugin& getSelf() const;

    /// @return True if the plugin is loaded successfully.
    bool load(ll::plugin::NativePlugin&);

    /// @return True if the plugin is enabled successfully.
    bool enable();

    /// @return True if the plugin is disabled successfully.
    bool disable();

private:
    ll::plugin::NativePlugin* mSelf{};
};

} // namespace myTest
 