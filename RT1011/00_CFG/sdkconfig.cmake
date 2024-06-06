# config to select component, the format is CONFIG_USE_${component}
set(CONFIG_USE_driver_lpuart_MIMXRT1011 true)

SET(SDK_DIRECTORY_PATH "${PROJECT_DIRECTORY_PATH}/../00_SDK")

set(MCUX_SDK_PROJECT_NAME ${QLCRAFT_PROJECT_OUTPUT_NAME})

set(CMAKE_MODULE_PATH
    ${SDK_DIRECTORY_PATH}/devices/MIMXRT1011/utilities/debug_console_lite
    ${SDK_DIRECTORY_PATH}/devices/MIMXRT1011/drivers
    ${SDK_DIRECTORY_PATH}/devices/MIMXRT1011
    ${SDK_DIRECTORY_PATH}/components/uart
    ${SDK_DIRECTORY_PATH}/components/lists
    ${SDK_DIRECTORY_PATH}/devices/MIMXRT1011/xip
    ${SDK_DIRECTORY_PATH}/devices/xip
    ${SDK_DIRECTORY_PATH}/CMSIS/Core/Include
)

include(utility_debug_console_lite_MIMXRT1011)
include(utility_assert_lite_MIMXRT1011)
include(driver_igpio_MIMXRT1011)
include(driver_clock_MIMXRT1011)
include(driver_common_MIMXRT1011)
include(device_MIMXRT1011_CMSIS_MIMXRT1011)
include(component_lpuart_adapter_MIMXRT1011)
include(component_lists_MIMXRT1011)
include(driver_lpuart_MIMXRT1011)
include(device_MIMXRT1011_startup_MIMXRT1011)
include(driver_iomuxc_MIMXRT1011)
include(driver_xip_device_MIMXRT1011)
include(CMSIS_Include_core_cm_MIMXRT1011)
include(device_MIMXRT1011_system_MIMXRT1011)
