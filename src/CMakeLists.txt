project(DroidSync)

cmake_minimum_required(VERSION 2.8)

find_package(Qt4 REQUIRED)
SET( QT_USE_QTGUI TRUE )

include(${QT_USE_FILE})

include("include.txt")
include("Project.txt" )

SET( QT_USE_QTGUI TRUE )

add_executable(DroidSync WIN32 ${qtproject_SRCS} ${qtproject_UIS_H} ${qtproject_MOC_SRCS} ${qtproject_H} ) 

target_link_libraries( DroidSync 
	${QT_QTMAIN_LIBRARY} ${QT_LIBRARIES} 
	)

