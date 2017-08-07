#!/bin/sh

INSTALL='apt-get install'
CLONE='git clone'
#POKYPATH=poky-morty
#ROOTPATH=./
#RPIPATH=rpi
#BUILDPATH=${RPIPATH}/build
#TOOLCHAINPATH=${ROOTPATH}/tools/toolchain/
#CONFPATH=conf
#SDKPATH=/opt/poky/2.2.2

##################################################
#
#  Help functions
#
##################################################
progress() {
  pid=$!
  sp='>'
  tput setaf $2
  echo ""
  echo $1
  while kill -0 $pid  > /dev/null 2>&1
  do
      printf '%s' "$sp"
      sleep 0.5
  done

}

errorReport() {
  tput setaf 1
  echo ""
  echo "error!: $1"
  echo ""
  tput sgr 0
  exit 1
}

success() {
  tput setaf 2
  echo ""
  echo "done"
  echo ""
  tput sgr 0
}

cleanterminal() {
  tput sgr 0
  echo ""
  echo ""
  echo ""
}

title() {
  tput setaf 3
  echo ------------------------------------------
  echo " $1"
  echo ------------------------------------------
  tput sgr 0
}

info() {
  tput setaf 5
  echo ------------------------------------------
  printf " $1"
  echo ------------------------------------------
  tput sgr 0
}

checkedInfo() {
  tput setaf 2
  echo ""
  echo "$1"
  echo ""
  tput sgr 0
}

head() {
  tput setaf 6
  echo ------------------------------------------
  echo ""
  echo "      "$1""        
  echo ""
  echo ------------------------------------------
  tput sgr 0
}

##################################################
#
#  Main functions
#
##################################################

installPackages(){
  title "Install needed packages"
  sudo $INSTALL cmake 
}


##################################################
#
#  Main routine
#
##################################################
head  "BIKEVIEW - PILOT QT APP"
cleanterminal
if [ ! -d $SDKPATH ]; then
  errorReport "Toolchain not detected please install it by executing install.sh on BSP repository" 
else
  checkedInfo "Toolchain-SDK detected :) "
fi
installPackages && success
#EOF
