set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

add_library(navx
    AHRS.cpp
    ContinuousAngleTracker.cpp
    InertialDataIntegrator.cpp
    OffsetTracker.cpp
    SerialIO.cpp
    SerialPort.cpp
)
