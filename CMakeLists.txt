project(LaboratoryLib)

set(SOURCE_FILES
        pch.h
        Laboratory.h Laboratory.cpp LaboratoryFactory.cpp LaboratoryFactory.h LaboratoryStandin.cpp LaboratoryStandin.h
        Polygon.cpp Polygon.h
        LaboratoryDialog.cpp LaboratoryDialog.h include/laboratory-api.h GraphicsHelper.cpp GraphicsHelper.h Sparky.cpp Sparky.h LaboratoryDerived.cpp LaboratoryDerived.h LaboratoryFactory1.cpp LaboratoryFactory1.h
        LaboratoryFactory2.cpp LaboratoryFactory2.h ActualLaboratory.cpp ActualLaboratory.h Component.cpp Component.h Gear.cpp Gear.h INegotiator.cpp INegotiator.h Lever.cpp Lever.h Motor.cpp Motor.h PositionSink.cpp PositionSink.h PositionSource.cpp PositionSource.h Rod.cpp Rod.h RodSink.cpp RodSink.h RodSource.cpp RodSource.h RotationSink.cpp RotationSource.cpp Shape.cpp Shape.h Arm.cpp Arm.h
        )

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)