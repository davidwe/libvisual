SET(SOURCES
  actor_led.cpp
)

LV_BUILD_ACTOR_PLUGIN(led
  SOURCES      ${SOURCES}
  INCLUDE_DIRS ${OPENGL_INCLUDE_DIR}
  LINK_LIBS    ${OPENGL_gl_LIBRARY} ${OPENGL_glu_LIBRARY} m
)

