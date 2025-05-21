#!/bin/bash

LINUX_CC="gcc"
WIN64_CC="x86_64-w64-mingw32-gcc"

TEST="test"
SRC="src"
OBJS="obj"
DEBUG="debug"
INCLUDE="include"

SRCS=$(find $SRC -name "*.c")
INCLUDES=$(find $INCLUDE -mindepth 0 -type d | sed "s|^|-I|" | tr '\n' ' ')

CFLAGES="-Wall -Wextra"
LDFLAGES=

LINUX_CFLAGES=" "
WIN64_CFLAGES=" "

LINUX_LDFLAGES=" "
WIN64_LDFLAGES=" "

LINUX_SOURCE="Linux"
LINUX_TEST="TestLinux"

WIN64_SOURCE="Windows"
WIN64_TEST="TestWindows"

LINUX_TESTTARGET="bin/Linux/test/run"
WIN64_TESTTARGET="bin/Win64/test/run"

compile()
{
	local CC=$1
	local Source=$2
	local Entry=$3
	local TESTTARGET=$4
	local cFlages=$5
	local ldFlages=$6

	echo "Start building..."

	mkdir -p $OBJS/$Source
	mkdir -p $OBJS/$Entry
	mkdir -p $(dirname $TESTTARGET)

	echo "Compiling soruce file..."
	for src_file in $SRCS; do
		obj_file="$OBJS/$Source/$(basename ${src_file%.c}.o)"
		echo "compiling $src_file --> $obj_file"
		$CC $CFLAGES $INCLUDES $cFlages -c $src_file -o $obj_file
	done

	echo "Compiling test file..."
	for test_file in $TEST/*.c; do
		test_obj="$OBJS/$Entry/$(basename ${test_file%.c}.o)"
		echo "Compiling $test_file --> $test_obj"
		$CC $CFLAGES $INCLUDES $cFlages -c $test_file -o $test_obj
	done

	echo "Linking object file"
	Index=1
	obj_files=$(ls $OBJS/$Source/*.o)
	for Entry in $OBJS/$Entry/*.o; do
		padded=$(printf "%04d" "$Index")
		echo "Source File:"
		echo "$obj_files"
		echo "Build Target: $TESTTARGET$padded"
		$CC $LDFLAGES $ldFlages -o $TESTTARGET$padded $Entry $obj_files

		Index=$(($Index+1))
	done
}

compileAll()
{
	compile $LINUX_CC $LINUX_SOURCE $LINUX_TEST $LINUX_TESTTARGET
	compile $WIN64_CC $WIN64_SOURCE $WIN64_TEST $WIN64_TESTTARGET
}

buildMain()
{
	local CC=$1
	local Source=$2
	local target=$3
	local ldFlages=$4

	echo "Linking object file"

	objs_files = $(ls $OBJS/$Source/*.o)
	echo "Object file:"
	echo "$objs_files"
	echo "Build target: $taregt"

	$CC $LDFLAGES $ldFlages -o $target $objs_files
}

clean()
{
	echo "Clean up object file and target"
	rm -rf $OBJS/* $(dirname $LINUX_TESTTARGET)/* $(dirname $WIN64_TESTTARGET)/*
}

run_test()
{
	echo "------------------------------"
	echo "Test Linux build"
	for exe in $(dirname $LINUX_TESTTARGET)/*; do
		echo "Test $exe"
		$exe
	done

	echo "------------------------------"
	echo "Test Windows build"
	for exe in $(dirname $WIN64_TESTTARGET)/*; do
		echo "Test $exe"
		wine $exe
	done
}

case $1 in

	"build")
	buildMain
	;;

	"clean")
	clean
	;;

	"test")
	run_test
	;;

	"linux")
	compile $LINUX_CC $LINUX_SOURCE $LINUX_TEST $LINUX_TESTTARGET
	;;

	"win64")
	compile $WIN64_CC $WIN64_SOURCE $WIN64_TEST $WIN64_TESTTARGET
	;;

	*)
	compileAll
	;;
esac
