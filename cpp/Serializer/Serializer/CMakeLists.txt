set(LIBRARY_NAME MGSerializer)

set(MODEL_FILES
        Models/InterpolatedC2.h
        Models/PointRef.cpp
        Models/PointRef.h
        Models/SceneObject.h
        Models/SceneObject.cpp
        Models/BezierC2.cpp
        Models/Point.cpp
        Models/Torus.h
        Models/Point.h
        Models/Bezier.h
        Models/BezierC0.cpp
        Models/BezierC0.h
        Models/InterpolatedC2.cpp
        Models/Torus.cpp
        Models/BezierC2.h
)

set(SCENE_FILES
        Scene/SceneSerializer.h
        Scene/Scene.h
        Scene/SceneSerializer.cpp
)

set(UTILS_FILES
        Utils/Uint2.cpp
        Utils/Float3.h
        Utils/Uint2.h
        Utils/Float3.cpp
)

set(RESOURCES_FILES
        Resources/Schema.h
)

set(LIBRARY_FILES
    ${MODEL_FILES}
    ${SCENE_FILES}
    ${UTILS_FILES}
    ${RESOURCES_FILES}
    pch.cpp
    pch.h
    Serializable.h
    Serializer.h
)
add_library(${LIBRARY_NAME} STATIC ${LIBRARY_FILES} )

# To jedyne co przyszło mi do głowy aby kopiowac wszystkie headery do build dira
# Jak ktos będzie miec lepszy pomysł jak poprawic zależności pomiędzy Sandboxem a Serializerem to prosze bardzo
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}
        DESTINATION ${PROJECT_BINARY_DIR}/include
        FILES_MATCHING
        PATTERN *.h
        )
