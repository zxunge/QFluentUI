qt_add_library(FluUtils STATIC
	FluConfigUtils.cpp
	FluConfigUtils.h
	FluEmoijUtils.cpp
	FluEmoijUtils.h
	FluIconUtils.cpp
	FluIconUtils.h
	FluLogUtils.cpp
	FluLogUtils.h
	FluObjectPtrUtils.cpp
	FluObjectPtrUtils.h
	FluStyleSheetUitls.cpp
	FluStyleSheetUitls.h
	FluThemeUtils.cpp
	FluThemeUtils.h
	FluUtils.h
)

target_compile_definitions(FluUtils PRIVATE USE_QRC)
target_link_libraries(FluUtils PUBLIC
    Qt::Widgets
    Qt::Svg
)
