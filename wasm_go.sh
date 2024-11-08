#!/bin/bash

# Copyright (c) 2019 Michael Neill Hartman. All rights reserved.
# mnh_license@proton.me
# https://github.com/hartmanm

# wasm_go
#
# bash wasm_go <target file> <second parameter to install else install will be skipped>
#
# example: bash wasm_go hello.c
#
# install example: bash wasm_go hello.c install
#
# so long as target file is unique and located in a subdirectory below wasm_go, it will be found.
#
# wasm_go is an emscripten wrapper with mods to make it easier to use with WASM!
# Easily compile and launch a c or cpp program for WASM and launch it in the browser.
# Note: input is not handled correctly, along with many other potential problems.
# OPTIMIZATION_LEVEL is hardcoded in the script to the lowest level, change it to 3 for the highest optimization.
# The html interface has been cleaned up and many of the annoying potential issues are avoided by automation.
# Minor modifications to files to do things like: make chrome the default browser (it can utilize your GPU with WASM).
#
# a hello WASM example c program (hello.c) and simple example cpp program (out.cpp) are included for testing:
#
# after running with install then:
# bash wasm_go hello.c
# bash wasm_go out.cpp
#
# TODO: 
# add button to output source text in ms.html
# automate installation of required; at least for linux
#

echo "
now deprecated
"
exec true

# 3 is highest, 0 is lowest
# change here:
OPTIMIZATION_LEVEL=0
#
LAUNCH_DIRECTORY=$(pwd)
# redirecting to script directory
DIRECTORY_LENGTH=$(echo ${0} | wc -c)
if [[ ${DIRECTORY_LENGTH} -gt 8 ]]
then 
LAUNCH_PATH=$(echo ${0} | tr '/' ' ' | awk '{$NF=""; print $0}' | tr ' ' '/' )
LAUNCH_PATH=${LAUNCH_PATH%?}
LAUNCH_PATH="/${LAUNCH_PATH}"
cd ${LAUNCH_PATH}
LAUNCH_DIRECTORY=${LAUNCH_PATH}
fi ##  if [[ ${DIRECTORY_LENGTH} -gt 8 ]]
INITIALIZE=${2}
LOCAL_OS=$(uname | tr '[:upper:]' '[:lower:]')
if [[ ${LOCAL_OS} != "linux" && ${LOCAL_OS} != "darwin" ]]
then
echo "Your OS is not supported by this script!"
exec true
fi ##  if [[ ${LOCAL_OS} != "linux" && ${LOCAL_OS} != "darwin" ]]
if [[ ${LOCAL_OS} == "darwin" ]]
then
echo "
note the following are required for macOS:
python
git
gcc
g++
cmake
"
IS_PYTHON=$(which python)
if [[ ${IS_PYTHON} == "" ]]
then
echo "you need to install python"
exec true
fi ##  if [[ ${IS_PYTHON} == "" ]]
IS_GIT=$(which git)
if [[ ${IS_GIT} == "" ]]
then
echo "you need to install git"
exec true
fi ##  if [[ ${IS_GIT} == "" ]]
IS_GCC=$(which gcc)
if [[ ${IS_GCC} == "" ]]
then
echo "you need to install gcc"
exec true
fi ##  if [[ ${IS_GCC} == "" ]]
IS_GPP=$(which g++)
if [[ ${IS_GPP} == "" ]]
then
echo "you need to install g++"
exec true
fi ##  if [[ ${IS_GPP} == "" ]]
echo "install cmake from apple App Store"
fi ##  if [[ ${LOCAL_OS} == "darwin" ]]
#
if [[ ${LOCAL_OS} == "linux" ]]
then
echo "
note the following are required for linux:
python
git
gcc
g++
cmake
note: this script is only setup for the yum package manager
"
IS_PYTHON=$(which python)
if [[ ${IS_PYTHON} == "" ]]
then
echo "you need to install python"
sudo yum install python -y
fi ##  if [[ ${IS_PYTHON} == "" ]]
IS_GIT=$(which git)
if [[ ${IS_GIT} == "" ]]
then
echo "you need to install git"
sudo yum install git -y
fi ##  if [[ ${IS_GIT} == "" ]]
IS_GCC=$(which gcc)
if [[ ${IS_GCC} == "" ]]
then
echo "you need to install gcc"
sudo yum install gcc -y
fi ##  if [[ ${IS_GCC} == "" ]]
IS_GPP=$(which g++)
if [[ ${IS_GPP} == "" ]]
then
echo "you need to install g++"
sudo yum install g++ -y
fi ##  if [[ ${IS_GPP} == "" ]]
echo "you need to install cmake"
sudo yum install cmake -y
fi ##  if [[ ${LOCAL_OS} == "linux" ]]
#
# check for leftover EMSCRIPTEN processes
IS_EM=$(ps -ef | grep -v grep | grep "emrun")
if [[ ${IS_EM} != "" ]]
then
pkill -f emrun
fi ##  if [[ ${IS_EM} != "" ]]
#
[[ -d emsdk ]] || echo "no emsdk directory cloning repo"
[[ -d emsdk ]] || git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
git pull
if [[ ${INITIALIZE} != "" ]]
then
python emsdk.py install latest 2>/dev/null
python emsdk.py activate latest 2>/dev/null
fi ##  if [[ ${INITIALIZE} != "" ]]
source ./emsdk_env.sh 2>/dev/null
SOURCE_FILE=${1}
TOKEN=""
cd ..
[[ ! -e ${SOURCE_FILE} ]] || echo "removing ${SOURCE_FILE}"
[[ ! -e ${SOURCE_FILE} ]] || rm ${SOURCE_FILE}
FEEDBACK=0
while [[ ${TOKEN} != ${SOURCE_FILE} ]]
do
TOKEN=$(find . -name ${SOURCE_FILE} | tr '/' ' ' | awk '{print $NF}')
WC1=$(echo ${SOURCE_FILE} | wc -c)
WC2=$(echo ${TOKEN} | wc -c)
FEEDBACK=$((${FEEDBACK}+1))
[[ ${FEEDBACK} -lt 100 ]] || echo "Error: target file: ${SOURCE_FILE} not found!"
[[ ${FEEDBACK} -lt 100 ]] || sleep 5
done
TOKEN=$(find . -name "${SOURCE_FILE}")
SOURCE_FILE_DIRECTORY=$(pwd)
TOKEN=${TOKEN:1}
TARGET_DIRECTORY=$(echo "${LAUNCH_DIRECTORY}/${TOKEN}" | tr '/' ' ' | awk '{$NF=""; print $0}' | tr ' ' '/')
TARGET_DIRECTORY=${TARGET_DIRECTORY%?}
TARGET_DIRECTORY="/${TARGET_DIRECTORY}"
cd "${TARGET_DIRECTORY}"
echo "
compiling target: emcc ${SOURCE_FILE} -s WASM=1 -O${OPTIMIZATION_LEVEL} -o ms.html
"
emcc "${SOURCE_FILE}" -s WASM=1 -O${OPTIMIZATION_LEVEL} -o ms.html 2>/dev/null
cd ${LAUNCH_DIRECTORY}
cd src
cp ms.html "${TARGET_DIRECTORY}/ms.html"
cp bootstrap_4_3_1.css "${TARGET_DIRECTORY}/bootstrap_4_3_1.css"
cd ${LAUNCH_DIRECTORY}
echo "
running target: ${TARGET_DIRECTORY}/ms.html
"
python emrun.py "${TARGET_DIRECTORY}/ms.html" &
sleep 5
pkill -f emrun
exec true
