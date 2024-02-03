#include "myTest.h"
#include <ll/api/plugin/NativePlugin.h>
#include <memory>

namespace myTest {

myTest::myTest() = default;

myTest& myTest::getInstance() {
    static myTest instance;
    return instance;
}

ll::plugin::NativePlugin& myTest::getSelf() const { return *mSelf; }

bool myTest::load(ll::plugin::NativePlugin& self) {
    mSelf = std::addressof(self);
    getSelf().getLogger().info("loading...");

    // Code for loading the plugin goes here.

    return true;
}

bool myTest::enable() {
    getSelf().getLogger().info("enabling...");

    auto& logger = mSelf->getLogger();

    return true;
}

bool myTest::disable() {
    getSelf().getLogger().info("disabling...");
    // Code for disabling the plugin goes here.
    return true;
}

extern "C" {
_declspec(dllexport) bool ll_plugin_load(ll::plugin::NativePlugin& self) { return myTest::getInstance().load(self); }

_declspec(dllexport) bool ll_plugin_enable(ll::plugin::NativePlugin&) { return myTest::getInstance().enable(); }

_declspec(dllexport) bool ll_plugin_disable(ll::plugin::NativePlugin&) { return myTest::getInstance().disable(); }

/// @warning Unloading the plugin may cause a crash if the plugin has not released all of its
/// resources. If you are unsure, keep this function commented out.
// _declspec(dllexport) bool ll_plugin_unload(ll::plugin::NativePlugin&) {
//     return myTest::getInstance().unload();
// }
}

} // namespace myTest
