# Source files
set(fcitx_%{APPNAMELC}_sources
  %{APPNAMELC}-config.c
  %{APPNAMELC}.c
  )

# See document in FcitxMacro.cmake and the example .fxaddon file
# doc/fcitx-example.fxaddon in the fcitx repo for more information.
fcitx_add_addon_full(%{APPNAMELC}
  DESC # Use configdesc file
  SCAN # Generate api header
  SCAN_PRIV # Generate addfunction header
  # HEADER_DIR alternative_name # change dir name your header is installed
  # LIB_NAME lib_name # module file name (without extension)
  # HEADERS headers.h # extra public headers to install
  # EXTRA_PO extra_files # extra files to translate
  # LINK_LIBS other-lib # external libraies to link
  SOURCES ${fcitx_%{APPNAMELC}_sources})
