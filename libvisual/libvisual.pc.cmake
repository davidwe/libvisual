prefix=@CMAKE_INSTALL_PREFIX@
exec_prefix=@EXEC_PREFIX@
libdir=@LIB_DIR@
includedir=@INCLUDE_DIR@
pluginsbasedir=@LV_PLUGINS_BASE_DIR@

Name: libvisual
Version: @LV_VERSION@
Description: An audio visualization abstraction library.
Requires: @LV_PKG_CONFIG_DEP@
Libs: -L${libdir} @LV_PKG_CONFIG_LIBS@
Cflags: -I${includedir} @LV_PKG_CONFIG_CFLAGS@