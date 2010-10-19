
SET(ANNOYME_PROJECT_NAME ${PROJECT_NAME})
SET(ANNOYME_INSTALL_PATH ${CMAKE_INSTALL_PREFIX})
SET(ANNOYME_SHARED_DIRECTORY share/${PROJECT_NAME})
SET(ANNOYME_SHARED_PATH ${CMAKE_INSTALL_PREFIX}/${ANNOYME_SHARED_DIR})
SET(ANNOYME_DEFAULT_CONFIG_NAME default_config.yaml)
SET(ANNOYME_RESOURCE_DIRECTORY resources)
SET(ANNOYME_SAMPLE_DIRECTORY samples)
SET(ANNOYME_CONFIG_NAME .annoyme)

CONFIGURE_FILE(${PROJECT_SOURCE_DIR}/src/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}/include/)

