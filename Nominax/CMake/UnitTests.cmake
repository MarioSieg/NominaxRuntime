IF (${CORIUM_BUILD_UNIT_TESTS})
	ADD_LIBRARY("NominaxRuntimeTest" STATIC "${NOMINAX_SOURCES}")
	TARGET_COMPILE_DEFINITIONS("NominaxRuntimeTest" PUBLIC "NOX_TEST")
	TARGET_COMPILE_OPTIONS("NominaxRuntimeTest" PRIVATE "-std=c++20")
	OPTION ("CORIUM_DEATH_TESTS" OFF)
	IF ("${CORIUM_DEATH_TESTS}")
		TARGET_COMPILE_DEFINITIONS("NominaxRuntimeTest" PUBLIC "NOX_DEATH_TESTS")
	ENDIF()
	FILE(GLOB_RECURSE "NOMINAX_TEST_SOURCES" "Nominax/Tests/*.cpp")
	ADD_EXECUTABLE("NominaxUnitTest" "${NOMINAX_TEST_SOURCES}")
	ADD_TEST(NAME "NominaxUnitTest" COMMAND "NominaxUnitTests")
	TARGET_INCLUDE_DIRECTORIES("NominaxUnitTest" PUBLIC "${TEST_INCLUDE}")
	TARGET_LINK_LIBRARIES("NominaxUnitTest" "gtest")
	TARGET_LINK_LIBRARIES("NominaxUnitTest" "NominaxRuntimeTest")
	ADD_COMPILE_DEFINITIONS("NOX_TESTING")

	# with GCC we need to link posix threads
	IF (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        TARGET_LINK_LIBRARIES("NominaxUnitTest" "pthread")
    ENDIF()

	CONFIGURE_FILE("Nominax/Tests/MockInput.txt" "${CMAKE_CURRENT_BINARY_DIR}/MockInput.txt" COPYONLY)
ENDIF()