set(fcitx_example_sources
  example-config.c
  example.c
  )
fcitx_add_addon_full(example DESC SCAN SCAN_PRIV
  SOURCES ${fcitx_example_sources})
