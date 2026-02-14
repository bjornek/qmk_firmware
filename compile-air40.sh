#!/bin/bash

rm ./.build/ymdk_ymd40_air40_eklofbjorn_air40.hex
rm ./ymdk_ymd40_air40_eklofbjorn_air40.hex
rm -r ./.build/*ymdk_ymd40_air40*

qmk $1 -kb ymdk/ymd40/air40 -km eklofbjorn_air40
