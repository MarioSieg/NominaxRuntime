ADD_SUBDIRECTORY("SharedTools/fmt/")
TARGET_LINK_LIBRARIES("Nominax" "fmt")
TARGET_LINK_LIBRARIES("NominaxTest" "fmt")

IF (NOT WIN32)
	TARGET_LINK_LIBRARIES("Nominax" "dl")
        TARGET_LINK_LIBRARIES("NominaxTest" "dl")
ENDIF()
