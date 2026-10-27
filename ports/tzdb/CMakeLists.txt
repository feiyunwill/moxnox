project(tzdb)

set(TZ_VERSION 2026e)
set(TZDIR /share/zoneinfo)
set(TZDEFAULT /etc/localtime)

set(GEN ${CMAKE_CURRENT_BINARY_DIR}/gen)
file(MAKE_DIRECTORY ${GEN})
file(MAKE_DIRECTORY ${GEN}/tools)
file(MAKE_DIRECTORY ${GEN}/zoneinfo)

set(REPO ${CMAKE_CURRENT_SOURCE_DIR}/repo)

file(CONFIGURE OUTPUT ${GEN}/version.h CONTENT [[static char const PKGVERSION[]="(tzcode) ";
static char const TZVERSION[]="@TZ_VERSION@";
static char const REPORT_BUGS_TO[]="tz@iana.org";
]] @ONLY)

file(CONFIGURE OUTPUT ${GEN}/tzdir.h CONTENT [[#ifndef TZDEFAULT
# define TZDEFAULT "@TZDEFAULT@" /* default zone */
#endif
#ifndef TZDIR
# define TZDIR "@TZDIR@" /* TZif directory */
#endif
]] @ONLY)

set(TDATA
    africa
    antarctica
    asia
    australasia
    europe
    northamerica
    southamerica
    etcetera
    factory
    backward
)

set(TDATA_PATHS)
foreach(f ${TDATA})
    list(APPEND TDATA_PATHS repo/${f})
endforeach()

add_custom_command(
    OUTPUT ${GEN}/tools/zic${HOST_EXECUTABLE_SUFFIX}
    COMMAND cc -O2 -I${GEN} -I${REPO} -o ${GEN}/tools/zic${HOST_EXECUTABLE_SUFFIX} ${REPO}/zic.c
    DEPENDS repo/zic.c repo/private.h repo/tzfile.h ${GEN}/version.h ${GEN}/tzdir.h
    VERBATIM
)

list(JOIN TDATA " " TDATA_ARGS)

add_custom_command(
    OUTPUT ${GEN}/main.zi
    COMMAND sh -c "awk -v DATAFORM=main -v PACKRATDATA= -v PACKRATLIST= -f ziguard.awk ${TDATA_ARGS} > '${GEN}/main.zi'"
    DEPENDS repo/ziguard.awk ${TDATA_PATHS}
    WORKING_DIRECTORY ${REPO}
    VERBATIM
)

add_custom_command(
    OUTPUT ${GEN}/tzdata.zi
    COMMAND sh -c "LC_ALL=C awk -v dataform=main -v deps='ziguard.awk ${TDATA_ARGS} zishrink.awk' -v redo=posix_only -v version=${TZ_VERSION} -f zishrink.awk '${GEN}/main.zi' > '${GEN}/tzdata.zi'"
    DEPENDS repo/zishrink.awk ${GEN}/main.zi
    WORKING_DIRECTORY ${REPO}
    VERBATIM
)

add_custom_command(
    OUTPUT ${GEN}/leapseconds
    COMMAND sh -c "awk -v EXPIRES_LINE=0 -f leapseconds.awk leap-seconds.list > '${GEN}/leapseconds'"
    DEPENDS repo/leapseconds.awk repo/leap-seconds.list
    WORKING_DIRECTORY ${REPO}
    VERBATIM
)

add_custom_command(
    OUTPUT ${GEN}/zoneinfo.stamp
    COMMAND ${CMAKE_COMMAND} -E rm -rf ${GEN}/zoneinfo
    COMMAND ${GEN}/tools/zic${HOST_EXECUTABLE_SUFFIX} -b fat -d ${GEN}/zoneinfo ${GEN}/tzdata.zi
    COMMAND ${CMAKE_COMMAND} -E touch ${GEN}/zoneinfo.stamp
    DEPENDS ${GEN}/tools/zic${HOST_EXECUTABLE_SUFFIX} ${GEN}/tzdata.zi
    VERBATIM
)

add_custom_command(
    OUTPUT ${GEN}/tzselect
    COMMAND ${HOST_SED}
            -e "s|#!/bin/bash|#!/bin/sh|"
            -e "s|\\(AWK\\)=[^}]*|\\1='awk'|"
            -e "s|\\(PKGVERSION\\)=.*|\\1='(tzcode) '|"
            -e "s|\\(REPORT_BUGS_TO\\)=.*|\\1='tz@iana.org'|"
            -e "s|\\(TZDIR\\)=[^}]*|\\1='${TZDIR}'|"
            -e "s|\\(TZVERSION\\)=.*|\\1='${TZ_VERSION}'|"
            ${REPO}/tzselect.ksh > ${GEN}/tzselect
    DEPENDS repo/tzselect.ksh
    VERBATIM
)

add_custom_target(tzdb ALL DEPENDS
    ${GEN}/zoneinfo.stamp
    ${GEN}/leapseconds
    ${GEN}/tzselect
)

add_executable(zic repo/zic.c)
add_executable(zdump repo/zdump.c)

foreach(tool zic zdump)
    target_include_directories(${tool} PRIVATE ${GEN} ${REPO})
    target_compile_definitions(${tool} PRIVATE HAVE_GETTEXT=0)
    target_compile_options(${tool} PRIVATE
        ${USERSPACE_CFLAGS}
        -Wno-conversion
        -Wno-sign-conversion
        -Wno-sign-compare
        $<$<C_COMPILER_ID:GNU>:-Wno-maybe-uninitialized>
    )
    target_link_libraries(${tool} PRIVATE moxnox)
endforeach()

target_compile_definitions(zdump PRIVATE HAVE_LOCALTIME_RZ=0 HAVE_STRFTIME_L=0)

install(TARGETS zic zdump DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(PROGRAMS ${GEN}/tzselect DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)

install(DIRECTORY ${GEN}/zoneinfo/ DESTINATION ${CMAKE_INSTALL_PREFIX}${TZDIR})
install(FILES
    repo/iso3166.tab
    repo/leap-seconds.list
    repo/zone.tab
    repo/zone1970.tab
    repo/zonenow.tab
    ${GEN}/leapseconds
    ${GEN}/tzdata.zi
    DESTINATION ${CMAKE_INSTALL_PREFIX}${TZDIR}
)
