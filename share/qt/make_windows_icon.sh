#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/richcoin.png
ICON_DST=../../src/qt/res/icons/richcoin.ico
convert ${ICON_SRC} -resize 16x16 richcoin-16.png
convert ${ICON_SRC} -resize 32x32 richcoin-32.png
convert ${ICON_SRC} -resize 48x48 richcoin-48.png
convert richcoin-16.png richcoin-32.png richcoin-48.png ${ICON_DST}

